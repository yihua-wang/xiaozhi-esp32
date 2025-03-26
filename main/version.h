#ifndef _VERSION_H
#define _VERSION_H

#include <functional>
#include <string>
#include <map>

class Version {
public:
    Version();
    ~Version();

    void SetCheckVersionUrl(std::string check_version_url);
    void SetHeader(const std::string& key, const std::string& value);
    void SetPostData(const std::string& post_data);
    bool CheckVersion();
    bool HasMqttConfig() { return has_mqtt_config_; }
    bool HasActivationCode() { return has_activation_code_; }
    bool HasServerTime() { return has_server_time_; }

    const std::string& GetActivationMessage() const { return activation_message_; }
    const std::string& GetActivationCode() const { return activation_code_; }

private:
    std::string check_version_url_;
    std::string activation_message_;
    std::string activation_code_;
    bool has_mqtt_config_ = false;
    bool has_server_time_ = false;
    bool has_activation_code_ = false;
    std::string post_data_;
    std::map<std::string, std::string> headers_;
};

#endif // _VERSION_H
