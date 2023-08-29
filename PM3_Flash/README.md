# PM3 Flash

Add the external SPI flash to the Proxmark3 Easy, to unlock all of the sandalone modes.  

# Tips:
1. Some of the new Proxmark3 Easy has already intergrated an external SPI flash. If you know how to flash the firmware to the Proxmark3 Easy, you can try to flash a SPI flash enabled firmware to test if the external flash exists.
2. The SPI flash chip will be powered at 3.3V, but some SPI flash chips on the market can only be powered at 1.xV.
3. The SPI flash on the Proxmark3 RDV4 has a capacity of 256kBytes, but you can also use chips with higher capacity. Only 256kBytes will be used unless you changed the code of the firmware.
4. To use the SPI flash, you need to flash your Proxmark3 with SPI flash enabled firmware.
5. To initialize the SPI flash, you need to run the [Proxmark3/client/luascripts/init_rdv4.lua](https://github.com/RfidResearchGroup/proxmark3/blob/v4.16717/client/luascripts/init_rdv4.lua) in the client.

# Soldering

| Module | MCU  |
| ------ | ---- |
| VCC    | 3.3V |
| GND    | GND  |
| CLK    | PA14 |
| MISO   | PA12 |
| MOSI   | PA13 |
| CS     | PA10 |

Please refer to the datasheet of AT91SAM7Sxxx to find the physical position of these pins.  
For some of the old Proxmark3 Easy, the PA14_SPCK, PA12_MISO and PA13_MOSI pin are exported near the JTAG pins. You only need to jump 1 wire(PA10_NPCS2) to the MCU directly.
