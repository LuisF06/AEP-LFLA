/*
 *      File        : MAL_WL_System.c
 *      Created on  : Oct 28, 2015
 *      Authors     : Luis Fernando Alvarez Guerrero. Luis Armando Garcia Valdovinos.
 *      Description : Window Lifter System Library
 */
#include "MAL\MAL_WL_System.h"

void WL_initModesAndClock(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_initModesandClock  
	*  Description          :  Initialize Running Modes and System Clock
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/
  	ME.MER.R = 0x0000001D;               /* Enable DRUN, RUN0, SAFE, RESET modes              */
  	/* Initialize PLL before turning it on:              */
   	CGM.FMPLL_CR.R = 0x02400100;         /* 8 MHz xtal: Set PLL0 to 64 MHz                    */   
   	ME.RUN[0].R = 0x001F0074;            /* RUN0 cfg: 16MHzIRCON,OSC0ON,PLL0ON,syclk=PLL0     */
   	ME.RUNPC[1].R = 0x00000010; 	     /* Peri. Cfg. 1 settings: only run in RUN0 mode      */
   	/* Mode Transition to enter RUN0 mode:               */
   	ME.MCTL.R = 0x40005AF0;              /* Enter RUN0 Mode & Key                             */
   	ME.MCTL.R = 0x4000A50F;              /* Enter RUN0 Mode & Inverted Key                    */  
   	while (ME.GS.B.S_MTRANS) {}          /* Wait for mode transition to complete              */    
	/* Note: could wait here using timer and/or I_TC IRQ */
   	while(ME.GS.B.S_CURRENTMODE != 4) {} /* Verify RUN0 is the current mode                   */
}

void WL_System_Init(void)
{ 	/* ------------------------------------------------------------------------
	 *  Name                 :	WL_System_init
	 *  Description          :  Initialize System
	 *  Parameters           :  void
	 *  Return               :  void
	 *  -----------------------------------------------------------------------
	 */
     WL_initModesAndClock();
}



