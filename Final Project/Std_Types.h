 /******************************************************************************
 *
 * Module: Common - Standard Types
 *
 * File Name: Std_Types.h
 *
 * Description: Standard Autosar Types
 *
 * Author: Ahmed Ehab El Gowely
 *
 *******************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


#include "Platform_Types.h"
#include "Compiler.h"
typedef struct
{
  uint16  vendorID;
  uint16  moduleID;
  uint8 sw_major_version;
  uint8 sw_minor_version;
  uint8 sw_patch_version;
} Std_VersionInfoType;

typedef uint8  Std_ReturnType;

#define STD_HIGH        0x01U       /* Standard HIGH */
#define STD_LOW         0x00U       /* Standard LOW */

#define STD_ACTIVE      0x01U       /* Logical state active */
#define STD_IDLE        0x00U       /* Logical state idle */

#define STD_ON          0x01U       /* Standard ON */
#define STD_OFF         0x00U       /* Standard OFF */

#define E_OK            ((Std_ReturnType)0x00U)      /* Function Return OK */
#define E_NOT_OK        ((Std_ReturnType)0x01U)      /* Function Return NOT OK */

#define LOGIC_HIGH              (1u)
#define LOGIC_LOW               (0u)


#endif
