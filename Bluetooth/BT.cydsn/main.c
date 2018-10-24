/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include<stdio.h>
#include<stdlib.h>


int main()
{
    uint8 ch; 
    UART_Start();
    PWM_R_Start();
    PWM_L_Start();
    ch=0xcc;
    for(;;)
    {
        ch=UART_UartGetChar();
        if (ch=='F')
        {
            PWM_R_WriteCompare(5100);
            PWM_L_WriteCompare(4100);
        }
        
        if (ch=='S')
        {
            PWM_R_WriteCompare(4500);
            PWM_L_WriteCompare(4500);
        }
        
        if (ch=='B')
        {
            PWM_R_WriteCompare(3900);
            PWM_L_WriteCompare(4900);
        }
        
        if (ch=='R')
        {
            PWM_R_WriteCompare(4500);
            PWM_L_WriteCompare(4100);
        }
        
        if (ch=='L')
        {
            PWM_R_WriteCompare(5100);
            PWM_L_WriteCompare(4500);
        }
        

    }
    return 0;
}


/* [] END OF FILE */
