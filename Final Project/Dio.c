/******************************************************************************
*
* Module: Dio
*
* File Name: Dio.c
*
* Description: Source file for TM4C123GH6PM Microcontroller - Dio Driver
*
* Author: Ahmed Ehab El Gowely
******************************************************************************/

#include "Dio.h"
#include "Dio_Regs.h"
#include "Dio_LCfg.h"

#if (DIO_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
/*******************************************************************************
*                       Global Variables                                    *
*******************************************************************************/

Dio_ChannelGroupType LED_Group = 
{
  .mask = LED_GROUP_MASK,
  .offset = LED_GROUP_OFFSET,
  .port = LED_GROUP_PORT,
} ;



STATIC const  DioPort_s * Port_struct_ptr = DioPort;
STATIC const  DioChannel_s * Channel_struct_ptr = DioChannel;

/*******************************************************************************
*                      Function Definitions                                    *
*******************************************************************************/

/************************************************************************************
* Service Name: Dio_ReadChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to return the value of the specified DIO channel.
************************************************************************************/

Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId )
{
#if (DIO_DEV_ERROR_DETECT == STD_ON)
  
  if (DIO_CHANNEL_SIZE  <= ChannelId)
  {
    /* Check if the used channel is within the valid range */
    Det_ReportError(DIO_MODULE_ID , DIO_INSTANCE_ID , DIO_READ_CHANNEL_SID , DIO_E_PARAM_INVALID_CHANNEL_ID);
    
  }
  else
  {
    /* No Action Required */
  }
#endif
  
  Dio_LevelType Level;
  Dio_PortType Port_Id;
  Dio_ChannelType Mine_Channel_Id;
  Dio_PortRegisterType Port_Register = NULL_PTR;
  
  for(uint8 i = ZERO; i < DIO_PORT_SIZE ;i++ )
  {
    if ( (ChannelId >= Port_struct_ptr[i].DioChannel_startingIndex) && \
      (ChannelId <( Port_struct_ptr[i].DioChannel_startingIndex + Port_struct_ptr[i].DioChannel_numberOfInstances)))
    {
      Port_Id = Port_struct_ptr[i].DioPortId;
      break;
    }
    else
    {
      
    }
  }
  switch (Port_Id)
  {
  case PORT_A:
    Port_Register = &GPIO_PORTA_DATA_REG;
    break;
  case PORT_B:
    Port_Register = &GPIO_PORTB_DATA_REG;
    break;
  case PORT_C:
    Port_Register = &GPIO_PORTC_DATA_REG;
    break;
  case PORT_D:
    Port_Register = &GPIO_PORTD_DATA_REG;
    break;
  case PORT_E:
    Port_Register = &GPIO_PORTE_DATA_REG;
    break;
  case PORT_F:
    Port_Register = &GPIO_PORTF_DATA_REG;
    break;
  }
  Mine_Channel_Id = Channel_struct_ptr[ChannelId].DioChannelId;
  
  Level = ((*Port_Register) & (STD_HIGH<<Mine_Channel_Id)) >> Mine_Channel_Id;
  
  return Level;
}


/************************************************************************************
* Service Name: Dio_WriteChannel
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a channel.
************************************************************************************/
void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
{
#if (DIO_DEV_ERROR_DETECT == STD_ON)
  
  if (DIO_CHANNEL_SIZE  <= ChannelId)
  {
    
    Det_ReportError(DIO_MODULE_ID , DIO_INSTANCE_ID , DIO_WRITE_CHANNEL_SID , DIO_E_PARAM_INVALID_CHANNEL_ID);
    
  }
  else
  {
    /* No Action Required */
  }
#endif
  Dio_PortType Port_Id;
  Dio_ChannelType Mine_Channel_Id;
  Dio_PortRegisterType Port_Register = NULL_PTR;
  for(uint8 i = ZERO; i < DIO_PORT_SIZE ;i++ )
  {
    if ( (ChannelId >= Port_struct_ptr[i].DioChannel_startingIndex) && \
      (ChannelId <( Port_struct_ptr[i].DioChannel_startingIndex + Port_struct_ptr[i].DioChannel_numberOfInstances)))
    {
      Port_Id = Port_struct_ptr[i].DioPortId;
      break;
    }
    
    else
    {
      
    }
  }
  switch (Port_Id)
  {
  case PORT_A:
    Port_Register = &GPIO_PORTA_DATA_REG;
    break;
  case PORT_B:
    Port_Register = &GPIO_PORTB_DATA_REG;
    break;
  case PORT_C:
    Port_Register = &GPIO_PORTC_DATA_REG;
    break;
  case PORT_D:
    Port_Register = &GPIO_PORTD_DATA_REG;
    break;
  case PORT_E:
    Port_Register = &GPIO_PORTE_DATA_REG;
    break;
  case PORT_F:
    Port_Register = &GPIO_PORTF_DATA_REG;
    break;
  }
  Mine_Channel_Id = Channel_struct_ptr[ChannelId].DioChannelId;
  
  *Port_Register = ((*Port_Register) & (STD_LOW<<Mine_Channel_Id)) | (Level<<Mine_Channel_Id) ;
}

