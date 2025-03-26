#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <freertos/FreeRTOS.h>
#include <freertos/event_groups.h>
#include <freertos/task.h>
#include <esp_timer.h>

#include <string>
#include <mutex>
#include <list>

#include <opus_encoder.h>
#include <opus_decoder.h>
#include <opus_resampler.h>

#include "audio_codec.h"
#include "display.h"
#include "protocol.h"
#include "version.h"
#include "background_task.h"

#if CONFIG_USE_WAKE_WORD_DETECT
#include "wake_word_detect.h"
#endif
#if CONFIG_USE_AUDIO_PROCESSOR
#include "audio_processor.h"
#endif

#define SCHEDULE_EVENT (1 << 0)
#define AUDIO_INPUT_READY_EVENT (1 << 1)
#define AUDIO_OUTPUT_READY_EVENT (1 << 2)

enum DeviceState {
    kDeviceStateUnknown,
    kDeviceStateStarting,
    kDeviceStateWifiConfiguring,
    kDeviceStateIdle,
    kDeviceStateConnecting,
    kDeviceStateListening,
    kDeviceStateSpeaking,
    kDeviceStateUpgrading,
    kDeviceStateActivating,
    kDeviceStateFatalError
};

#define OPUS_FRAME_DURATION_MS 60

class Application {
public:
    static Application& GetInstance() {
        static Application instance;
        return instance;
    }
    // 删除拷贝构造函数和赋值运算符
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    void Start(AudioCodec* _audio_codec, Display* _display);
    DeviceState GetDeviceState() const { return device_state_; }
    bool IsVoiceDetected() const { return voice_detected_; }
    void Schedule(std::function<void()> callback);
    void SetDeviceState(DeviceState state);
    void Alert(const char* status, const char* message, const char* emotion = "", const std::string_view& sound = "");
    void DismissAlert();
    void AbortSpeaking(AbortReason reason);
    void ToggleChatState();
    void StartListening();
    void StopListening();
    void UpdateIotStates();
    void Reboot();
    void WakeWordInvoke(const std::string& wake_word);
    void PlaySound(const std::string_view& sound);
    bool CanEnterSleepMode();

private:
    Application();
    ~Application();

#if CONFIG_USE_WAKE_WORD_DETECT
    WakeWordDetect wake_word_detect_;
#endif
#if CONFIG_USE_AUDIO_PROCESSOR
    AudioProcessor audio_processor_;
#endif
    Version _version;
    std::mutex mutex_;
    std::list<std::function<void()>> main_tasks_;
    std::unique_ptr<Protocol> protocol_;
    EventGroupHandle_t event_group_ = nullptr;
    esp_timer_handle_t clock_timer_handle_ = nullptr;
    volatile DeviceState device_state_ = kDeviceStateUnknown;
    bool keep_listening_ = false;
    bool aborted_ = false;
    bool voice_detected_ = false;
    int clock_ticks_ = 0;

    // Audio encode / decode
    BackgroundTask* background_task_ = nullptr;
    std::chrono::steady_clock::time_point last_output_time_;
    std::list<std::vector<uint8_t>> audio_decode_queue_;

    std::unique_ptr<OpusEncoderWrapper> opus_encoder_;
    std::unique_ptr<OpusDecoderWrapper> opus_decoder_;

    int opus_decode_sample_rate_ = -1;
    OpusResampler input_resampler_;
    OpusResampler reference_resampler_;
    OpusResampler output_resampler_;

    void MainLoop();
    void InputAudio();
    void OutputAudio();
    void ResetDecoder();
    void SetDecodeSampleRate(int sample_rate);
    void CheckNewVersion();
    void ShowActivationCode();
    void OnClockTimer();
public:
    static Display* display;
    static Display* GetDisplay() { return display; }
    static AudioCodec* codec;
    static AudioCodec* GetAudioCodec() { return codec; }
};

#endif // _APPLICATION_H_
