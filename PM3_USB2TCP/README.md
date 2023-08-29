# PM3 USB to TCP Bridge

Connect to PM3 hardware with TCP, using ESP32-S3 as a USB to TCP bridge.  
This modding only contains the firmware of ESP32-S3, and it should work on most of the ESP32-S3 dev boards.  

# Tips:
1. To use this modding, you need a Proxmark3 client newer than commit [9c947eddcdbc66e76be6b33be9af4ce75e730b92](https://github.com/RfidResearchGroup/proxmark3/commit/9c947eddcdbc66e76be6b33be9af4ce75e730b92)
2. You need ESP-IDF to compile this project
3. The ESP32-S3 will work as a soft-AP. The SSID and password are defined in [PM3_Modding/PM3_USB2TCP/firmware/main/wifi.h](./firmware/main/wifi.h)
4. The default IP address of ESP32-S3 is `192.168.4.1`(soft-AP mode). The server port is defined in [PM3_Modding/PM3_USB2TCP/firmware/main/tcp-server.h](./firmware/main/tcp-server.h)
5. ESP32-S3 only has Bluetooth BLE, so it cannot work like the "Blue Shark" Bluetooth / Battery add-on(HC-06).
6. ESP32-S2 also has the USB-Host peripheral, so it should also works.

# Hardware Connection

| ESP32-S3 | PM3    |
| -------- | ------ |
| GND      | GND    |
| GPIO19   | USB_D- |
| GPIO20   | USB_D+ |
| 5V       | 5V     |

The 5V pin is optional.  