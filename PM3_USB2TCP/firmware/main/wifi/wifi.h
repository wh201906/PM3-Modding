#pragma once

#include "esp_wifi.h"
#include "sdkconfig.h"

#if !CONFIG_BRIDGE_USE_CONFIG 
    // Items in Kconfig are not used unless configured

    // For AP/Station
    #define WIFI_SSID    "PM3_ESPBridge"
    #define WIFI_PWD     "[PM3_USB]"

    // For station only
    // If WIFI_STA_STATIC_IP_ADDR is set to "", use allocated IP address.
    // Don't forget to set WIFI_STA_STATIC_GATEWAY_ADDR if WIFI_STA_STATIC_IP_ADDR is specified.
    #define WIFI_STA_STATIC_IP_ADDR         ""
    #define WIFI_STA_STATIC_NETMASK_ADDR    "255.255.255.0"
    #define WIFI_STA_STATIC_GATEWAY_ADDR    ""
    // DNS is unnecessary because it doesn't access the Internet
#else
    // Ignore this block if items in Kconfig are not used
    #define WIFI_SSID    CONFIG_BRIDGE_WIFI_SSID
    #define WIFI_PWD     CONFIG_BRIDGE_WIFI_PASSWORD
    #if !CONFIG_BRIDGE_WIFI_STA_USE_STATIC_IP
        #define WIFI_STA_STATIC_IP_ADDR         ""
        #define WIFI_STA_STATIC_NETMASK_ADDR    "255.255.255.0"
        #define WIFI_STA_STATIC_GATEWAY_ADDR    ""
    #else
        #define WIFI_STA_STATIC_IP_ADDR         CONFIG_BRIDGE_WIFI_STA_STATIC_IP_ADDR
        #define WIFI_STA_STATIC_NETMASK_ADDR    CONFIG_BRIDGE_WIFI_STA_STATIC_NETMASK_ADDR
        #define WIFI_STA_STATIC_GATEWAY_ADDR    CONFIG_BRIDGE_WIFI_STA_STATIC_GATEWAY_ADDR
    #endif
#endif

// For AP only
#define WIFI_AP_CHANNEL 5
#define WIFI_AP_MAX_STA_CONN 3

// For station only
#define WIFI_STA_MAX_RETRY 3
#define WIFI_STA_H2E_IDENTIFIER ""

static const char *TAG_WIFI = "Wifi";

void wifi_init_softap(void);
void wifi_init_sta(void);
