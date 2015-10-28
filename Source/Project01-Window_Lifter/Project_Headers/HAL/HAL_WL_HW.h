/*
 *      File        : WL_HW.h
 *      Created on  : Oct 28, 2015
 *      Authors     : Luis Fernando Alvarez Guerrero, Luis Armando Garcia Valdovinos
 *      Description : Window Lifter System Library
 */

#ifndef WL_HW_H_
#define WL_HW_H_

#include "driver_channel_MPC5606B.h"
#include "stdtypedef.h"
#include "MPC5606B.h"


/* Functions Prototyping */
void Init_GPIO_En(T_SWORD lsw_ch, T_UWORD luw_state);
void WL_HW_Init  (void);

#endif /* WL_HW_H_ */
