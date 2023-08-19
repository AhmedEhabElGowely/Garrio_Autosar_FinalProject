 /******************************************************************************
 *
 * Module: Systick
 *
 * File Name: Systick_Regs.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Systick Driver Registers
 *
 * Author: Ahmed Ehab El Gowely
 ******************************************************************************/

#ifndef SYSTICK_REGS_H_
#define SYSTICK_REGS_H_

/*****************************************************************************
                    Systick Timer Registers
*****************************************************************************/
#define SYSTICK_CTRL_REG          (*((volatile uint32 *)0xE000E010))
#define SYSTICK_RELOAD_REG        (*((volatile uint32 *)0xE000E014))
#define SYSTICK_CURRENT_REG       (*((volatile uint32 *)0xE000E018))

#define NVIC_SYSTEM_PRI3_REG      (*((volatile uint32 *)0xE000ED20))


#endif
