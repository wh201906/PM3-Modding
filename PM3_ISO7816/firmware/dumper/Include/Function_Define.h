/*--------------------------------------------------------------------------
N76E003 Function_define.h V1.02

All function define inital setting file for Nuvoton N76E003
--------------------------------------------------------------------------*/

#include <intrins.h>
#include <stdio.h>

#define nop _nop_();

//16 --> 8 x 2
#define HIBYTE(v1)              ((UINT8)((v1)>>8))                      //v1 is UINT16
#define LOBYTE(v1)              ((UINT8)((v1)&0xFF))

#define SET_BIT0        0x01
#define SET_BIT1        0x02
#define SET_BIT2        0x04
#define SET_BIT3        0x08
#define SET_BIT4        0x10
#define SET_BIT5        0x20
#define SET_BIT6        0x40
#define SET_BIT7        0x80
#define SET_BIT8        0x0100
#define SET_BIT9        0x0200
#define SET_BIT10       0x0400
#define SET_BIT11       0x0800
#define SET_BIT12       0x1000
#define SET_BIT13       0x2000
#define SET_BIT14       0x4000
#define SET_BIT15       0x8000

/*****************************************************************************************
* For GPIO INIT setting 
*****************************************************************************************/
//------------------- Define Port as Quasi mode  -------------------
#define P02_Quasi_Mode				P0M1&=~SET_BIT2;P0M2&=~SET_BIT2
#define P16_Quasi_Mode				P1M1&=~SET_BIT6;P1M2&=~SET_BIT6

/*****************************************************************************************
* For TIMER VALUE setting is base on " option -> C51 -> Preprocesser Symbols -> Define "
*****************************************************************************************/
#ifdef FOSC_160000		// if Fsys = 16MHz 
		#define TIMER_DIV12_VALUE_10us			65536-13		//13*12/16000000 = 10 uS,  			// Timer divider = 12 for TM0/TM1
		#define TIMER_DIV12_VALUE_100us			65536-130		//130*12/16000000 = 10 uS,  		// Timer divider = 12 
		#define TIMER_DIV12_VALUE_1ms				65536-1334	//1334*12/16000000 = 1 mS, 			// Timer divider = 12 
		#define TIMER_DIV12_VALUE_10ms			65536-13334	//13334*12/16000000 = 10 mS 		// Timer divider = 12 
		#define TIMER_DIV12_VALUE_40ms			65536-53336	//53336*12/16000000 = 40 ms			// Timer divider = 12 
		#define TIMER_DIV4_VALUE_10us				65536-40		//40*4/16000000 = 10 uS,    		// Timer divider = 4	for TM2/TM3
		#define TIMER_DIV4_VALUE_100us			65536-400		//400*4/16000000 = 100 us				// Timer divider = 4
		#define TIMER_DIV4_VALUE_200us			65536-800		//800*4/16000000 = 200 us				// Timer divider = 4
		#define TIMER_DIV4_VALUE_500us			65536-2000	//2000*4/16000000 = 500 us			// Timer divider = 4
    #define TIMER_DIV4_VALUE_1ms				65536-4000	//4000*4/16000000 = 1 mS,   		// Timer divider = 4
		#define TIMER_DIV16_VALUE_10ms			65536-10000	//10000*16/16000000 = 10 ms			// Timer	divider = 16
		#define TIMER_DIV64_VALUE_30ms			65536-7500	//7500*64/16000000 = 30 ms			// Timer divider = 64
		#define	TIMER_DIV128_VALUE_100ms		65536-12500	//12500*128/16000000 = 100 ms		// Timer divider = 128
		#define	TIMER_DIV128_VALUE_200ms		65536-25000	//25000*128/16000000 = 200 ms		// Timer divider = 128
		#define TIMER_DIV256_VALUE_500ms		65536-31250	//31250*256/16000000 = 500 ms 	// Timer divider = 256
		#define	TIMER_DIV512_VALUE_1s				65536-31250	//31250*512/16000000 = 1 s.  		// Timer Divider = 512
#endif
