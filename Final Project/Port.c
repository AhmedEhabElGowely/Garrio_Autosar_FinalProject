/******************************************************************************
*
* Module: Port
*
* File Name: Port.c
*
* Description: Source file for TM4C123GH6PM Microcontroller - Port Driver
*
* Author: Ahmed Ehab El Gowely
******************************************************************************/


#include "Port.h"
#include "Port_Regs.h"
#include "Port_LCfg.h"
#include "Common_Macros.h"

#if (PortDevErrorDetect_0 == STD_ON)
#include "Det.h"
#endif

/******************************************************************************
*                                     Macros                                 *
******************************************************************************/
#define ACCESSS_REG(BASE_ADDRESS , OFFSET) 	( *(volatile uint32 *) ( (volatile uint8 *)(BASE_ADDRESS) + (OFFSET) ) )
#define INSERT_BIT (ACCESS , BIT , BIT_NO) ( (ACCESS) & (~((BIT) << (BIT_NO))) ) | ((BIT) <<(BIT_NO))

/*******************************************************************************
*                              Function Definitions                             *
*******************************************************************************/

/************************************************************************************
* Service Name: Port_Init
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr - Pointer to Link_time configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the Port Driver module.
************************************************************************************/

void Port_Init( const Port_ConfigType* ConfigPtr )
{
	Port_PtrType Port_Ptr = NULL_PTR;
	Port_PinType Pin_Id;
	Port_Type Port_Id;
	for (int i = 38; i< PORT_PIN_SIZE ; i++)
	{

		if ( ( (ConfigPtr[i].PortPinId) >= PIN_A0 ) && ( (ConfigPtr[i].PortPinId) <= PIN_A7 ) )
		{

		}
		else if ( ( (ConfigPtr[i].PortPinId) >= PIN_B0 ) && ( (ConfigPtr[i].PortPinId) <= PIN_B7 ) )
		{
 
		}
		else if ( ( (ConfigPtr[i].PortPinId) >= PIN_C0 ) && ( (ConfigPtr[i].PortPinId) <= PIN_C7 ) )
		{

		}
		else if ( ( (ConfigPtr[i].PortPinId) >= PIN_D0 ) && ( (ConfigPtr[i].PortPinId) <= PIN_D7 ) )
		{

		}
		else if ( ( (ConfigPtr[i].PortPinId) >= PIN_E0 ) && ( (ConfigPtr[i].PortPinId) <= PIN_E5 ) )
		{

		}
		else if ( ( (ConfigPtr[i].PortPinId) >= PIN_F0 ) && ( (ConfigPtr[i].PortPinId) <= PIN_F4 ) )
		{
			Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS;
			Port_Id = PORT_F;
			Pin_Id= ( (ConfigPtr[i].PortPinId) - PIN_F0 );
		}

		SET_BIT(SYSCTL_REGCGC2_REG,Port_Id);
		while ( BIT_IS_CLEAR(SYSCTL_REGCGC2_REG,Port_Id) );
		if ((ConfigPtr[i].PortPinId) == PIN_F0)
		{
			ACCESSS_REG(Port_Ptr , PORT_LOCK_REG_OFFSET ) = UNLOCK;
		}
		else
		{

		}
		SET_BIT(ACCESSS_REG(Port_Ptr , PORT_COMMIT_REG_OFFSET ),Pin_Id) ;


		if (ConfigPtr[i].PortPinInitialMode == PORT_PIN_MODE_DIO)
		{
			CLEAR_BIT( ACCESSS_REG(Port_Ptr , PORT_ANALOG_MODE_SEL_REG_OFFSET) , Pin_Id);
			CLEAR_BIT( ACCESSS_REG(Port_Ptr , PORT_ALT_FUNC_REG_OFFSET) , Pin_Id);
			ACCESSS_REG(Port_Ptr , PORT_CTL_REG_OFFSET) = ACCESSS_REG(Port_Ptr , PORT_CTL_REG_OFFSET) & ( ~(0x0F << (Pin_Id *4)) );
			SET_BIT( ACCESSS_REG(Port_Ptr , PORT_DIGITAL_ENABLE_REG_OFFSET) , Pin_Id);
                        
                         //SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Pin_Id);//test
                        
                        
			if (ConfigPtr[i].PortPinDirection == PORT_PIN_OUT )
			{
				SET_BIT(ACCESSS_REG(Port_Ptr , PORT_DIR_REG_OFFSET ),Pin_Id);
				if (ConfigPtr[i].PortPinLevelValue == PORT_PIN_LEVEL_HIGH)
				{
					SET_BIT( ACCESSS_REG(Port_Ptr , PORT_DATA_REG_OFFSET) , Pin_Id);
				}
				else if (ConfigPtr[i].PortPinLevelValue == PORT_PIN_LEVEL_LOW)
				{
					CLEAR_BIT( ACCESSS_REG(Port_Ptr , PORT_DATA_REG_OFFSET) , Pin_Id);
				}
			}
			else if (ConfigPtr[i].PortPinDirection == PORT_PIN_IN )
			{
				CLEAR_BIT(ACCESSS_REG(Port_Ptr , PORT_DIR_REG_OFFSET ),Pin_Id);
				if (ConfigPtr[i].PortPinInputPullResistor == PORT_PIN_IN_NO_PULL)
				{
					CLEAR_BIT(ACCESSS_REG(Port_Ptr , PORT_PULL_UP_REG_OFFSET ),Pin_Id);
					CLEAR_BIT(ACCESSS_REG(Port_Ptr , PORT_PULL_DOWN_REG_OFFSET ),Pin_Id);
				}
				else if(ConfigPtr[i].PortPinInputPullResistor == PORT_PIN_IN_PULL_DOWN)
				{
					CLEAR_BIT(ACCESSS_REG(Port_Ptr , PORT_PULL_UP_REG_OFFSET ),Pin_Id);
					SET_BIT(ACCESSS_REG(Port_Ptr , PORT_PULL_DOWN_REG_OFFSET ),Pin_Id);
				}
				else if(ConfigPtr[i].PortPinInputPullResistor == PORT_PIN_IN_PULL_UP)
				{
					SET_BIT(ACCESSS_REG(Port_Ptr , PORT_PULL_UP_REG_OFFSET ),Pin_Id);
					CLEAR_BIT(ACCESSS_REG(Port_Ptr , PORT_PULL_DOWN_REG_OFFSET ),Pin_Id);
				}
			}
		}
		else if (0)
		{
			// other modes
		}

	}
}


#if (PortSetPinDirectionApi_0 == STD_ON)
/************************************************************************************
* Service Name: Port_SetPinDirection
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number
*                  Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin direction.
************************************************************************************/
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
{

}
#endif

/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Refreshes port direction.
************************************************************************************/
void Port_RefreshPortDirection( void )
{

}

#if (PortVersionInfoApi_0 == STD_ON)
/************************************************************************************
* Service Name: Port_GetVersionInfo
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version information of this module.
* Return value: None
* Description: Returns the version information of this module.
************************************************************************************/
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
{

}
#endif


#if (PortSetPinModeApi_0 == STD_ON)
/************************************************************************************
* Service Name: Port_SetPinMode
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number
*                  Mode - New Port Pin mode to be set on port pin.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin mode.
************************************************************************************/
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{

}
#endif
