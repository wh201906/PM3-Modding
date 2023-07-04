/*
 * SPDX-FileCopyrightText: 2015-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <string.h>
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_err.h"
#include "usb/usb_host.h"
#include "usb/cdc_acm_host.h"

#define USB_HOST_PRIORITY 20
// For Proxmark3
#define USB_DEVICE_VID 0x9AC4
#define USB_DEVICE_PID 0x4B8F

static const char *TAG = "USB-CDC";

/* ------------------------------- Callbacks -------------------------------- */
static void handle_rx(uint8_t *data, size_t data_len, void *arg)
{
    ESP_LOGI(TAG, "Data received");
    ESP_LOG_BUFFER_HEXDUMP(TAG, data, data_len, ESP_LOG_INFO);
}

void usb_lib_task(void *arg)
{
    while (1) {
        //Start handling system events
        uint32_t event_flags;
        usb_host_lib_handle_events(portMAX_DELAY, &event_flags);
        if (event_flags & USB_HOST_LIB_EVENT_FLAGS_NO_CLIENTS) {
            ESP_LOGI(TAG, "All clients deregistered");
            ESP_ERROR_CHECK(usb_host_device_free_all());
        }
        if (event_flags & USB_HOST_LIB_EVENT_FLAGS_ALL_FREE) {
            break;
        }
    }

    //Clean up USB Host
    ESP_ERROR_CHECK(usb_host_uninstall());
    vTaskDelete(NULL);
}

/* ---------------------------------- Main ---------------------------------- */
void app_main(void)
{
    //Install USB Host driver. Should only be called once in entire application
    ESP_LOGI(TAG, "Installing USB Host");
    usb_host_config_t host_config = {
        .skip_phy_setup = false,
        .intr_flags = ESP_INTR_FLAG_LEVEL1,
    };
    ESP_ERROR_CHECK(usb_host_install(&host_config));

    // Create a task that will handle USB library events
    xTaskCreate(usb_lib_task, "usb_lib", 4096, xTaskGetCurrentTaskHandle(), USB_HOST_PRIORITY, NULL);

    ESP_LOGI(TAG, "Installing CDC-ACM driver");
    ESP_ERROR_CHECK(cdc_acm_host_install(NULL));

    ESP_LOGI(TAG, "Opening CDC ACM device 0x%04X:0x%04X", USB_DEVICE_VID, USB_DEVICE_PID);
    cdc_acm_dev_hdl_t cdc_dev;
    const cdc_acm_host_device_config_t dev_config = {
        .connection_timeout_ms = 5000,
        .out_buffer_size = 64,
        .user_arg = NULL,
        .event_cb = NULL,
        .data_cb = handle_rx
    };
    ESP_ERROR_CHECK(cdc_acm_host_open_vendor_specific(USB_DEVICE_VID, USB_DEVICE_PID, 1, &dev_config, &cdc_dev));
    assert(cdc_dev);
    cdc_acm_host_desc_print(cdc_dev);
    vTaskDelay(100);

    ESP_LOGI(TAG, "Example finished successfully!");
}
