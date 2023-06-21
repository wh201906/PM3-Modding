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

//----------------------------------------------------------------------------------
// UART1 baud rate initial setting
//----------------------------------------------------------------------------------
void InitialUART1_Timer3() //use timer3 as Baudrate generator
{
  P02_Quasi_Mode; //Setting UART pin as Quasi mode for transmit
  P16_Quasi_Mode; //Setting UART pin as Quasi mode for transmit

  SCON_1 = 0x50; //UART1 Mode1,REN_1=1,TI_1=1
  T3CON = 0x08;  //T3PS2=0,T3PS1=0,T3PS0=0(Prescale=1), UART1 in MODE 1
  clr_BRCK;

#ifdef FOSC_160000
  RH3 = HIBYTE(65536 - (1000000 / (UINT32)BAUDRATE) - 1); /*16 MHz */
  RL3 = LOBYTE(65536 - (1000000 / (UINT32)BAUDRATE) - 1); /*16 MHz */
#endif
#ifdef FOSC_166000
  RH3 = HIBYTE(65536 - (1037500 / (UINT32)BAUDRATE); /*16.6 MHz */
  RL3 = LOBYTE(65536 - (1037500 / (UINT32)BAUDRATE); /*16.6 MHz */
#endif
  set_TR3; //Trigger Timer3
}
