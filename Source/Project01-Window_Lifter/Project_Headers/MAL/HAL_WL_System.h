/*
 *      File        : WL_System.h
 *      Created on  : Oct 27, 2015
 *      Authors     : Luis Fernando Alvarez Guerrero, Luis Armando Garcia Valdovinos
 *      Description : Window Lifter System Library
 */

#ifndef WL_SYSTEM_H_
#define WL_SYSTEM_H_

#include "MPC5606B.h"
#include "stdtypedef.h"
#include "driver_channel_MPC5606B.h"

void WL_initModesAndClock(void);
void WL_STM_init(void);
void WL_EIRQ_Init(void);
void WL_System_Init(void);

#endif /* WL_SYSTEM_H_ */
