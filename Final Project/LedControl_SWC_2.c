#include "Rte_LedControl_SWC_2.h"


#define NO_MOVE 			0x00
#define STALL 				0xFF
#define CLOCKWISE 			0x01
#define COUNTER_CLOCKWISE 	        0x10

#define WHITE_STATE		0
#define RED_STATE		1
#define GREEN_STATE		2
#define BLUE_STATE		3

/*
*Runnable:LedControl_SWC_2_Runnable_1
*Event Type:periodic
*DATA ACCESS:
Rte_IRead_LedControl_SWC_2_Runnable_1_rp_Button_LedCommand_SR_Led_Command_Element_1 (&data)
* DATA READ ACCESS:   SR_Led_Command_Element_1    Rte_Read_rp_Button_LedCommand_SR_Led_Command_Element_1()
*SYNCHRONOUS-SERVER-CALL-POINT:  Rte_Call_rp_ControlLed_CS_ControlLed_Operation_1(Led_Status CS_ControlLed_Operation_1_Argument_1)
*/
Led_Command Command = NO_MOVE , Prev_Command = NO_MOVE;
sint8 State = WHITE_STATE;
void LedControl_SWC_2_Runnable_1(void)
{
	Rte_IRead_LedControl_SWC_2_Runnable_1_rp_Button_LedCommand_SR_Led_Command_Element_1(Command);
	//Rte_Read_rp_Button_LedCommand_SR_Led_Command_Element_1(Command);

	if (Command == NO_MOVE)
	{

	}
	else if ( (Command == STALL) && (Prev_Command != STALL) )
	{
		State = WHITE_STATE;
	}
	else if  ( (Command == CLOCKWISE) && (Prev_Command != CLOCKWISE) )
	{
		State++;
	}
	else if  ( (Command == COUNTER_CLOCKWISE) && (Prev_Command != COUNTER_CLOCKWISE) )
	{
		State--;
	}

	Prev_Command = Command;

	if (State < WHITE_STATE)
	{
		State = BLUE_STATE;
	}
	else if (State > BLUE_STATE)
	{
		State = WHITE_STATE;
	}

	Rte_Call_rp_ControlLed_CS_ControlLed_Operation_1(State);
}


