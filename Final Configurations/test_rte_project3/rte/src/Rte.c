#include "Rte_Type.h"


Led_Command ButtonManager_Composition_Prototype_pp_Button_LedCommand_SR_Led_Command_Element_1 = 0;


Std_ReturnType Rte_Write_ButtonManager_Composition_Prototype_pp_Button_LedCommand_SR_Led_Command_Element_1(Led_Command data)
{
     ButtonManager_Composition_Prototype_pp_Button_LedCommand_SR_Led_Command_Element_1 = data;
   return E_OK;
}

Std_ReturnType Rte_Read_LedControl_Composition_Prototype_rp_Button_LedCommand_SR_Led_Command_Element_1(Led_Command* data)
{
   Std_ReturnType return_value = E_NOT_OK;
   if (NULL_PTR == data){
         return_value = E_NOT_OK;
   }

   else{
      *data = ButtonManager_Composition_Prototype_pp_Button_LedCommand_SR_Led_Command_Element_1;
      return_value = E_OK;
   }
   return return_value;
}



