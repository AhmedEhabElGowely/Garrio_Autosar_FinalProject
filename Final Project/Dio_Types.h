/******************************************************************************
*
* Module: Dio
*
* File Name: Dio_Types.h
*
* Description: Header File for data types for DIO_Module
*
* Author: Ahmed Ehab El Gowely
******************************************************************************/

#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_


#include "Std_Types.h"

/*******************************************************************************
*                              Module Data Types                              *
*******************************************************************************/

typedef uint8 Dio_LevelType;

typedef uint8 Dio_PortLevelType;

typedef volatile  uint32 * Dio_PortRegisterType;

typedef uint8 Dio_ChannelType;

typedef uint8 Dio_PortType;

typedef uint8 Dio_Channel_Group_MaskType;

typedef uint8 Dio_Channel_Group_OffsetType;

typedef struct
{
	Dio_Channel_Group_MaskType mask;
	Dio_Channel_Group_OffsetType offset;
	Dio_PortType port;

}Dio_ChannelGroupType;

/*******************************************************************************
*                              Configuration Data Types                              *
*******************************************************************************/

typedef struct{
	Dio_ChannelType DioChannelId;
}DioChannel_s;

typedef struct{
	Dio_PortType DioPortId;
	Dio_ChannelType DioChannel_startingIndex;
	Dio_ChannelType DioChannel_numberOfInstances;
	Dio_ChannelType DioChannelGroup_startingIndex;
	Dio_ChannelType DioChannelGroup_numberOfInstances;
}DioPort_s;

typedef struct{
	Dio_PortType DioPort_startingIndex;
	Dio_PortType DioPort_numberOfInstances;

}DioConfig_s;

typedef struct{
	Dio_Channel_Group_MaskType DioPortMask;
	Dio_Channel_Group_OffsetType DioPortOffset;
	Dio_PortType DioPortId;
}DioChannelGroup_s;


#endif
