 /******************************************************************************
 *
 * Module: Systick
 *
 * File Name: Systick.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - SysTick Timer Driver.
 *
 * Author: Ahmed Ehab El Gowely
 ******************************************************************************/
#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "Std_Types.h"

/*******************************************************************************
*                              Module Data Types                              *
*******************************************************************************/
typedef uint8 TickType;
typedef uint32 TimeMsType;

/*******************************************************************************
*                              Module Definitions                             *
*******************************************************************************/

#define SYSTICK_PRIORITY_MASK  0x1FFFFFFF
#define SYSTICK_INTERRUPT_PRIORITY  3
#define SYSTICK_PRIORITY_BITS_POS   29

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern TickType g_ticks; 


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
void SysTick_Start(TimeMsType Tick_Time);

void SysTick_Stop(void);


#endif