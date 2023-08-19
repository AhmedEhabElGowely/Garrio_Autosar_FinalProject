 /******************************************************************************
 *
 * Module: Main
 *
 * File Name: main.c
 *
 * Description:  Main File
 *
 * Author: Ahmed Ehab El Gowely
 ******************************************************************************/

#include "Systick.h"

/*******************************************************************************
*                              Module Definitions                             *
*******************************************************************************/

#define Enable_Interrupts()    __asm("CPSIE I")
#define Wait_For_Interrupt()     __asm("WFI")

#define TICK_TIME               ((TimeMsType)5)

#define ZERO    (0U)
#define ONE     (1U)

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
extern void CDD_SWC_1_Init_Runnable(void);
extern void ButtonManager_SWC_1_Runnable_1(void);
extern void LedControl_SWC_2_Runnable_1(void);

/*******************************************************************************
 *                       Global Variables                                    *
 *******************************************************************************/

uint8 g_run_flag = ZERO;

/*******************************************************************************
 *                               Main Function                                 *
 *******************************************************************************/
int main()
{
  SysTick_Start(TICK_TIME);
  Enable_Interrupts();
  CDD_SWC_1_Init_Runnable();
  for(;;)
  {
    
    if (g_ticks == ZERO & g_run_flag == ZERO)
    {
      //Call this function once each 10ms
      ButtonManager_SWC_1_Runnable_1();
      g_run_flag++;
    }
    else if (g_ticks == ONE & g_run_flag == ONE)
    {
      //Call this function once each 10ms
      LedControl_SWC_2_Runnable_1();
      g_run_flag++;
      
    }
    else 
    {
      Wait_For_Interrupt();
    }
    if (g_ticks > ONE)
    {
      g_ticks = ZERO;
      g_run_flag = ZERO;
    }
  }
  return ZERO;
}
