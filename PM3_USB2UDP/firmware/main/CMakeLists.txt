idf_component_register(
    SRCS 
        "udp-server.c" 
        "app_main.c" 
        "usb-cdc.c" 
        "wifi/wifi_ap.c" 
        "wifi/wifi_station.c" 
        "common_vars.c"                
    INCLUDE_DIRS 
        "."
        "wifi/"
)
target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")
