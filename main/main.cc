#include <esp_log.h>
#include <esp_err.h>
#include <nvs.h>
#include <nvs_flash.h>
#include <driver/gpio.h>
#include <esp_event.h>

#include "board.h"
#include "wifi_board.h"
#include "audio_codec.h"
#include "no_audio_codec.h"
#include "display.h"
#include "application.h"

#define TAG "main"

#define AUDIO_INPUT_SAMPLE_RATE  24000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000
#define AUDIO_DEFAULT_OUTPUT_VOLUME 80

#define AUDIO_I2S_GPIO_MCLK GPIO_NUM_21
#define AUDIO_I2S_GPIO_WS   GPIO_NUM_16
#define AUDIO_I2S_GPIO_BCLK GPIO_NUM_18
#define AUDIO_I2S_GPIO_DIN  GPIO_NUM_NC
#define AUDIO_I2S_GPIO_DOUT GPIO_NUM_17
#define AUDIO_MUTE_PIN      GPIO_NUM_48   // 低电平静音

#define AUDIO_MIC_WS_PIN    GPIO_NUM_45
#define AUDIO_MIC_SD_PIN    GPIO_NUM_46
#define AUDIO_MIC_SCK_PIN   GPIO_NUM_42

class DisplayPrint : public Display
{
public:
    DisplayPrint() {};
    ~DisplayPrint() {};
};

DisplayPrint *display = nullptr;
NoAudioCodecSimplex* audio_codec = nullptr;

extern "C" void app_main(void)
{
    // Initialize the default event loop
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    // Initialize NVS flash for WiFi configuration
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_LOGW(TAG, "Erasing NVS flash to fix corruption");
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    audio_codec = new NoAudioCodecSimplex(AUDIO_INPUT_SAMPLE_RATE,
                                          AUDIO_OUTPUT_SAMPLE_RATE,
                                          AUDIO_I2S_GPIO_BCLK,
                                          AUDIO_I2S_GPIO_WS,
                                          AUDIO_I2S_GPIO_DOUT,
                                          AUDIO_MIC_SCK_PIN,
                                          AUDIO_MIC_WS_PIN,
                                          AUDIO_MIC_SD_PIN);
    display = new DisplayPrint();
    // Launch the application
    Application::GetInstance().Start(audio_codec, display);
    // The main thread will exit and release the stack memory
}
