#include <REGX52.H>
#include "Delay.h"

//引脚定义
sbit XPT2046_DIN=P3^4;
sbit XPT2046_CS=P3^5;
sbit XPT2046_DCLK=P3^6;
sbit XPT2046_DOUT=P3^7;

/**
  * @brief  XPT2046读取AD值
  * @param  Command 命令字，范围：头文件内定义的宏，结尾的数字表示转换的位数
  * @retval AD转换后的数字量，范围：8位为0~255，12位为0~4095
  */
unsigned int XPT2046_ReadAD(unsigned char Command)
{
	unsigned char i;
	unsigned int Data=0;			//16位
	XPT2046_DCLK=0;			//初始化
	XPT2046_CS=0;			//CS置零
	for(i=0;i<8;i++)			//写指令
	{	
		XPT2046_DIN=Command&(0x80>>i);
		XPT2046_DCLK=1;			//上升沿发送一位
		XPT2046_DCLK=0;			//下降沿无事发生
	}

	for(i=0;i<16;i++)			//写指令
	{	
		XPT2046_DCLK=1;			
		XPT2046_DCLK=0;			//下降沿接收一位
		Delay(1);			//必须Delay1ms才准确变化
		if(XPT2046_DOUT){Data|=(0x8000>>i);}		//高位开始读，读16位
	}
	XPT2046_CS=1;			//CS置高
	
	if(Command&0x08)				//判断多少位，如果1，是8位，如果0，是12位
	{
		return Data>>8;
	}
	else
	{
		return Data>>4;
	}
}