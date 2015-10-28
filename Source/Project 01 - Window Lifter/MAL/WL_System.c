/*
 *      File        : WL_System.c
 *      Created on  : Oct 27, 2015
 *      Authors     : Luis Fernando Alvarez Guerrero, Luis Armando Garcia Valdovinos
 *      Description : Window Lifter System Library
 */
#include "WL_System.h"

void WL_initModesAndClock(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_initModesandClock  
	*  Description          :  Initialise Running Modes and System Clock
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/

  	ME.MER.R = 0x0000001D;               /* Enable DRUN, RUN0, SAFE, RESET modes              */
    
  	/* Initialize PLL before turning it on:              */
   	CGM.FMPLL_CR.R = 0x02400100;         /* 8 MHz xtal: Set PLL0 to 64 MHz                    */   
   	
   	ME.RUN[0].R = 0x001F0074;            /* RUN0 cfg: 16MHzIRCON,OSC0ON,PLL0ON,syclk=PLL0     */
   	
   	ME.RUNPC[1].R = 0x00000010; 	     /* Peri. Cfg. 1 settings: only run in RUN0 mode      */
   	
   	ME.PCTL[PA00].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_BAR_0             */
   	ME.PCTL[PA01].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_BAR_1             */
   	ME.PCTL[PA02].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_BAR_2             */
   	ME.PCTL[PA03].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_BAR_3             */
   	ME.PCTL[PA04].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_BAR_4             */
   	ME.PCTL[PA05].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_BAR_5             */
   	ME.PCTL[PA06].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_BAR_6             */
   	ME.PCTL[PA07].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_BAR_7             */
   	ME.PCTL[PA08].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_BAR_8             */
   	ME.PCTL[PA09].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_BAR_9             */
   	ME.PCTL[PA10].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_DOWN              */
   	ME.PCTL[PA11].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_UP                */
   	ME.PCTL[PE00].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for SW_DOWN               */
   	ME.PCTL[PE01].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for SW_UP                 */
   	ME.PCTL[PE02].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for SW_A_PINCH            */
   	                                         
   	/* Mode Transition to enter RUN0 mode:               */
   	ME.MCTL.R = 0x40005AF0;              /* Enter RUN0 Mode & Key                             */
   	ME.MCTL.R = 0x4000A50F;              /* Enter RUN0 Mode & Inverted Key                    */  
   	while (ME.GS.B.S_MTRANS) {}          /* Wait for mode transition to complete              */    
    
   	/* Note: could wait here using timer and/or I_TC IRQ */
   	while(ME.GS.B.S_CURRENTMODE != 4) {} /* Verify RUN0 is the current mode                   */
  
  }

void WL_STM_init(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_STM_init  
	*  Description          :  Initialise System Timer Module
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/

    STM.CR.B.TEN        = 0x0;		 /* Disable System Timer Module                              */
    STM.CR.B.FRZ        = 0x1;       /* Enable Freeze for debugging purposes                    */
    STM.CR.B.CPS        = 0;         /* Configure Counter Prescaler, Counter Prescaler is 1     */
    STM.CH[0].CMP.R     = 0xFA00;    /* Compare with 1 millisecond - 64 Mhz clock,              */      
    STM.CH[0].CCR.B.CEN = 0x1;       /* System Timer Channel 0: ENABLE                          */
    STM.CR.B.TEN        = 0x1;       /* Enable System Timer Module                              */
}

void WL_EIRQ_Init(void)
{ 	/* ------------------------------------------------------------------------
 	 *  Name                 :	WL_EIRQ_Init
 	 *  Description          :  Initialise External Interruptions
 	 *  Parameters           :  void
 	 *  Return               :  void
 	 *  -----------------------------------------------------------------------
 	 */
		SIU.PCR[PE02].R    = 0x0100;	/* Pin PE[2]- EIRQ21 configured as GPIO   */
		SIU.IFEER.B.IFEE21 = 1;	        /* Enable falling edge event on EIRQ21    */
		SIU.IRER.B.IRE21   = 1;		    /* Enable interrupt Results EIRQ21        */
}

void WL_System_Init(void)
{ 	/* ------------------------------------------------------------------------
	 *  Name                 :	WL_System_init
	 *  Description          :  Initialise System
	 *  Parameters           :  void
	 *  Return               :  void
	 *  -----------------------------------------------------------------------
	 */
     WL_initModesAndClock();
	 WL_STM_init();
	 WL_EIRQ_Init();
}



