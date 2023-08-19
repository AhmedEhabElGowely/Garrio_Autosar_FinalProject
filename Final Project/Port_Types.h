/******************************************************************************
*
* Module: Port
*
* File Name: Port_Types.h
*
* Description: Header File for data types for Port_Module
*
* Author: Ahmed Ehab El Gowely
******************************************************************************/

#ifndef PORT_TYPES_H_
#define PORT_TYPES_H_

#include "Std_Types.h"

/*******************************************************************************
*                              Module Data Types                              *
*******************************************************************************/

typedef volatile uint32 * Port_PtrType;

typedef uint8 Port_PinType;

typedef uint8 Port_Type;

typedef enum
{
	PORT_PIN_IN,
	PORT_PIN_OUT

}Port_PinDirectionType;

typedef enum
{
	PORT_PIN_MODE_ADC,
	PORT_PIN_MODE_CAN,
	PORT_PIN_MODE_DIO,
	PORT_PIN_MODE_DIO_GPT,
	PORT_PIN_MODE_DIO_WDG,
	PORT_PIN_MODE_FLEXRAY,
	PORT_PIN_MODE_ICU,
	PORT_PIN_MODE_LIN,
	PORT_PIN_MODE_MEM,
	PORT_PIN_MODE_PWM,
	PORT_PIN_MODE_SPI

}Port_PinModeType;

typedef enum
{
	PORT_PIN_IN_NO_PULL,
	PORT_PIN_IN_PULL_DOWN,
	PORT_PIN_IN_PULL_UP
}Port_InternalResistor;


typedef enum
{

	PORT_PIN_LEVEL_HIGH,
	PORT_PIN_LEVEL_LOW

}Port_PinLevelType;

typedef struct
{
	Port_PinDirectionType PortPinDirection;
	boolean PortPinDirectionChangeable;
	Port_PinType PortPinId;
	Port_PinModeType PortPinInitialMode;
	Port_PinLevelType PortPinLevelValue;
	Port_PinModeType PortPinMode;
	boolean PortPinModeChangeable;
	Port_InternalResistor PortPinInputPullResistor;
}Port_ConfigType;

/*******************************************************************************
*                              Configuration Data Types                              *
*******************************************************************************/

typedef struct
{
	Port_Type PortContainer_startingIndex;
	Port_Type PortContainer_numberOfInstances;

}PortConfigSet_s;

typedef struct
{
	Port_Type PortNumberOfPortPins;
	Port_Type PortPin_startingIndex;
	Port_Type PortPin_numberOfInstances;
}PortContainer_s;

typedef Port_ConfigType PortPin_s;

#endif /* PORT_TYPES_H_ */
