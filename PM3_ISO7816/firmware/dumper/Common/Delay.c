/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2016 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Nuvoton Technoledge Corp.
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//  Date   : Apr/21/2016
//***********************************************************************************************************

#include "N76E003.h"
#include "Common.h"
#include "Delay.h"
#include "SFR_Macro.h"
#include "Function_define.h"
bit BIT_TMP;

//------------------------------------------------------------------------------
void Timer0_Delay10ms(UINT8 u8CNT)
{
  clr_T0M;      //T0M=0, Timer0 Clock = Fsys/12
  TMOD |= 0x01; //Timer0 is 16-bit mode
  set_TR0;      //Start Timer0
  while (u8CNT != 0)
  {
    TL0 = LOBYTE(TIMER_DIV12_VALUE_10ms); //Find  define in "Function_define.h" "TIMER VALUE"
    TH0 = HIBYTE(TIMER_DIV12_VALUE_10ms);
    while (TF0 != 1)
      ; //Check Timer0 Time-Out Flag
    clr_TF0;
    u8CNT--;
  }
  clr_TR0; //Stop Timer0
}