/************************************************************************************
* Service Name: Dio_ReadPort
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - ID of DIO Port.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_PortLevelType
* Description: Function which returns the level of all channels of that port.
************************************************************************************/
Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId )
{
  
  Dio_PortLevelType Level;
  Dio_PortRegisterType Port_Register = NULL_PTR;
  
  switch (PortId)
  {
  case PORT_A:
    Port_Register = &GPIO_PORTA_DATA_REG;
    break;
  case PORT_B:
    Port_Register = &GPIO_PORTB_DATA_REG;
    break;
  case PORT_C:
    Port_Register = &GPIO_PORTC_DATA_REG;
    break;
  case PORT_D:
    Port_Register = &GPIO_PORTD_DATA_REG;
    break;
  case PORT_E:
    Port_Register = &GPIO_PORTE_DATA_REG;
    break;
  case PORT_F:
    Port_Register = &GPIO_PORTF_DATA_REG;
    break;
  }
  Level = *Port_Register;
  return Level;
}


/************************************************************************************
* Service Name: Dio_WritePort
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - ID of DIO Port
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a port.
************************************************************************************/
void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level )
{
  
  
  Dio_PortRegisterType Port_Register = NULL_PTR;
  
  switch (PortId)
  {
  case PORT_A:
    Port_Register = &GPIO_PORTA_DATA_REG;
    break;
  case PORT_B:
    Port_Register = &GPIO_PORTB_DATA_REG;
    break;
  case PORT_C:
    Port_Register = &GPIO_PORTC_DATA_REG;
    break;
  case PORT_D:
    Port_Register = &GPIO_PORTD_DATA_REG;
    break;
  case PORT_E:
    Port_Register = &GPIO_PORTE_DATA_REG;
    break;
  case PORT_F:
    Port_Register = &GPIO_PORTF_DATA_REG;
    break;
  }
  *Port_Register = Level;
}

/************************************************************************************
* Service Name: Dio_ReadChannelGroup
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelGroupIdPtr - Pointer to ChannelGroup
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_PortLevelType - Level of a subset of the adjoining bits of a port
* Description: This Service reads a subset of the adjoining bits of a port.
************************************************************************************/
Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr )
{
#if (DIO_DEV_ERROR_DETECT == STD_ON)
  
  if (NULL_PTR == ChannelGroupIdPtr)
  {
    Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_CHANNEL_GROUP_SID,
                    DIO_E_PARAM_CONFIG);
  }
  else
  {
    
  }
#endif
  Dio_PortLevelType Level;
  volatile Dio_PortRegisterType Port_Register;
  
  switch (ChannelGroupIdPtr->port)
  {
  case PORT_A:
    Port_Register = &GPIO_PORTA_DATA_REG;
    break;
  case PORT_B:
    Port_Register = &GPIO_PORTB_DATA_REG;
    break;
  case PORT_C:
    Port_Register = &GPIO_PORTC_DATA_REG;
    break;
  case PORT_D:
    Port_Register = &GPIO_PORTD_DATA_REG;
    break;
  case PORT_E:
    Port_Register = &GPIO_PORTE_DATA_REG;
    break;
  case PORT_F:
    Port_Register = &GPIO_PORTF_DATA_REG;
    break;
  }
  Level = ((*Port_Register) & ChannelGroupIdPtr->mask)>> ChannelGroupIdPtr->offset;
  return Level;
}


/************************************************************************************
* Service Name: Dio_WriteChannelGroup
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelGroupIdPtr - Pointer to ChannelGroup
                   Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Service to set a subset of the adjoining bits of a port to a specified level.
************************************************************************************/
void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level )
{
#if (DIO_DEV_ERROR_DETECT == STD_ON)
  
  if (NULL_PTR == ChannelGroupIdPtr)
  {
    Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_CHANNEL_GROUP_SID,
                    DIO_E_PARAM_CONFIG);
  }
  else
  {
    
  }
