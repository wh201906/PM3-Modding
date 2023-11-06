#pragma once

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_mac.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"

#include "lwip/err.h"
#include "lwip/sys.h"

#define WIFI_AP_SSID "PM3_ESPBridge"
#define WIFI_AP_PWD "[PM3_USB]"
#define WIFI_AP_CHANNEL 5
#define WIFI_AP_MAX_STA_CONN 3

static const char *TAG_WIFI = "wifi softAP";

void wifi_init_softap(void);
