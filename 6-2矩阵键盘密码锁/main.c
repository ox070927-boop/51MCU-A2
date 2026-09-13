#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

#define RightPassword 2345

unsigned char KeyNum;
unsigned int Password , Count ;

void main ()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
		KeyNum= MatrixKey();
		if(KeyNum)
		{
			if(KeyNum<=10) 		//如果S1~S10被按下，输入密码
			{
				if(Count<4)		//如果输入次数少于4
				{
					Password*=10;
					Password+=KeyNum%10;		//获取一位密码
					Count++;
				}
				LCD_ShowNum(2,1,Password,4);	//更新显示
			}
			if(KeyNum==11)		//如果S11按下，确认
			{
				if(Password==RightPassword)
				{
					LCD_ShowString(1,14,"OK ");	//显示OK
					Password=0;  //密码清零
					Count=0;		 //计次清零
					LCD_ShowNum(2,1,Password,4);	//更新显示
				}
				else
				{
					LCD_ShowString(1,14,"ERR");	//显示OK
					Password=0;  //密码清零
					Count=0;		 //计次清零
					LCD_ShowNum(2,1,Password,4);	//更新显示
				}
			}
			if(KeyNum==12)		//如果S12按键按下，取消
			{
				Password=0;  //密码清零
				Count=0;		 //计次清零
				LCD_ShowNum(2,1,Password,4);	//更新显示
			}
		}
	}	
}