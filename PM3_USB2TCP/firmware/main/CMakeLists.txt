idf_component_register(SRCS "app_main.c" "usb-cdc.c" "wifi.c" "tcp-server.c" "common_vars.c"
                    INCLUDE_DIRS ".")
target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")
