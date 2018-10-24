/*******************************************************************************
* File Name: POT_R.h  
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

#if !defined(CY_PINS_POT_R_H) /* Pins POT_R_H */
#define CY_PINS_POT_R_H

#include "cytypes.h"
#include "cyfitter.h"
#include "POT_R_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    POT_R_Write(uint8 value) ;
void    POT_R_SetDriveMode(uint8 mode) ;
uint8   POT_R_ReadDataReg(void) ;
uint8   POT_R_Read(void) ;
uint8   POT_R_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define POT_R_DRIVE_MODE_BITS        (3)
#define POT_R_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - POT_R_DRIVE_MODE_BITS))

#define POT_R_DM_ALG_HIZ         (0x00u)
#define POT_R_DM_DIG_HIZ         (0x01u)
#define POT_R_DM_RES_UP          (0x02u)
#define POT_R_DM_RES_DWN         (0x03u)
#define POT_R_DM_OD_LO           (0x04u)
#define POT_R_DM_OD_HI           (0x05u)
#define POT_R_DM_STRONG          (0x06u)
#define POT_R_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define POT_R_MASK               POT_R__MASK
#define POT_R_SHIFT              POT_R__SHIFT
#define POT_R_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define POT_R_PS                     (* (reg32 *) POT_R__PS)
/* Port Configuration */
#define POT_R_PC                     (* (reg32 *) POT_R__PC)
/* Data Register */
#define POT_R_DR                     (* (reg32 *) POT_R__DR)
/* Input Buffer Disable Override */
#define POT_R_INP_DIS                (* (reg32 *) POT_R__PC2)


#if defined(POT_R__INTSTAT)  /* Interrupt Registers */

    #define POT_R_INTSTAT                (* (reg32 *) POT_R__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define POT_R_DRIVE_MODE_SHIFT       (0x00u)
#define POT_R_DRIVE_MODE_MASK        (0x07u << POT_R_DRIVE_MODE_SHIFT)


#endif /* End Pins POT_R_H */


/* [] END OF FILE */
