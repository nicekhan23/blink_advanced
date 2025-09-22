#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "esp_log.h"
#include "blink.h"
#include "freertos/projdefs.h"
#include "gpio.h"

static bool blink_initialized = false;
static uint16_t blink_delay_ms = CONFIG_BLINK_PERIOD; // Delay from the configuration
static char *TAG = "blink";
static uint8_t s_led_state = 0;

#define LOG_LOCAL_LEVEL ESP_LOG_DEBUG

static void blink(void)
{
    esp_set_level(CONFIG_BLINK_LED_GPIO, s_led_state);
    s_led_state = s_led_state ? 0 : 1;
}

static void blink_task(void *arg){
    ESP_LOGD(TAG, "Blink task started with delay %d ms", blink_delay_ms);
    while (true) {
        if (blink_initialized)
        {
            blink();
        }
        vTaskDelay(pdMS_TO_TICKS(blink_delay_ms));
    }
}

BaseType_t blink_init(void){
    esp_log_level_set(TAG, LOG_LOCAL_LEVEL);
    gpio_reset_pin(CONFIG_BLINK_LED_GPIO);
    rtc_gpio_set_direction(CONFIG_BLINK_LED_GPIO, GPIO_MODE_OUTPUT);
    return xTaskCreate(blink_task, "blink_task", 2048, NULL, uxTaskPriorityGet(NULL), NULL);
}

BaseType_t blink_deinit(void){
    return pdPASS;
}