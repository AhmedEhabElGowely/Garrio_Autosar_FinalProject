/******************************************************************************
*
* Module: Dio
*
* File Name: Dio.h
*
* Description: Header file for TM4C123GH6PM Microcontroller - Dio Driver
*
* Author: Ahmed Ehab El Gowely
******************************************************************************/
#ifndef DIO_H_
#define DIO_H_

#include "Std_Types.h"
#include "Dio_Cfg.h"
#include "Dio_LCfg.h"
#include "Dio_Types.h"


#define DIO_MODULE_ID 				(120U)
#define DIO_INSTANCE_ID 			(0U)
/* Id for the company in the AUTOSAR
 * for example Ahmed Ehab El Gowely's ID = 1000 :) */
#define STD_TYPES_VENDOR_ID                                  (1000U)

/*
 * AUTOSAR Version 4.3.1
 */
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION                   (4U)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION                   (3U)
#define STD_TYPES_AR_RELEASE_PATCH_VERSION                   (1U)

/*******************************************************************************
*                              Module Definitions                             *
*******************************************************************************/

#define Button2_ID       (0U)
#define RedLed_ID        (1U)
#define BlueLed_ID       (2U)
#define GreenLed_ID      (3U)
#define Button1_ID       (4U)

#define PORT_A           (0U)
#define PORT_B           (1U)
#define PORT_C           (2U)
#define PORT_D           (3U)
#define PORT_E           (4U)
#define PORT_F           (5U)

#define LED_GROUP_MASK   (14U)
#define LED_GROUP_OFFSET (1U)
#define LED_GROUP_PORT   PORT_F


#define ZERO              (0U)

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern structure to be used by Dio and other modules */
extern Dio_ChannelGroupType LED_Group;


/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for DIO read Channel */
#define DIO_READ_CHANNEL_SID           (uint8)0x00

/* Service ID for DIO write Channel */
#define DIO_WRITE_CHANNEL_SID          (uint8)0x01

/* Service ID for DIO read Port */
#define DIO_READ_PORT_SID              (uint8)0x02

/* Service ID for DIO write Port */
#define DIO_WRITE_PORT_SID             (uint8)0x03

/* Service ID for DIO read Channel Group */
#define DIO_READ_CHANNEL_GROUP_SID     (uint8)0x04

/* Service ID for DIO write Channel Group */
#define DIO_WRITE_CHANNEL_GROUP_SID    (uint8)0x05

/* Service ID for DIO GetVersionInfo */
#define DIO_GET_VERSION_INFO_SID       (uint8)0x12

/* Service ID for DIO flip Channel */
#define DIO_FLIP_CHANNEL_SID           (uint8)0x11

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report Invalid Channel */
#define DIO_E_PARAM_INVALID_CHANNEL_ID (uint8)0x0A

/* Dio_Init API service called with NULL pointer parameter */
#define DIO_E_PARAM_CONFIG             (uint8)0x10

/* DET code to report Invalid Port */
#define DIO_E_PARAM_INVALID_PORT_ID    (uint8)0x14

/* DET code to report Invalid Channel Group */
#define DIO_E_PARAM_INVALID_GROUP      (uint8)0x1F

/*
 * The API service shall return immediately without any further action,
 * beside reporting this development error.
 */
#define DIO_E_PARAM_POINTER             (uint8)0x20


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Function for DIO read Channel API */
Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId );

/* Function for DIO write Channel API */
void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level );

/* Function for DIO read Port API */
Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId );

/* Function for DIO write Port API */
void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level );

/* Function for DIO read Channel Group API */
Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr );

/* Function for DIO write Channel Group API */
void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level );


#if (DIO_VERSION_INFO_API == STD_ON)
/* Function for DIO Get Version Info API */
void Dio_GetVersionInfo( Std_VersionInfoType* VersionInfo );
#endif

#if (DIO_FLIP_CHANNEL_API == STD_ON)
/* Function for DIO flip channel API */
Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId);
#endif


#endif /* DIO_H */





