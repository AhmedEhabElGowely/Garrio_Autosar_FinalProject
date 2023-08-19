#include "Rte_ButtonManager_SWC_1.h"


#define PRESSED         STD_LOW
#define UNPRESSED       STD_HIGH

#define NO_MOVE                 0x00
#define STALL                   0xFF
#define CLOCKWISE               0x01
#define COUNTER_CLOCKWISE       0x10

#define STATES_SIZE             4

#define STATE_1_INDEX           0
#define STATE_2_INDEX           1
#define STATE_3_INDEX           2
#define STATE_4_INDEX           3

#define ZERO    (0U)
#define TWO     (2U)
/*
*Runnable:ButtonManager_SWC_1_Runnable_1
*Event Type:periodic
*DATA ACCESS:
* DATA SEND POINT:  Rte_Write_pp_Button_LedCommand_SR_Led_Command_Element_1(Led_Command SR_Led_Command_Element_1)
*SYNCHRONOUS-SERVER-CALL-POINT:  Rte_Call_rp_ButtonReading_CS_GetButtonReading_Operation_1(Button_Status CS_GetButtonReading_Operation_1_Argument_1)
*SYNCHRONOUS-SERVER-CALL-POINT:  Rte_Call_rp_ButtonReading_CS_GetButtonReading_Operation_2(Button_Status CS_GetButtonReading_Operation_2_Argument_1)
*/
Button_Status CW_Button = UNPRESSED , CCW_Button = UNPRESSED , Debounce_flag[STATES_SIZE] = {ZERO};
void ButtonManager_SWC_1_Runnable_1(void)
{
  Rte_Call_rp_ButtonReading_CS_GetButtonReading_Operation_1(&CW_Button);
  Rte_Call_rp_ButtonReading_CS_GetButtonReading_Operation_2(&CCW_Button);
  
  if ( (CW_Button == UNPRESSED) && (CCW_Button  == UNPRESSED))
  {
    Debounce_flag[STATE_1_INDEX]++;
    
    Debounce_flag[STATE_2_INDEX] = ZERO;
    Debounce_flag[STATE_3_INDEX] = ZERO;
    Debounce_flag[STATE_4_INDEX] = ZERO;
    if ( ((CW_Button == UNPRESSED) && (CCW_Button  == UNPRESSED)) && (Debounce_flag[STATE_1_INDEX] == TWO) )
    {
      Rte_Write_pp_Button_LedCommand_SR_Led_Command_Element_1(NO_MOVE);
      Debounce_flag[STATE_1_INDEX] = ZERO;
    }
    else
    {
      return;
    }
  }
  else if ( (CW_Button == PRESSED) && (CCW_Button  == UNPRESSED))
  {
    Debounce_flag[STATE_2_INDEX]++;
    Debounce_flag[STATE_1_INDEX] = ZERO;
    Debounce_flag[STATE_3_INDEX] = ZERO;
    Debounce_flag[STATE_4_INDEX] = ZERO;
    if ( ( (CW_Button == PRESSED) && (CCW_Button  == UNPRESSED)) && (Debounce_flag[STATE_2_INDEX] == TWO) )
    {
      Rte_Write_pp_Button_LedCommand_SR_Led_Command_Element_1(CLOCKWISE);
      Debounce_flag[STATE_2_INDEX] = ZERO;
    }
    else
    {
      return;
    }
  }
  else if ( (CW_Button == UNPRESSED) && (CCW_Button  == PRESSED))
  {
    Debounce_flag[STATE_3_INDEX]++;
    Debounce_flag[STATE_2_INDEX] = ZERO;
    Debounce_flag[STATE_1_INDEX] = ZERO;
    Debounce_flag[STATE_4_INDEX] = ZERO;
    if ( ( (CW_Button == UNPRESSED) && (CCW_Button  == PRESSED)) && (Debounce_flag[STATE_3_INDEX] == TWO) )
    {
      Rte_Write_pp_Button_LedCommand_SR_Led_Command_Element_1(COUNTER_CLOCKWISE);
      Debounce_flag[STATE_3_INDEX] = ZERO;
    }
    else
    {
      return;
    }
    
  }
  else if ( (CW_Button == PRESSED) && (CCW_Button  == PRESSED))
  {
    Debounce_flag[STATE_4_INDEX]++;
    Debounce_flag[STATE_2_INDEX] = ZERO;
    Debounce_flag[STATE_3_INDEX] = ZERO;
    Debounce_flag[STATE_1_INDEX] = ZERO;
    if ( ( (CW_Button == PRESSED) && (CCW_Button  == PRESSED)) && (Debounce_flag[STATE_4_INDEX] == TWO) )
    {
      Rte_Write_pp_Button_LedCommand_SR_Led_Command_Element_1 (STALL);
      Debounce_flag[STATE_4_INDEX] = ZERO;
    }
    else
    {
      return;
    }
    
    
  }
  
}


