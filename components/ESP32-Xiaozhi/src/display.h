#ifndef DISPLAY_H
#define DISPLAY_H

#include <esp_timer.h>
#include <esp_log.h>
#include <esp_pm.h>

#include <string>


class Display {
public:
    Display();
    virtual ~Display();

    virtual void SetStatus(const char* status);
    virtual void ShowNotification(const char* notification, int duration_ms = 3000);
    virtual void ShowNotification(const std::string &notification, int duration_ms = 3000);
    virtual void SetEmotion(const char* emotion);
    virtual void SetChatMessage(const char* role, const char* content);
    virtual void SetIcon(const char* icon);
    virtual void SetTheme(const std::string& theme_name);
    virtual std::string GetTheme() { return current_theme_name_; }

protected:
    std::string current_theme_name_ = "hello esp32 xiaozhi!";

};

#endif
