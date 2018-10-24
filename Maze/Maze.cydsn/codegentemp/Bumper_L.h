/*******************************************************************************
* File Name: Bumper_L.h  
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

#if !defined(CY_PINS_Bumper_L_H) /* Pins Bumper_L_H */
#define CY_PINS_Bumper_L_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Bumper_L_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Bumper_L_Write(uint8 value) ;
void    Bumper_L_SetDriveMode(uint8 mode) ;
uint8   Bumper_L_ReadDataReg(void) ;
uint8   Bumper_L_Read(void) ;
uint8   Bumper_L_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Bumper_L_DRIVE_MODE_BITS        (3)
#define Bumper_L_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Bumper_L_DRIVE_MODE_BITS))

#define Bumper_L_DM_ALG_HIZ         (0x00u)
#define Bumper_L_DM_DIG_HIZ         (0x01u)
#define Bumper_L_DM_RES_UP          (0x02u)
#define Bumper_L_DM_RES_DWN         (0x03u)
#define Bumper_L_DM_OD_LO           (0x04u)
#define Bumper_L_DM_OD_HI           (0x05u)
#define Bumper_L_DM_STRONG          (0x06u)
#define Bumper_L_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Bumper_L_MASK               Bumper_L__MASK
#define Bumper_L_SHIFT              Bumper_L__SHIFT
#define Bumper_L_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Bumper_L_PS                     (* (reg32 *) Bumper_L__PS)
/* Port Configuration */
#define Bumper_L_PC                     (* (reg32 *) Bumper_L__PC)
/* Data Register */
#define Bumper_L_DR                     (* (reg32 *) Bumper_L__DR)
/* Input Buffer Disable Override */
#define Bumper_L_INP_DIS                (* (reg32 *) Bumper_L__PC2)


#if defined(Bumper_L__INTSTAT)  /* Interrupt Registers */

    #define Bumper_L_INTSTAT                (* (reg32 *) Bumper_L__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Bumper_L_DRIVE_MODE_SHIFT       (0x00u)
#define Bumper_L_DRIVE_MODE_MASK        (0x07u << Bumper_L_DRIVE_MODE_SHIFT)


#endif /* End Pins Bumper_L_H */


/* [] END OF FILE */
