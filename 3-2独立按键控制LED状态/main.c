#include <REGX52.H>
#include "Delay.h"

//独立按键消抖

void main ()
{
	while(1)
	{
		if(P3_1==0)						//如果K1按键按下
		{
			Delay(20);					//延时消抖
			while(P3_1==0);			//松手检测
			Delay(20);					//延时消抖
			
			P2_0=~P2_0;					//LED1取反
		}
	}	
}