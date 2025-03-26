#include "version.h"
#include "board.h"
#include "settings.h"

#include <cJSON.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>

#define TAG "Version"


Version::Version() {
}

Version::~Version() {
}

void Version::SetCheckVersionUrl(std::string check_version_url) {
    check_version_url_ = check_version_url;
}

void Version::SetHeader(const std::string& key, const std::string& value) {
    headers_[key] = value;
}

void Version::SetPostData(const std::string& post_data) {
    post_data_ = post_data;
}

bool Version::CheckVersion() {
    if (check_version_url_.length() < 10) {
        ESP_LOGE(TAG, "Check version URL is not properly set");
        return false;
    }

    auto http = Board::GetInstance().CreateHttp();
    for (const auto& header : headers_) {
        http->SetHeader(header.first, header.second);
    }

    http->SetHeader("Content-Type", "application/json");
    std::string method = post_data_.length() > 0 ? "POST" : "GET";
    if (!http->Open(method, check_version_url_, post_data_)) {
        ESP_LOGE(TAG, "Failed to open HTTP connection");
        delete http;
        return false;
    }

    auto response = http->GetBody();
    http->Close();
    delete http;

    // Response: { "firmware": { "version": "1.0.0", "url": "http://" } }
    // Parse the JSON response and check if the version is newer
    // If it is, set has_new_version_ to true and store the new version and URL
    
    cJSON *root = cJSON_Parse(response.c_str());
    if (root == NULL) {
        ESP_LOGE(TAG, "Failed to parse JSON response");
        return false;
    }

    has_activation_code_ = false;
    cJSON *activation = cJSON_GetObjectItem(root, "activation");
    if (activation != NULL) {
        cJSON* message = cJSON_GetObjectItem(activation, "message");
        if (message != NULL) {
            activation_message_ = message->valuestring;
        }
        cJSON* code = cJSON_GetObjectItem(activation, "code");
        if (code != NULL) {
            activation_code_ = code->valuestring;
        }
        has_activation_code_ = true;
    }

    has_mqtt_config_ = false;
    cJSON *mqtt = cJSON_GetObjectItem(root, "mqtt");
    if (mqtt != NULL) {
        Settings settings("mqtt", true);
        cJSON *item = NULL;
        cJSON_ArrayForEach(item, mqtt) {
            if (item->type == cJSON_String) {
                if (settings.GetString(item->string) != item->valuestring) {
                    settings.SetString(item->string, item->valuestring);
                }
            }
        }
        has_mqtt_config_ = true;
    }

    has_server_time_ = false;
    cJSON *server_time = cJSON_GetObjectItem(root, "server_time");
    if (server_time != NULL) {
        cJSON *timestamp = cJSON_GetObjectItem(server_time, "timestamp");
        cJSON *timezone_offset = cJSON_GetObjectItem(server_time, "timezone_offset");
        
        if (timestamp != NULL) {
            // 设置系统时间
            struct timeval tv;
            double ts = timestamp->valuedouble;
            
            // 如果有时区偏移，计算本地时间
            if (timezone_offset != NULL) {
                ts += (timezone_offset->valueint * 60 * 1000); // 转换分钟为毫秒
            }
            
            tv.tv_sec = (time_t)(ts / 1000);  // 转换毫秒为秒
            tv.tv_usec = (suseconds_t)((long long)ts % 1000) * 1000;  // 剩余的毫秒转换为微秒
            settimeofday(&tv, NULL);
            has_server_time_ = true;
        }
    }

    cJSON *firmware = cJSON_GetObjectItem(root, "firmware");
    if (firmware == NULL) {
        ESP_LOGE(TAG, "Failed to get firmware object");
        cJSON_Delete(root);
        return false;
    }
    cJSON *version = cJSON_GetObjectItem(firmware, "version");
    if (version == NULL) {
        ESP_LOGE(TAG, "Failed to get version object");
        cJSON_Delete(root);
        return false;
    }
    cJSON *url = cJSON_GetObjectItem(firmware, "url");
    if (url == NULL) {
        ESP_LOGE(TAG, "Failed to get url object");
        cJSON_Delete(root);
        return false;
    }

    cJSON_Delete(root);
    return true;
}
