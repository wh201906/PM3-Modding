#include <stdio.h>
#include <string.h>
#include "esp_system.h"
#include "esp_log.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "usb-cdc.h"
#include "wifi.h"
#include "tcp-server.h"
#include "common_vars.h"

#define USB_DEVICE_VID 0x9AC4
#define USB_DEVICE_PID 0x4B8F

/* ---------------------------------- Main ---------------------------------- */
void app_main(void)
{
    //Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    ESP_ERROR_CHECK(esp_event_loop_create_default());
    ESP_ERROR_CHECK(esp_netif_init());


    wifi_init_softap(); // Create a Wifi AP
    // wifi_init_sta(); // Connect to a Wifi AP

    tcp_server_init();
    usb_cdc_init();
    usb_cdc_open(USB_DEVICE_VID, USB_DEVICE_PID, &cdc_dev);
}
