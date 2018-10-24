/* ========================================
   小车走迷宫任务代码
 * ========================================
*/
#include <project.h>
#include <stdio.h> //需要使用sprintf

void TurnLeft();
void TurnRight();
void Backward();
void Forward();
void TurnRightTiny();
void IntToString(char *str, int number);

uint32 ADC_Result_L = 0,ADC_Result_R = 0;//ADC_Result_L和ADC_Result_R分别为AD转换后的左右红外原始数据
float dist_L,dist_R;//dist_L和dist_R分别为红外传感器处理后数据
int dis_L,dis_R;//dist_L和dist_R数值类型转换后数据
int e=0,e1=0,e2=0;//机器人与左侧墙壁距离偏差值（当前时刻、上一时刻和上上时刻）
int PWM_controlled_R;//右侧电机输入PWM波值
char string_L[50],string_R[50];//由数值变换为字符串时存储的阵列，用于LCD显示

int main()
{
    //设备初始化部分
    //PWM 初始化
    PWM_R_Start();
    PWM_L_Start();
    //LCD 初始化
    LCD_Char_Start();
    LCD_Char_LoadCustomFonts(LCD_Char_customFonts);
    LCD_Char_ClearDisplay();
    LCD_Char_Position(0,0);
    CyGlobalIntEnable;
    //ADC 初始化
    ADC_SAR_Seq_Start();
    ADC_SAR_Seq_StartConvert();

    //红外传感器数据采集&处理部分
    for(;;)
    {
        //数据采集
        ADC_SAR_Seq_IsEndConversion(ADC_SAR_Seq_WAIT_FOR_RESULT);
        ADC_Result_L = ADC_SAR_Seq_GetResult16(0);
        ADC_Result_R = ADC_SAR_Seq_GetResult16(1);
        //左侧红外数据处理
        if(ADC_Result_L >0xFFFF) ADC_Result_L =0;
        if(ADC_Result_L>0)
        {
            dist_L=0.5/(0.00002*ADC_Result_L -0.00045)-2;
            dis_L=(int)dist_L;
            IntToString(string_L, dis_L);
            LCD_Char_Position(0,0);
            LCD_Char_PrintString(string_L);
        }
        //右侧红外数据处理
        if(ADC_Result_R >0xFFFF) ADC_Result_R =0;
        if(ADC_Result_R>0)
        {
            dist_R=0.5/(0.00002*ADC_Result_R -0.00045)-2;
            dis_R=(int)dist_R;
            //IntToString(string_R, dis_R);
            //LCD_Char_Position(0,0);
            //LCD_Char_PrintString(string_R);
        }

        //控制策略
        /*
        //方案一：On-Off阈值控制，可以完成任务，但控制效果一般
        //机器人碰撞后应急处理：倒车&右转
        if (Bumper_L_Read()==0 || Bumper_R_Read()==1)
        {
            Backward();
            TurnRight();
        }
        else if(dis_L>=30)TurnLeft();
        else if(dis_L<=22)TurnRightTiny();
        else if(dis_R<=25)TurnRightTiny();      
        else Forward();
        */
        
        //方案二：PID控制，控制效果较为流畅
        //机器人碰撞后应急处理：倒车&右转
        if (Bumper_L_Read()==0 || Bumper_R_Read()==1)
        {
            Backward();
            TurnRight();
        }
        //偏差值计算&更新
        e2 = e1;
        e1 = e;
        e = dis_L-25;
        //电机控制
        PWM_L_WriteCompare(4100);//4100
        PWM_controlled_R = 5100+100*e+50*(e+e1+e2)+10*(e-e1);
        PWM_R_WriteCompare(PWM_controlled_R);
        CyDelay(2);        
    }
    /*
    //碰撞传感器&PWM测试
    for(;;)
    {
        //碰撞传感器 右方碰撞为1，否则为0；左方碰撞为0，否则为1
        if (Bumper_R_Read()== 1&&Bumper_L_Read()==1 ) TurnLeft();//右方碰撞
        if (Bumper_R_Read()== 0&&Bumper_L_Read()==0 ) TurnRight();//左方碰撞
        if (Bumper_R_Read()== 1&&Bumper_L_Read()==0 ) Backward();//前方碰撞
        Forward();
        CyDelay(100);
    }
    */
    return 0;
}

//小幅度右转
void TurnRightTiny()
{
   LCD_Char_Position(1,0);
   LCD_Char_PrintString("Turn RightTiny");
   PWM_R_WriteCompare(4200);//4700
   PWM_L_WriteCompare(4300);//3900
   CyDelay(100);
}

//右转
void TurnRight()
{
    LCD_Char_ClearDisplay();
    LCD_Char_Position(1,0);
    LCD_Char_PrintString("Turn Right");
    PWM_R_WriteCompare(3000);
    PWM_L_WriteCompare(3500);
    CyDelay(300);
}

//左转
void TurnLeft()
{
   LCD_Char_ClearDisplay();
   LCD_Char_Position(1,0);
   LCD_Char_PrintString("Turn Left");
   PWM_R_WriteCompare(5100);
   PWM_L_WriteCompare(4300);
   CyDelay(100);
}

//倒车
void Backward()
{
    LCD_Char_ClearDisplay();
    LCD_Char_Position(1,0);
    LCD_Char_PrintString("Backward");
    PWM_R_WriteCompare(3900);
    PWM_L_WriteCompare(5400);
    CyDelay(400);
}

//直行
void Forward()
{
    LCD_Char_ClearDisplay();
    LCD_Char_Position(1,0);
    LCD_Char_PrintString("Forward");
    PWM_R_WriteCompare(5400);
    PWM_L_WriteCompare(3900);
    CyDelay(50);
}

void IntToString(char *str, int number)// 由数值变换为字符串的函数
{
    sprintf(str, "%d", number);
}


/* [] END OF FILE */
