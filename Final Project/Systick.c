 /******************************************************************************
 *
 * Module: Systick
 *
 * File Name: Systick.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - SysTick Timer Driver.
 *
 * Author: Ahmed Ehab El Gowely
 ******************************************************************************/
#include "Systick.h"
#include "Systick_Regs.h"

/************************************************************************************
                                  Global Variables
************************************************************************************/
TickType g_ticks = 0; 

/************************************************************************************
* Service Name: SysTick_Handler
* Description: SysTick Timer ISR
************************************************************************************/
void SysTick_Handler(void)
{
  g_ticks++;
}

/************************************************************************************
* Service Name: SysTick_Start
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Tick_Time - Time in miliseconds
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the SysTick Timer configuration to count n miliseconds:
*              - Set the Reload value
*              - Enable SysTick Timer with System clock 16Mhz
*              - Enable SysTick Timer Interrupt and set its priority
************************************************************************************/
void SysTick_Start(TimeMsType Tick_Time)
{
    SYSTICK_CTRL_REG    = 0;                         /* Disable the SysTick Timer by Clear the ENABLE Bit */
    SYSTICK_RELOAD_REG  = (16000 * Tick_Time) - 1;         /* Set the Reload value to count n miliseconds */
    SYSTICK_CURRENT_REG = 0;                         /* Clear the Current Register value */
    /* Configure the SysTick Control Register 
     * Enable the SysTick Timer (ENABLE = 1)
     * Enable SysTick Interrupt (INTEN = 1)
     * Choose the clock source to be System Clock (CLK_SRC = 1) */
    SYSTICK_CTRL_REG   |= 0x07;
    /* Assign priority level 3 to the SysTick Interrupt */
    NVIC_SYSTEM_PRI3_REG =  (NVIC_SYSTEM_PRI3_REG & SYSTICK_PRIORITY_MASK) | (SYSTICK_INTERRUPT_PRIORITY << SYSTICK_PRIORITY_BITS_POS);
}

/************************************************************************************
* Service Name: SysTick_Stop
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Stop the SysTick Timer.
************************************************************************************/
void SysTick_Stop(void)
{
    SYSTICK_CTRL_REG = 0; /* Disable the SysTick Timer by Clear the ENABLE Bit */
}
