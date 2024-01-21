# PM3 USB to TCP Bridge

Connect to PM3 hardware with TCP, using ESP32-S3/S2 as a USB to TCP bridge.  
This modding only contains the firmware of ESP32-S3, and it should work on most of the ESP32-S3 and ESP32-S2 dev boards.  

# Tips:
1. To use this modding, you need a Proxmark3 client newer than commit [9c947eddcdbc66e76be6b33be9af4ce75e730b92](https://github.com/RfidResearchGroup/proxmark3/commit/9c947eddcdbc66e76be6b33be9af4ce75e730b92)
2. You need ESP-IDF or GitHub Action to build this project
3. The ESP32-S3 can work as a soft-AP. The SSID and the password are defined in [PM3_Modding/PM3_USB2TCP/firmware/main/wifi/wifi.h](./firmware/main/wifi/wifi.h)
4. To connect to an existing AP like wireless router or mobile hotspot, you should follow these steps:  
    + Set the correct SSID and password in [PM3_Modding/PM3_USB2TCP/firmware/main/wifi/wifi.h](./firmware/main/wifi/wifi.h)
    + Comment out `wifi_init_softap();` in [PM3_Modding/PM3_USB2TCP/firmware/main/app_main.c](./firmware/main/app_main.c)
    + Uncomment `wifi_init_sta();` in [PM3_Modding/PM3_USB2TCP/firmware/main/app_main.c](./firmware/main/app_main.c)
    + To get the IP address allocated by the DHCP server, you can check the output on UART0(GPIO43 for Tx, GPIO44 for Rx) or the management page of the router
    + (Optional) If it's not convenient to get the allocated IP address, you can set the static IP address in [PM3_Modding/PM3_USB2TCP/firmware/main/wifi/wifi.h](./firmware/main/wifi/wifi.h)
5. The default IP address of ESP32-S3 is `192.168.4.1`(soft-AP mode). The server port is defined in [PM3_Modding/PM3_USB2TCP/firmware/main/tcp-server.h](./firmware/main/tcp-server.h)
6. ESP32-S2 also has the USB-Host peripheral, so it also works. Remember to set the correct target chip in ESP-IDF.
7. Some of the arguments mentioned above can be configured by running `idf.py menuconfig` -> `USB Bridge Configuration`.

# Hardware Connection

| ESP32-S3 | PM3    |
| -------- | ------ |
| GND      | GND    |
| GPIO19   | USB_D- |
| GPIO20   | USB_D+ |
| 5V       | 5V     |

The 5V pin is optional.  