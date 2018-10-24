/*******************************************************************************
* File Name: POT_L.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_POT_L_H) /* Pins POT_L_H */
#define CY_PINS_POT_L_H

#include "cytypes.h"
#include "cyfitter.h"
#include "POT_L_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    POT_L_Write(uint8 value) ;
void    POT_L_SetDriveMode(uint8 mode) ;
uint8   POT_L_ReadDataReg(void) ;
uint8   POT_L_Read(void) ;
uint8   POT_L_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define POT_L_DRIVE_MODE_BITS        (3)
#define POT_L_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - POT_L_DRIVE_MODE_BITS))

#define POT_L_DM_ALG_HIZ         (0x00u)
#define POT_L_DM_DIG_HIZ         (0x01u)
#define POT_L_DM_RES_UP          (0x02u)
#define POT_L_DM_RES_DWN         (0x03u)
#define POT_L_DM_OD_LO           (0x04u)
#define POT_L_DM_OD_HI           (0x05u)
#define POT_L_DM_STRONG          (0x06u)
#define POT_L_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define POT_L_MASK               POT_L__MASK
#define POT_L_SHIFT              POT_L__SHIFT
#define POT_L_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define POT_L_PS                     (* (reg32 *) POT_L__PS)
/* Port Configuration */
#define POT_L_PC                     (* (reg32 *) POT_L__PC)
/* Data Register */
#define POT_L_DR                     (* (reg32 *) POT_L__DR)
/* Input Buffer Disable Override */
#define POT_L_INP_DIS                (* (reg32 *) POT_L__PC2)


#if defined(POT_L__INTSTAT)  /* Interrupt Registers */

    #define POT_L_INTSTAT                (* (reg32 *) POT_L__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define POT_L_DRIVE_MODE_SHIFT       (0x00u)
#define POT_L_DRIVE_MODE_MASK        (0x07u << POT_L_DRIVE_MODE_SHIFT)


#endif /* End Pins POT_L_H */


/* [] END OF FILE */
