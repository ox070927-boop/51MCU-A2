#include <REGX52.H>
#include "Delay.h"
#include "MatrixLED.h"

//动画数据
unsigned char code Animation[]={		//code  写入flash
	0x78,0xFC,0xFE,0x7F,0x7F,0xFE,0xFC,0x78,
	0x78,0x84,0x82,0x41,0x41,0x82,0x84,0x78,
};


void main ()
{
	unsigned char i,Offset=0,Count=0;
	MatrixLED_Init();
	while(1)
	{
		for(i=0;i<8;i++)		//循环8次，显示8列数据
		{
			MatrixLED_ShowColumn(i,Animation[i+Offset]);
		}
		Count++;		//计次延时
		if(Count>15)
		{
			Count=0;
			Offset+=8;		//偏移+8，切换下一帧画面
			if(Offset>8)
			{
				Offset=0;
			}
		}
	}	
}
	
	