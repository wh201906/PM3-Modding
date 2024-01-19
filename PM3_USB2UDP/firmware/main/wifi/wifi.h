#pragma once

#include "esp_wifi.h"

// For AP/Station
#define WIFI_SSID "PM3_ESPBridge"
#define WIFI_PWD "[PM3_USB]"

// For AP only
#define WIFI_AP_CHANNEL 5
#define WIFI_AP_MAX_STA_CONN 3

// For station only
#define WIFI_STA_MAX_RETRY 3
#define WIFI_STA_H2E_IDENTIFIER ""

static const char *TAG_WIFI = "Wifi";

void wifi_init_softap(void);
void wifi_init_sta(void);
