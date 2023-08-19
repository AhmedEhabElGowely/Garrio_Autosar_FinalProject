/*
 * Port.h
 *
 *  Created on: 16 Aug 2023
 *      Author: Omen
 */

#ifndef PORT_H_
#define PORT_H_

#include "Std_Types.h"
#include "Port_Cfg.h"
#include "Port_Types.h"
#include "Port_LCfg.h"

/*******************************************************************************
*                              Module Definitions                             *
*******************************************************************************/

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3
#define PORT_E 4
#define PORT_F 5

#define PIN_A0	1

#define PIN_A7	8

#define PIN_B0	9

#define PIN_B7	16

#define PIN_C0	17

#define PIN_C7	24

#define PIN_D0	25

#define PIN_D7	32

#define PIN_E0	33

#define PIN_E5	38

#define PIN_F0	39

#define PIN_F4	43




/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
// Description: Initializes the Port Driver module.
void Port_Init( const Port_ConfigType* ConfigPtr );

#if (PortSetPinDirectionApi_0 == STD_ON)
/* Description: Sets the port pin direction */
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
#endif
/* Description: Refreshes port direction */
void Port_RefreshPortDirection( void );

#if (PortVersionInfoApi_0 == STD_ON)
/* Description: Returns the version information of this module */
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif

#if (PortSetPinModeApi_0 == STD_ON)
/* Description: Sets the port pin mode */
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );
#endif



#endif /* PORT_H_ */
