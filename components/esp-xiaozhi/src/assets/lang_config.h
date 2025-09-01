// Auto-generated language config
// Language: zh-CN with en-US fallback
#pragma once

#include <string_view>

#ifndef zh_cn
    #define zh_cn  // 預設語言
#endif

namespace Lang {
    // 语言元数据
    constexpr const char* CODE = "zh-CN";

    // 字符串资源 (en-US as fallback for missing keys)
    namespace Strings {
        constexpr const char* ACCESS_VIA_BROWSER = "，浏览器访问 ";
        constexpr const char* ACTIVATION = "激活设备";
        constexpr const char* BATTERY_CHARGING = "正在充电";
        constexpr const char* BATTERY_FULL = "电量已满";
        constexpr const char* BATTERY_LOW = "电量不足";
        constexpr const char* BATTERY_NEED_CHARGE = "电量低，请充电";
        constexpr const char* CHECKING_NEW_VERSION = "检查新版本...";
        constexpr const char* CHECK_NEW_VERSION_FAILED = "检查新版本失败，将在 %d 秒后重试：%s";
        constexpr const char* CONNECTED_TO = "已连接 ";
        constexpr const char* CONNECTING = "连接中...";
        constexpr const char* CONNECTION_SUCCESSFUL = "Connection Successful";
        constexpr const char* CONNECT_TO = "连接 ";
        constexpr const char* CONNECT_TO_HOTSPOT = "手机连接热点 ";
        constexpr const char* DETECTING_MODULE = "检测模组...";
        constexpr const char* ENTERING_WIFI_CONFIG_MODE = "进入配网模式...";
        constexpr const char* ERROR = "错误";
        constexpr const char* INFO = "信息";
        constexpr const char* INITIALIZING = "正在初始化...";
        constexpr const char* LISTENING = "聆听中...";
        constexpr const char* LOADING_PROTOCOL = "登录服务器...";
        constexpr const char* MAX_VOLUME = "最大音量";
        constexpr const char* MUTED = "已静音";
        constexpr const char* NEW_VERSION = "新版本 ";
        constexpr const char* OTA_UPGRADE = "OTA 升级";
        constexpr const char* PIN_ERROR = "请插入 SIM 卡";
        constexpr const char* REGISTERING_NETWORK = "等待网络...";
        constexpr const char* REG_ERROR = "无法接入网络，请检查流量卡状态";
        constexpr const char* RTC_MODE_OFF = "AEC 关闭";
        constexpr const char* RTC_MODE_ON = "AEC 开启";
        constexpr const char* SCANNING_WIFI = "扫描 Wi-Fi...";
        constexpr const char* SERVER_ERROR = "发送失败，请检查网络";
        constexpr const char* SERVER_NOT_CONNECTED = "无法连接服务，请稍后再试";
        constexpr const char* SERVER_NOT_FOUND = "正在寻找可用服务";
        constexpr const char* SERVER_TIMEOUT = "等待响应超时";
        constexpr const char* SPEAKING = "说话中...";
        constexpr const char* STANDBY = "待命";
        constexpr const char* SWITCH_TO_4G_NETWORK = "切换到 4G...";
        constexpr const char* SWITCH_TO_WIFI_NETWORK = "切换到 Wi-Fi...";
        constexpr const char* UPGRADE_FAILED = "升级失败";
        constexpr const char* UPGRADING = "正在升级系统...";
        constexpr const char* VERSION = "版本 ";
        constexpr const char* VOLUME = "音量 ";
        constexpr const char* WARNING = "警告";
        constexpr const char* WIFI_CONFIG_MODE = "配网模式";
    }

    // 音效资源 (en-US as fallback for missing audio files)
    namespace Sounds {

        extern const char ogg_0_start[] asm("_binary_0_ogg_start");
        extern const char ogg_0_end[] asm("_binary_0_ogg_end");
        static const std::string_view OGG_0 {
        static_cast<const char*>(ogg_0_start),
        static_cast<size_t>(ogg_0_end - ogg_0_start)
        };

        extern const char ogg_1_start[] asm("_binary_1_ogg_start");
        extern const char ogg_1_end[] asm("_binary_1_ogg_end");
        static const std::string_view OGG_1 {
        static_cast<const char*>(ogg_1_start),
        static_cast<size_t>(ogg_1_end - ogg_1_start)
        };

        extern const char ogg_2_start[] asm("_binary_2_ogg_start");
        extern const char ogg_2_end[] asm("_binary_2_ogg_end");
        static const std::string_view OGG_2 {
        static_cast<const char*>(ogg_2_start),
        static_cast<size_t>(ogg_2_end - ogg_2_start)
        };

        extern const char ogg_3_start[] asm("_binary_3_ogg_start");
        extern const char ogg_3_end[] asm("_binary_3_ogg_end");
        static const std::string_view OGG_3 {
        static_cast<const char*>(ogg_3_start),
        static_cast<size_t>(ogg_3_end - ogg_3_start)
        };

        extern const char ogg_4_start[] asm("_binary_4_ogg_start");
        extern const char ogg_4_end[] asm("_binary_4_ogg_end");
        static const std::string_view OGG_4 {
        static_cast<const char*>(ogg_4_start),
        static_cast<size_t>(ogg_4_end - ogg_4_start)
        };

        extern const char ogg_5_start[] asm("_binary_5_ogg_start");
        extern const char ogg_5_end[] asm("_binary_5_ogg_end");
        static const std::string_view OGG_5 {
        static_cast<const char*>(ogg_5_start),
        static_cast<size_t>(ogg_5_end - ogg_5_start)
        };

