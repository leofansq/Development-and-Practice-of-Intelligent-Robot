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
#include<project.h>
#include<stdio.h>//需要使用sprintf
#include<stdlib.h>

#define BlackOrWhite 600
#define PWM_left_forward  4150      //4200       //3500-4500-6000
#define PWM_right_forward 5025    //4950
extern uint8 const CYCODE LCD_Char_1_customFonts[];//载入传统字体
/*
uint32 ADC_Result = 0;//ADC_Result;表示数值的变量
uint32 ADC_Result1 = 0;
uint32 ADC_Result2 = 0;
*/
int ADC_Result = 0;//ADC_Result;表示数值的变量
int ADC_Result1 = 0;
int ADC_Result2 = 0;
    //int i; //i; BarGraph用
char string[50];// 由数值变换为字符串时存储的阵列
   
int PWM_left = PWM_left_forward;
int PWM_right = PWM_right_forward;

float angle = -90.0;
int Angle = 0;
void LCD_Display(int i)
{
    //LCD_Char_1_Position(1,0);
	//LCD_Char_1_PrintString("   ");       //输入前清屏        
	//LCD_Char_1_Position(1,0);
    sprintf(string," ");
	sprintf(string,"%d",i);
	LCD_Char_1_PrintString(string);
}


int main()
{
    CyGlobalIntEnable;
    UART_Start();     //使用3.3V电源时
    UART_UartPutString("Data Start");
    UART_UartPutString("\r\n");
    CyDelay(1); 
    
    LCD_Char_1_Start();
    LCD_Char_1_LoadCustomFonts(LCD_Char_1_customFonts);
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_Position(0,0);
    LCD_Char_1_PrintString("START!");
    CyDelay(10);
    
    ADC_SAR_Seq_Start();
    ADC_SAR_Seq_StartConvert(); //开始AD转换，因为在组件属性里设定为Continuous，因此以下自动连续采样
    
    PWM_Start();
    PWM_1_Start();
    
    for(;;)
    {
        
        
        //ADC的转换结束，存储结束前一直待机
        //采集巡线传感器的数据
        ADC_SAR_Seq_IsEndConversion(ADC_SAR_Seq_WAIT_FOR_RESULT);
        ADC_Result = ADC_SAR_Seq_GetResult16(0);
        //CyDelay(10);
        ADC_Result1 = ADC_SAR_Seq_GetResult16(1);
        //CyDelay(10);
        ADC_Result2 = ADC_SAR_Seq_GetResult16(2);
        //CyDelay(10);

        //UART显示数据
        /*UART_UartPutString("CCD1-");
        sprintf(string, "%d", ADC_Result);
        UART_UartPutString(string);
        UART_UartPutString("   CCD2-");
        sprintf(string, "%d", ADC_Result1);
        UART_UartPutString(string);
        UART_UartPutString("   CCD3-");
        sprintf(string, "%d", ADC_Result2);
        UART_UartPutString(string);
        UART_UartPutString("\r\n");
        UART_UartPutCRLF(0x0D);
        CyDelay(500);*/
        
        
        //LCD显示数据
        LCD_Char_1_ClearDisplay();
        LCD_Char_1_Position(1,0);
        //LCD_Char_1_PrintString("CCD1-");
        LCD_Display(ADC_Result);
        //LCD_Char_1_Position(1,0);
        LCD_Char_1_PrintString("-");
        LCD_Display(ADC_Result1);
        //LCD_Char_1_Position(0,11); 
        LCD_Char_1_PrintString("-");
        //LCD_Char_1_Position(1,11);
        LCD_Display(ADC_Result2);      
        //CyDelay(500);
        
        //调整PWM占空比转向
        PWM_left = PWM_left_forward;
        PWM_right = PWM_right_forward;
        //判断机器人偏离位置
        if(ADC_Result < BlackOrWhite) 
        {  
            //angle = (90.0*(ADC_Result - 4500))/2500;  
            //Angle=(int)angle;
            //sprintf(string, "%d", Angle);
            //LCD_Char_1_ClearDisplay();
            LCD_Char_1_Position(0,0);
            LCD_Char_1_PrintString("Turn left:");
            //LCD_Char_1_Position(1,0);
            //LCD_Char_1_PrintString(string);
            //if(ADC_Result1 < BlackOrWhite) PWM_left = 4400;
            //else PWM_left = PWM_left_forward + (BlackOrWhite - ADC_Result);  
            PWM_left = 4450;  //4400;
            PWM_right = 5000;//4950;    //4950;
        }
        else if(ADC_Result2 < BlackOrWhite) 
        {  
            //angle = (90.0*(ADC_Result2 - 4500))/2500;  
            //Angle=(int)angle;
            //sprintf(string, "%d", Angle);
            //LCD_Char_1_ClearDisplay();
            LCD_Char_1_Position(0,0);
            LCD_Char_1_PrintString("Turn right:");
            //LCD_Char_1_Position(1,0);
            //LCD_Char_1_PrintString(string);
            //if(ADC_Result1 < BlackOrWhite) PWM_right = 4500;
            //else PWM_right = PWM_right_forward - (BlackOrWhite - ADC_Result) * 2;  
            PWM_left = 4050;//4100    //4000
            PWM_right = 4550;//4500;    //4500
        }
        else
        {
            //LCD_Char_1_ClearDisplay();
            LCD_Char_1_Position(0,0);
            LCD_Char_1_PrintString("Go forward");
        }
        PWM_WriteCompare(PWM_left);
        PWM_1_WriteCompare(PWM_right);
        CyDelay(10);
    }
    //CyDelay(1000);
    return 0;
}




/* [] END OF FILE */
