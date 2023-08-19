#ifndef RTE_LEDCONTROL_SWC_2_H_
#define RTE_LEDCONTROL_SWC_2_H_


#include "Rte.h"


extern void CDD_SWC_1_ControlLed(Led_Status CS_ControlLed_Operation_1_Argument_1);


#define    Rte_Call_rp_ControlLed_CS_ControlLed_Operation_1(CS_ControlLed_Operation_1_Argument_1)     (CDD_SWC_1_ControlLed(CS_ControlLed_Operation_1_Argument_1))
//#define    Rte_IRead_LedControl_SWC_2_Runnable_1_rp_Button_LedCommand_SR_Led_Command_Element_1 (&data)     (Rte_IRead_SR_Led_Command_Element_1_LedControl_Composition_Prototype_rp_Button_LedCommand_LedControl_SWC_2_Runnable_1 (&data))
#define    Rte_IRead_LedControl_SWC_2_Runnable_1_rp_Button_LedCommand_SR_Led_Command_Element_1(data)     (Rte_IRead_SR_Led_Command_Element_1_LedControl_Composition_Prototype_rp_Button_LedCommand_LedControl_SWC_2_Runnable_1 (&data))


#endif
