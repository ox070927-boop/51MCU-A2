#include <REGX52.H>
#include "Delay.h"

unsigned char LEDNum;

void main ()
{
	P2=~0x01;  			//上电默认LED1点亮
	while(1)
	{
		if(P3_1==0)		//如果K1按键按下
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			
			LEDNum++;		//LEDNum自增
			if(LEDNum>=8)		//限制LEDNum自增范围
				LEDNum=0;
			P2=~(0x01<<LEDNum);   //LED的第LEDNum位点亮
		}
		if(P3_0==0)		//如果K2按键按下
		{
			Delay(20);
			while(P3_0==0);
			Delay(20);
			
			if(LEDNum==0)  //LEDNum是无符号，要先判断是否为0
				LEDNum=7;
			else					//LEDNum未减到0，自减
				LEDNum--;
			P2=~(0x01<<LEDNum);  //LED的第LEDNum位点亮
		}
	}	
}