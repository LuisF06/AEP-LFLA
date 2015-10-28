#include "MPC5606B.h"
#include "stdtypedef.h"
#include "IntcInterrupts.h"
#include "WL_System.h"
#include "WL_HW.h"



int main(void) {
  volatile int i = 0;

  WL_System_Init();
  WL_HW_Init();
  


  /* Loop forever */
  for (;;) {
    i++;
  }
}