#endif
  volatile Dio_PortRegisterType Port_Register;
  
  switch (ChannelGroupIdPtr->port)
  {
  case PORT_A:
    Port_Register = &GPIO_PORTA_DATA_REG;
    break;
  case PORT_B:
    Port_Register = &GPIO_PORTB_DATA_REG;
    break;
  case PORT_C:
    Port_Register = &GPIO_PORTC_DATA_REG;
    break;
  case PORT_D:
    Port_Register = &GPIO_PORTD_DATA_REG;
    break;
  case PORT_E:
    Port_Register = &GPIO_PORTE_DATA_REG;
    break;
  case PORT_F:
    Port_Register = &GPIO_PORTF_DATA_REG;
    break;
  }
  *Port_Register = ((*Port_Register) & ~(ChannelGroupIdPtr->mask) ) | (Level << ChannelGroupIdPtr->offset);
}


#if (DIO_VERSION_INFO_API == STD_ON)
/************************************************************************************
* Service Name: Dio_GetVersionInfo
* Service ID[hex]: 0x12
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): VersionInfo - Pointer to where to store the version information of this module.
* Return value: None
* Description: Function to get the version information of this module.
************************************************************************************/
void Dio_GetVersionInfo( Std_VersionInfoType* VersionInfo )
{
#if (DIO_DEV_ERROR_DETECT == STD_ON)
  
  if (NULL_PTR == ChannelGroupIdPtr)
  {
    Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_GET_VERSION_INFO_SID,
                    DIO_E_PARAM_CONFIG);
  }
  else
  {
    
  }
#endif
  VersionInfo->vendorID = STD_TYPES_VENDOR_ID ;
  VersionInfo->moduleID = DIO_MODULE_ID;
  VersionInfo->sw_major_version = STD_TYPES_AR_RELEASE_MAJOR_VERSION;
  VersionInfo->sw_minor_version = STD_TYPES_AR_RELEASE_MINOR_VERSION;
  VersionInfo->sw_patch_version = STD_TYPES_AR_RELEASE_PATCH_VERSION;
}
#endif

#if (DIO_FLIP_CHANNEL_API == STD_ON)
/************************************************************************************
* Service Name: Dio_FlipChannel
* Service ID[hex]: 0x11
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to flip the level of a channel and return the level of the channel after flip.
************************************************************************************/
Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId)
{
#if (DIO_DEV_ERROR_DETECT == STD_ON)
  
  if (DIO_CHANNEL_SIZE  <= ChannelId)
  {
    
    Det_ReportError(DIO_MODULE_ID , DIO_INSTANCE_ID , DIO_FLIP_CHANNEL_SID  , DIO_E_PARAM_INVALID_CHANNEL_ID);
    
  }
  else
  {
    /* No Action Required */
  }
#endif
  Dio_LevelType Level;
  Dio_PortType Port_Id;
  Dio_ChannelType Mine_Channel_Id;
  volatile Dio_PortRegisterType Port_Register;
  for(uint8 i = 0; i < DIO_PORT_SIZE ;i++ )
  {
    if ( (ChannelId >= Port_struct_ptr[i].DioChannel_startingIndex) && \
      (ChannelId <( Port_struct_ptr[i].DioChannel_startingIndex + Port_struct_ptr[i].DioChannel_numberOfInstances)))
    {
      Port_Id = Port_struct_ptr[i].DioPortId;
      break;
    }
    else
    {
      
    }
  }
  switch (Port_Id)
  {
  case PORT_A:
    Port_Register = &GPIO_PORTA_DATA_REG;
    break;
  case PORT_B:
    Port_Register = &GPIO_PORTB_DATA_REG;
    break;
  case PORT_C:
    Port_Register = &GPIO_PORTC_DATA_REG;
    break;
  case PORT_D:
    Port_Register = &GPIO_PORTD_DATA_REG;
    break;
  case PORT_E:
    Port_Register = &GPIO_PORTE_DATA_REG;
    break;
  case PORT_F:
    Port_Register = &GPIO_PORTF_DATA_REG;
    break;
  }
  Mine_Channel_Id = Channel_struct_ptr[ChannelId].DioChannelId;
  
  *Port_Register = (*Port_Register) ^ (STD_HIGH<<Mine_Channel_Id) ;
  
  Level = ((*Port_Register) & (STD_HIGH<<Mine_Channel_Id)) >> Mine_Channel_Id;
  
  return Level;
}
#endif
