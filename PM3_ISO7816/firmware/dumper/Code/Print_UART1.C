/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2017 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//  Date   : Jan/21/2017
//***********************************************************************************************************

//***********************************************************************************************************
//  File Function: N76E003 GPIO demo code
//***********************************************************************************************************
#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"

unsigned char temp _at_ 0x08;
unsigned char idata itemp _at_ 0x80;
unsigned char xdata xtemp _at_ 0x80;

/*==========================================================================*/

#define BYTE_READ_AP 0x00
#define BYTE_READ_LD 0x40
#define BYTE_READ_CONFIG 0xC0

// This macro doesn't touch the interrupt
// Call it at the start of the program
#define set_IAPEN_m \
  TA = 0xAA;        \
  TA = 0x55;        \
  CHPCON |= SET_BIT0;

// THE CODE OPTIMIZATION LEVEL MUST BE 8 OR LOWER

void Trigger_IAP(void)
{
  set_IAPGO;                           //trigger IAP
  if ((CHPCON & SET_BIT6) == SET_BIT6) // if fail flag is set, print "err" then continue
  {
    putchar('e');
    putchar('r');
    putchar('r');
    clr_IAPFF;
  }
}

void Print_Config_Byte(UINT8 CONFIGn)
{
  IAPAL = CONFIGn;
  IAPAH = 0x00;
  IAPCN = BYTE_READ_CONFIG;

  Trigger_IAP();
  putchar(IAPFD);
}

void Print_ROM(UINT8 nK, UINT8 cmd)
{
  UINT16 u16Count;
  UINT16 data_size_all = 1024 * nK;

  IAPAL = 0x00;
  IAPAH = 0x00;
  IAPCN = cmd;

  for (u16Count = 0; u16Count < data_size_all; u16Count++)
  {
    Trigger_IAP();
    putchar(IAPFD);
    IAPAL++;

    if (IAPAL == 0)
      IAPAH++;
  }
}

void main(void)
{
  set_IAPEN_m;
  // Baudrate is defined in Common.h
  InitialUART1_Timer3();
  TI_1 = 1;

  Timer0_Delay10ms(255); // 2550 ms

  // It takes less than 1400ms to print the whole APROM
  // Set frame timeout to 1350ms to get the CONFIG bytes, LDROM and APROM as three frames

  // Read CONFIG bytes
  Print_Config_Byte(0);
  Print_Config_Byte(1);
  Print_Config_Byte(2);
  Print_Config_Byte(3);
  Print_Config_Byte(4);
  Timer0_Delay10ms(140);

  // For PM3 Rdv4, CONFIG1 = 0xFE -> 1kB for LDROM and 17kB for APROM
  // Read LDROM
  Print_ROM(1, BYTE_READ_LD);
  Timer0_Delay10ms(140);

  // Read APROM
  Print_ROM(17, BYTE_READ_AP);

  // clr_IAPEN; // not necessary, takes up more APROM
  while (1)
    ;
}