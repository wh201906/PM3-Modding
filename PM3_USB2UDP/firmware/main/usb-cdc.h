#pragma once

#include "esp_system.h"
#include "usb/cdc_acm_host.h"

#define USB_HOST_PRIORITY 20
#define USB_HOST_OUT_BUFFER_SIZE 256

static const char *TAG_USB = "USB-CDC";

void usb_cdc_init(void);
esp_err_t usb_cdc_open(uint16_t vid, uint16_t pid, cdc_acm_dev_hdl_t *cdc_hdl_ret);
