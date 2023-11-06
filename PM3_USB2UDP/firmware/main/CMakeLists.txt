idf_component_register(SRCS "udp-server.c" "app_main.c" "usb-cdc.c" "wifi.c" "common_vars.c"
                    INCLUDE_DIRS ".")
target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")
