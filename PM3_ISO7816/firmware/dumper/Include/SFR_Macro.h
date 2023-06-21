
/**** P0		80H *****/
#define set_P00			P00		=		1
#define set_P01			P01		=		1
#define set_P02			P02		=		1
#define set_P03			P03		=		1
#define set_P04			P04		=		1
#define set_P05			P05		=		1
#define set_P06			P06		=		1
#define set_P07			P07		=		1

#define clr_P00			P00		=		0
#define clr_P01			P01		=		0
#define clr_P02			P02		=		0
#define clr_P03			P03		=		0
#define clr_P04			P04		=		0
#define clr_P05			P05		=		0
#define clr_P06			P06		=		0
#define clr_P07			P07		=		0

//**** SP  	81H **** 
//**** DPH  82H **** 
//**** DPL  83H **** 
//**** RWK  86H **** 

/**** TCON		88H ****/
#define set_TF1			TF1		=		1
#define set_TR1			TR1		=		1
#define set_TF0			TF0		=		1
#define set_TR0			TR0		=		1
#define set_IE1			IE1		=		1
#define set_IT1			IT1		=		1
#define set_IE0			IE0		=		1
#define set_IT0			IT0		=		1

#define clr_TF1			TF1		=		0
#define clr_TR1			TR1		=		0
#define clr_TF0			TF0		=		0
#define clr_TR0			TR0		=		0
#define clr_IE1			IE1		=		0
#define clr_IT1			IT1		=		0
#define clr_IE0			IE0		=		0
#define clr_IT0			IT0		=		0


//**** TH1		8AH **** 
//**** TH0		8BH **** 
//**** TL1		8CH	**** 
//**** TL0		8DH **** 

//**** CKCON	8EH ****
#define set_PWMCKS  CKCON   |= SET_BIT6
#define set_T1M     CKCON   |= SET_BIT4
#define set_T0M     CKCON   |= SET_BIT3
#define set_CLOEN   CKCON   |= SET_BIT1
                            
#define clr_PWMCKS  CKCON   &= ~SET_BIT6
#define clr_T1M     CKCON   &= ~SET_BIT4
#define clr_T0M     CKCON   &= ~SET_BIT3
#define clr_CLOEN   CKCON   &= ~SET_BIT1

//****SFRS		91H ****
#define set_SFRPAGE  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=SET_BIT0;EA=BIT_TMP
#define clr_SFRPAGE  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS&=~SET_BIT0;EA=BIT_TMP

//**** CKDIV		95H ****

//**** SCON		98H ****
#define set_TI      TI    = 1
#define set_RI      RI    = 1

#define clr_TI      TI    = 0
#define clr_RI      RI    = 0

//**** SBUF		99H ****
//**** SBUF_1	9AH ****
                            
//**** CHPCON		9DH ****  TA protect register
#define set_SWRST   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON|=SET_BIT7 ;EA=BIT_TMP
#define set_IAPFF   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON|=SET_BIT6 ;EA=BIT_TMP
#define set_BS      BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON|=SET_BIT1 ;EA=BIT_TMP
#define set_IAPEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON|=SET_BIT0 ;EA=BIT_TMP
       
#define clr_SWRST   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON&=~SET_BIT7;EA=BIT_TMP
#define clr_IAPFF   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON&=~SET_BIT6;EA=BIT_TMP
#define clr_BS      BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON&=~SET_BIT1;EA=BIT_TMP
#define clr_IAPEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON&=~SET_BIT0;EA=BIT_TMP

//**** P2		A0H ****

//**** IAPTRG		A4H	****  TA protect register
#define set_IAPGO   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPTRG|=SET_BIT0 ;EA=BIT_TMP
#define clr_IAPGO   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPTRG&=~SET_BIT0;EA=BIT_TMP

//**** IAPUEN		A5H **** TA protect register
#define set_CFUEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN|=SET_BIT2;EA=BIT_TMP
#define set_LDUEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN|=SET_BIT1;EA=BIT_TMP
#define set_APUEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN|=SET_BIT0;EA=BIT_TMP

#define clr_CFUEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN&=~SET_BIT2;EA=BIT_TMP
#define clr_LDUEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN&=~SET_BIT1;EA=BIT_TMP
#define clr_APUEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN&=~SET_BIT0;EA=BIT_TMP

//**** IAPAL	A6H ****
//**** IAPAH	A7H ****

//**** SADDR		A9H ****


//**** IAPFD	AEH ****

//**** IAPCN	AFH ****
#define set_FOEN    IAPN    |= SET_BIT5
#define set_FCEN    IAPN    |= SET_BIT4
#define set_FCTRL3  IAPN    |= SET_BIT3
#define set_FCTRL2  IAPN    |= SET_BIT2
#define set_FCTRL1  IAPN    |= SET_BIT1
#define set_FCTRL0  IAPN    |= SET_BIT0
                            
#define clr_FOEN    IAPN    &= ~SET_BIT5
#define clr_FCEN    IAPN    &= ~SET_BIT4
#define clr_FCTRL3  IAPN    &= ~SET_BIT3
#define clr_FCTRL2  IAPN    &= ~SET_BIT2
#define clr_FCTRL1  IAPN    &= ~SET_BIT1
#define clr_FCTRL0  IAPN    &= ~SET_BIT0

//**** T3CON		C4H	PAGE0 ****                     
#define set_TR3     T3CON   |= SET_BIT3
#define clr_BRCK    T3CON   &= ~SET_BIT5
