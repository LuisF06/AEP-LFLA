/*
 *      File        : WL_HW.c
 *      Created on  : Oct 28, 2015
 *      Authors     : Luis Fernando Alvarez Guerrero, Luis Armando Garcia Valdovinos
 *      Description : Window Lifter System Library
 */

#include "WL_HW.h"

/* PORT Mapping */

/* PORT mapping for LED Bar Indicator */
/* 1 -> Window Portion is Closed      */
/* 0 -> Window Portion is Open        */
enum E_PORT LED_BAR_0  = PA00;  
enum E_PORT LED_BAR_1  = PA01;
enum E_PORT LED_BAR_2  = PA02;
enum E_PORT LED_BAR_3  = PA03;
enum E_PORT LED_BAR_4  = PA04;
enum E_PORT LED_BAR_5  = PA05;
enum E_PORT LED_BAR_6  = PA06;
enum E_PORT LED_BAR_7  = PA07;
enum E_PORT LED_BAR_8  = PA08;
enum E_PORT LED_BAR_9  = PA09;

/* PORT Mapping for Movement Indicators*/
enum E_PORT LED_DOWN   = PA10; 
enum E_PORT LED_UP     = PA11;

/* PORT Mapping for Movement Switches */
enum E_PORT SW_DOWN    = PE00; /* Development Board Switch S1*/
enum E_PORT SW_UP      = PE01; /* Development Board Switch S2*/

/* PORT Mapping for Anti-Pinch Button */
enum E_PORT SW_A_PINCH = PE02; /* Development Board Switch S3*/


void Init_GPIO_En(T_SWORD lsw_ch, T_UWORD luw_state)   
{	/* ------------------------------------------------------------------------
     *  Name                 :	Init_GPIO_En
     *  Description          :  Program the drive enable pin
     *  Parameters           :  T_SWORD ch, T_ULONG state
     *  Return               :  void
     *  -----------------------------------------------------------------------
	 * state = 0x0200 -> enable as output                   
	 * state = 0x0100 -> enable as input                    
	 * state = 0x0103 -> enable as input, Pull - up
	 * state = 0x2000 -> enable as APC "Analog Pad Control" or ANP "Analog Port"
	 */
	 
	SIU.PCR[lsw_ch].R = luw_state;				

}

void WL_HW_Init(void)
{	/* ------------------------------------------------------------------------
 	 *  Name                 :	WL_HW_Init
 	 *  Description          :  Initialise GPIO 
 	 *  Parameters           :  void
 	 *  Return               :  void
 	 *  -----------------------------------------------------------------------
 	 */
	 Init_GPIO_En(LED_BAR_0,  0x0200); /* Program the drive enable pin of LED_BAR_0 (PA0) as output       */
	 Init_GPIO_En(LED_BAR_1,  0x0200); /* Program the drive enable pin of LED_BAR_1 (PA1) as output       */
	 Init_GPIO_En(LED_BAR_2,  0x0200); /* Program the drive enable pin of LED_BAR_2 (PA2) as output       */
	 Init_GPIO_En(LED_BAR_3,  0x0200); /* Program the drive enable pin of LED_BAR_3 (PA3) as output       */
	 Init_GPIO_En(LED_BAR_4,  0x0200); /* Program the drive enable pin of LED_BAR_4 (PA4) as output       */
	 Init_GPIO_En(LED_BAR_5,  0x0200); /* Program the drive enable pin of LED_BAR_5 (PA5) as output       */
	 Init_GPIO_En(LED_BAR_6,  0x0200); /* Program the drive enable pin of LED_BAR_6 (PA6) as output       */
	 Init_GPIO_En(LED_BAR_7,  0x0200); /* Program the drive enable pin of LED_BAR_7 (PA7) as output       */
	 Init_GPIO_En(LED_BAR_8,  0x0200); /* Program the drive enable pin of LED_BAR_8 (PA8) as output       */
	 Init_GPIO_En(LED_BAR_9,  0x0200); /* Program the drive enable pin of LED_BAR_9 (PA9) as output       */
	 
	 Init_GPIO_En(LED_DOWN,   0x0200); /* Program the drive enable pin of LED_DOWN (PA10) as output       */
	 Init_GPIO_En(LED_UP,     0x0200); /* Program the drive enable pin of LED_UP (PA11) as output         */
	 	  	  
	 Init_GPIO_En(SW_DOWN,    0x0100);  /* Program the drive enable pin of SW_DOWN "S1",(PE0) as input    */
	 Init_GPIO_En(SW_UP,      0x0100);  /* Program the drive enable pin of SW_UP "S2",(PE1) as input      */
	 Init_GPIO_En(SW_A_PINCH, 0x0100);  /* Program the drive enable pin of SW_A_PINCH "S3",(PE2) as input */
}





