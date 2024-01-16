# PM3 ISO7816

Add the smartcard module to the Proxmark3 Easy.  

# Tips:
1. The MCU on the original smartcard module is Nuvoton's N76E003xQ20. I use the TSSOP-20 package(N76E003AT20) rather than QFN-20 package for easier manufacturing. The firmware works on both of them.
2. The firmware is separated into LDROM(kinda like bootloader) and APROM. To use this module, you need to flash the LDROM and APROM to the MCU first. 
3. The APROM can be found in the [Proxmark3 RRG repo](https://github.com/RfidResearchGroup/proxmark3/blob/v4.16717/client/resources/sim013.bin) with its [source code](https://github.com/RfidResearchGroup/proxmark3/blob/v4.16717/tools/simmodule/sim013.asm). The LDROM is [PM3_Modding/PM3_ISO7816/firmware/LDROM.bin](./firmware/LDROM.bin), which is closed-source and unreleased. I managed to get it from an original smartcard module.
4. You need to flash your Proxmark3 with smartcard module enabled firmware in order to use this module.

# Soldering

| Module | MCU  |
| ------ | ---- |
| VCC    | 3.3V |
| SDA    | PA7  |
| SCL    | PA5  |
| nRST   | PA1  |
| GND    | GND  |

Please refer to the datasheet of AT91SAM7Sxxx to find the physical position of these pins.  
For some of the old Proxmark3 Easy, the PA1 pin is exported near the JTAG pins. You only need to jump 2 wires(PA5, PA7) to the MCU directly.  
