#include <REGX52.H>
#include "Delay.h"

//IO扩展——串转并

sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SER=P3^4;

#define MATRIX_LED_PORT	P0

/**
  * @brief		74H595写入一个字节
  * @param		Byte 要写入的字节
  * @retval		无
  */

void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for (i=0;i<8;i++)
	{
		SER=Byte&(0x80>>i);		//左边被赋值为数，右边赋值为字节，遵循非零即1
		SCK=1;		//相当于一个一个输入字节
		SCK=0;
	}
	RCK=1;		//最后一起并行输入
	RCK=0;
}

/**
  * @brief		LEDd点阵屏显示一列数据
  * @param		Column要选择的列，范围：0~7，0在最左边
	* @param	 	Data 选择列显示的数据，高位在上，1为亮0为灭
  * @retval		无
  */

void MatrixLED_ShowColumn(unsigned char Column,Data)
{
	_74HC595_WriteByte(Data);
	MATRIX_LED_PORT=~(0x80>>Column);
	Delay(1);
	MATRIX_LED_PORT=0xFF;		//消影
}

void main ()
{
	SCK=0;
	RCK=0;
	while(1)
	{
		unsigned char Data[]={0x38,0x7C,0x7E,0x3F,0x3F,0x7E,0x7C,0x38,};
		unsigned char i;
		for(i=0;i<8;i++)
		{
			MatrixLED_ShowColumn(i,Data[i]);
		}
	}	
}
	