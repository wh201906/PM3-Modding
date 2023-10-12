#include "usb-cdc.h"

#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_err.h"
#include "usb/usb_host.h"
#include "tcp-server.h"
#include "common_vars.h"

/* ------------------------------- Callbacks -------------------------------- */
static void usb_handle_rx(uint8_t *data, size_t data_len, void *arg)
{
    ESP_LOGI(TAG_USB, "Data received: %d", data_len);
    // This slows down the communication, causes timeout
    // ESP_LOG_BUFFER_HEXDUMP(TAG_USB, data, data_len, ESP_LOG_INFO);

    if (data_socket != INVALID_SOCK)
    {
        ESP_LOGI(TAG_USB, "Sending to socket %d", data_socket);
        int len = socket_send("USB2TCP", data_socket, (char *)data, data_len);
        if (len < 0)
        {
            // Error occurred on write to this socket -> close it and mark invalid
            ESP_LOGI(TAG_USB, "[sock=%d]: socket_send() returned %d -> closing the socket", data_socket, len);
            close(data_socket);
            data_socket = INVALID_SOCK;
        }
        else
        {
            ESP_LOGI(TAG_USB, "Data sent: %d", len);
        }
    }
}

static void usb_handle_event(const cdc_acm_host_dev_event_data_t *event, void *user_ctx)
{
    ESP_LOGI(TAG_USB, "Event:\ntype:%u,data:%u", event->type, event->data);
}

void usb_lib_task(void *arg)
{
    while (1)
    {
        //Start handling system events
        uint32_t event_flags;
        usb_host_lib_handle_events(portMAX_DELAY, &event_flags);
        if (event_flags & USB_HOST_LIB_EVENT_FLAGS_NO_CLIENTS)
        {
            ESP_LOGI(TAG_USB, "All clients deregistered");
            ESP_ERROR_CHECK(usb_host_device_free_all());
        }
        if (event_flags & USB_HOST_LIB_EVENT_FLAGS_ALL_FREE)
        {
            break;
        }
    }

    //Clean up USB Host
    ESP_ERROR_CHECK(usb_host_uninstall());
    vTaskDelete(NULL);
}

esp_err_t usb_cdc_open(uint16_t vid, uint16_t pid, cdc_acm_dev_hdl_t *cdc_hdl_ret)
{
    ESP_LOGI(TAG_USB, "Opening CDC ACM device 0x%04X:0x%04X", vid, pid);
    const cdc_acm_host_device_config_t dev_config = {
        .connection_timeout_ms = 5000,
        .out_buffer_size = USB_HOST_OUT_BUFFER_SIZE,
        .user_arg = NULL,
        .event_cb = usb_handle_event,
        .data_cb = usb_handle_rx};
    esp_err_t result = cdc_acm_host_open_vendor_specific(vid, pid, 1, &dev_config, cdc_hdl_ret);
    assert(*cdc_hdl_ret);
    if (result == ESP_OK)
        ESP_LOGI(TAG_USB, "Opened");
    else
        ESP_LOGI(TAG_USB, "Failed");
    return result;
}

void usb_cdc_init(void)
{
    ESP_LOGI(TAG_USB, "Installing USB Host");
    usb_host_config_t host_config = {
        .skip_phy_setup = false,
        .intr_flags = ESP_INTR_FLAG_LEVEL1,
    };
    ESP_ERROR_CHECK(usb_host_install(&host_config));

    // Create a task that will handle USB library events
    xTaskCreate(usb_lib_task, "usb_lib", 4096, xTaskGetCurrentTaskHandle(), USB_HOST_PRIORITY, NULL);

    ESP_LOGI(TAG_USB, "Installing CDC-ACM driver");
    ESP_ERROR_CHECK(cdc_acm_host_install(NULL));
}
