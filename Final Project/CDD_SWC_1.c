#include "Rte_CDD_SWC_1.h"

#include "Dio.h"
#include "Port.h"

#define PRESSED STD_LOW
#define UNPRESSED STD_HIGH


#define WHITE_STATE		0U
#define RED_STATE		1U
#define GREEN_STATE		2U
#define BLUE_STATE		3U

#define WHITE_COMMAND 	0x07
#define RED_COMMAND 	0x01
#define GREEN_COMMAND	0x04
#define BLUE_COMMAND	0x02
/*
*Runnable:CDD_SWC_1_Init_Runnable
*Event Type:init
*DATA ACCESS:
*/
void CDD_SWC_1_Init_Runnable(void)
{
	Port_Init(PortPin);

}



/*
*Runnable:CDD_SWC_1_Get_Reading_1
*Event Type:operation invoked event
*DATA ACCESS:
*/
void CDD_SWC_1_Get_Reading_1(Button_Status* CS_GetButtonReading_Operation_1_Argument_1){

	*CS_GetButtonReading_Operation_1_Argument_1 = Dio_ReadChannel(Button1_ID);
}



/*
*Runnable:CDD_SWC_1_Get_Reading_2
*Event Type:operation invoked event
*DATA ACCESS:
*/
void CDD_SWC_1_Get_Reading_2(Button_Status* CS_GetButtonReading_Operation_2_Argument_1){

	*CS_GetButtonReading_Operation_2_Argument_1 = Dio_ReadChannel(Button2_ID);

}



/*
*Runnable:CDD_SWC_1_ControlLed
*Event Type:operation invoked event
*DATA ACCESS:
*/
void CDD_SWC_1_ControlLed(Led_Status CS_ControlLed_Operation_1_Argument_1)
{
	switch (CS_ControlLed_Operation_1_Argument_1)
	{
	case WHITE_STATE:
		Dio_WriteChannelGroup(&LED_Group ,WHITE_COMMAND);
		break;
	case RED_STATE:
		Dio_WriteChannelGroup(&LED_Group ,RED_COMMAND);
		break;
	case GREEN_STATE:
		Dio_WriteChannelGroup(&LED_Group ,GREEN_COMMAND);
		break;
	case BLUE_STATE:
		Dio_WriteChannelGroup(&LED_Group ,BLUE_COMMAND);
		break;
	}

}


