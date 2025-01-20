#include "temp_sense.h"

#include "esp_log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "ntc_driver.h"

#include <math.h>

static const char *LOG_TAG = "temp_sense";

ntc_config_t ntc_config = {
    .b_value = 3435,
    .r25_ohm = 10000,
    .fixed_ohm = 10000,
    .vdd_mv = 3300,
    .circuit_mode = CIRCUIT_MODE_NTC_GND,
    .atten = ADC_ATTEN_DB_11,
    .channel = ADC_CHANNEL_0,
    .unit = ADC_UNIT_1,
};

ntc_device_handle_t ntc = NULL;
adc_oneshot_unit_handle_t adc_handle = NULL;

esp_err_t temp_sense_init(void)
{
    esp_err_t ret = ESP_OK;
    ret = ntc_dev_create(&ntc_config, &ntc, &adc_handle);
    if (ret != ESP_OK)
    {
        ESP_LOGE(LOG_TAG, "ntc_dev_create failed");
        return ret;
    }
    ret = ntc_dev_get_adc_handle(ntc, &adc_handle);
    if (ret != ESP_OK)
    {
        ESP_LOGE(LOG_TAG, "ntc_dev_get_adc_handle failed");
        return ret;
    }
    return ret;
}

void temp_sense_task(void *pvParameter)
{
    while (1)
    {
        // Get NTC sensor data
        float temp = NAN;
        esp_err_t ret = ntc_dev_get_temperature(ntc, &temp);
        if (ret == ESP_OK)
        {
            ESP_LOGI(LOG_TAG, "NTC temperature = %.2f°C.", temp);
        }
        else
        {
            ESP_LOGE(LOG_TAG, "Failed to get sensor data");
            break;
        }

        // Wait for 1 second before the next read
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    ESP_ERROR_CHECK(ntc_dev_delete(ntc));
}
