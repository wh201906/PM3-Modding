This project is based on `N76E003_BSP_Keil_C51_V1.0.6.zip` -> `Sample_Code\UART1_printf`, with these changes:  

+ Add common dependencies  
+ Remove some unused functions and macros  
+ Remove division  

To read the data in flash:  
(Including CONFIG bytes, LDROM and part of the APROM)
1. copy the `dumper.bin` and `dumper.sha512.txt` into the `resource` folder of the client  
2. run `smart upgrade -f dumper.bin` in the client  
3. Connect the DAT pin of the smartcard module to the Rx pin of a USB to serial adapter
4. Open the corresponding serial port. (baudrate=115200, databits=8, stopbits=1)
5. run `hw status` in the client
6. Now you get the data from the serial port

The first 5 bytes are CONFIG0 ~ CONFIG4  
Then 1024 bytes of LDROM
Then 17408 bytes of APROM(The first 384 bytes are overwritten by the dumper.bin)
If your serial monitor supports splitting frames by timeout, just set the timeout to ~1350ms, then you will get the data above split into three frames.

The `hex2bin.exe` is from https://sourceforge.net/projects/hex2bin/