        extern const char ogg_6_start[] asm("_binary_6_ogg_start");
        extern const char ogg_6_end[] asm("_binary_6_ogg_end");
        static const std::string_view OGG_6 {
        static_cast<const char*>(ogg_6_start),
        static_cast<size_t>(ogg_6_end - ogg_6_start)
        };

        extern const char ogg_7_start[] asm("_binary_7_ogg_start");
        extern const char ogg_7_end[] asm("_binary_7_ogg_end");
        static const std::string_view OGG_7 {
        static_cast<const char*>(ogg_7_start),
        static_cast<size_t>(ogg_7_end - ogg_7_start)
        };

        extern const char ogg_8_start[] asm("_binary_8_ogg_start");
        extern const char ogg_8_end[] asm("_binary_8_ogg_end");
        static const std::string_view OGG_8 {
        static_cast<const char*>(ogg_8_start),
        static_cast<size_t>(ogg_8_end - ogg_8_start)
        };

        extern const char ogg_9_start[] asm("_binary_9_ogg_start");
        extern const char ogg_9_end[] asm("_binary_9_ogg_end");
        static const std::string_view OGG_9 {
        static_cast<const char*>(ogg_9_start),
        static_cast<size_t>(ogg_9_end - ogg_9_start)
        };

        extern const char ogg_activation_start[] asm("_binary_activation_ogg_start");
        extern const char ogg_activation_end[] asm("_binary_activation_ogg_end");
        static const std::string_view OGG_ACTIVATION {
        static_cast<const char*>(ogg_activation_start),
        static_cast<size_t>(ogg_activation_end - ogg_activation_start)
        };

        extern const char ogg_err_pin_start[] asm("_binary_err_pin_ogg_start");
        extern const char ogg_err_pin_end[] asm("_binary_err_pin_ogg_end");
        static const std::string_view OGG_ERR_PIN {
        static_cast<const char*>(ogg_err_pin_start),
        static_cast<size_t>(ogg_err_pin_end - ogg_err_pin_start)
        };

        extern const char ogg_err_reg_start[] asm("_binary_err_reg_ogg_start");
        extern const char ogg_err_reg_end[] asm("_binary_err_reg_ogg_end");
        static const std::string_view OGG_ERR_REG {
        static_cast<const char*>(ogg_err_reg_start),
        static_cast<size_t>(ogg_err_reg_end - ogg_err_reg_start)
        };

        extern const char ogg_exclamation_start[] asm("_binary_exclamation_ogg_start");
        extern const char ogg_exclamation_end[] asm("_binary_exclamation_ogg_end");
        static const std::string_view OGG_EXCLAMATION {
        static_cast<const char*>(ogg_exclamation_start),
        static_cast<size_t>(ogg_exclamation_end - ogg_exclamation_start)
        };

        extern const char ogg_low_battery_start[] asm("_binary_low_battery_ogg_start");
        extern const char ogg_low_battery_end[] asm("_binary_low_battery_ogg_end");
        static const std::string_view OGG_LOW_BATTERY {
        static_cast<const char*>(ogg_low_battery_start),
        static_cast<size_t>(ogg_low_battery_end - ogg_low_battery_start)
        };

        extern const char ogg_popup_start[] asm("_binary_popup_ogg_start");
        extern const char ogg_popup_end[] asm("_binary_popup_ogg_end");
        static const std::string_view OGG_POPUP {
        static_cast<const char*>(ogg_popup_start),
        static_cast<size_t>(ogg_popup_end - ogg_popup_start)
        };

        extern const char ogg_success_start[] asm("_binary_success_ogg_start");
        extern const char ogg_success_end[] asm("_binary_success_ogg_end");
        static const std::string_view OGG_SUCCESS {
        static_cast<const char*>(ogg_success_start),
        static_cast<size_t>(ogg_success_end - ogg_success_start)
        };

        extern const char ogg_upgrade_start[] asm("_binary_upgrade_ogg_start");
        extern const char ogg_upgrade_end[] asm("_binary_upgrade_ogg_end");
        static const std::string_view OGG_UPGRADE {
        static_cast<const char*>(ogg_upgrade_start),
        static_cast<size_t>(ogg_upgrade_end - ogg_upgrade_start)
        };

        extern const char ogg_vibration_start[] asm("_binary_vibration_ogg_start");
        extern const char ogg_vibration_end[] asm("_binary_vibration_ogg_end");
        static const std::string_view OGG_VIBRATION {
        static_cast<const char*>(ogg_vibration_start),
        static_cast<size_t>(ogg_vibration_end - ogg_vibration_start)
        };

        extern const char ogg_welcome_start[] asm("_binary_welcome_ogg_start");
        extern const char ogg_welcome_end[] asm("_binary_welcome_ogg_end");
        static const std::string_view OGG_WELCOME {
        static_cast<const char*>(ogg_welcome_start),
        static_cast<size_t>(ogg_welcome_end - ogg_welcome_start)
        };

        extern const char ogg_wificonfig_start[] asm("_binary_wificonfig_ogg_start");
        extern const char ogg_wificonfig_end[] asm("_binary_wificonfig_ogg_end");
        static const std::string_view OGG_WIFICONFIG {
        static_cast<const char*>(ogg_wificonfig_start),
        static_cast<size_t>(ogg_wificonfig_end - ogg_wificonfig_start)
        };
    }
}
