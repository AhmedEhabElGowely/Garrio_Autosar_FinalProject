#ifndef RTE_BUTTONMANAGER_SWC_1_H_
#define RTE_BUTTONMANAGER_SWC_1_H_


#include "Rte.h"


extern void CDD_SWC_1_Get_Reading_1(Button_Status* CS_GetButtonReading_Operation_1_Argument_1);
extern void CDD_SWC_1_Get_Reading_2(Button_Status* CS_GetButtonReading_Operation_2_Argument_1);


#define    Rte_Write_pp_Button_LedCommand_SR_Led_Command_Element_1(data)     (Rte_Write_ButtonManager_Composition_Prototype_pp_Button_LedCommand_SR_Led_Command_Element_1(data))
#define    Rte_Call_rp_ButtonReading_CS_GetButtonReading_Operation_1(CS_GetButtonReading_Operation_1_Argument_1)     (CDD_SWC_1_Get_Reading_1(CS_GetButtonReading_Operation_1_Argument_1))
#define    Rte_Call_rp_ButtonReading_CS_GetButtonReading_Operation_2(CS_GetButtonReading_Operation_2_Argument_1)     (CDD_SWC_1_Get_Reading_2(CS_GetButtonReading_Operation_2_Argument_1))



#endif
