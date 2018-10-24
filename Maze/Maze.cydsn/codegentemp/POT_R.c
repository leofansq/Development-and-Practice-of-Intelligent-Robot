/*******************************************************************************
* File Name: POT_R.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "POT_R.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        POT_R_PC =   (POT_R_PC & \
                                (uint32)(~(uint32)(POT_R_DRIVE_MODE_IND_MASK << (POT_R_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (POT_R_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: POT_R_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void POT_R_Write(uint8 value) 
{
    uint8 drVal = (uint8)(POT_R_DR & (uint8)(~POT_R_MASK));
    drVal = (drVal | ((uint8)(value << POT_R_SHIFT) & POT_R_MASK));
    POT_R_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: POT_R_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  POT_R_DM_STRONG     Strong Drive 
*  POT_R_DM_OD_HI      Open Drain, Drives High 
*  POT_R_DM_OD_LO      Open Drain, Drives Low 
*  POT_R_DM_RES_UP     Resistive Pull Up 
*  POT_R_DM_RES_DWN    Resistive Pull Down 
*  POT_R_DM_RES_UPDWN  Resistive Pull Up/Down 
*  POT_R_DM_DIG_HIZ    High Impedance Digital 
*  POT_R_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void POT_R_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(POT_R__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: POT_R_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro POT_R_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 POT_R_Read(void) 
{
    return (uint8)((POT_R_PS & POT_R_MASK) >> POT_R_SHIFT);
}


/*******************************************************************************
* Function Name: POT_R_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 POT_R_ReadDataReg(void) 
{
    return (uint8)((POT_R_DR & POT_R_MASK) >> POT_R_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(POT_R_INTSTAT) 

    /*******************************************************************************
    * Function Name: POT_R_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 POT_R_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(POT_R_INTSTAT & POT_R_MASK);
		POT_R_INTSTAT = maskedStatus;
        return maskedStatus >> POT_R_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
