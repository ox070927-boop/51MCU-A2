#include <REGX52.H>
#include "UART.h"

unsigned char data_LED;

void main()
{
    UART_Init();     // 串口初始化
    P2 = 0xFF;      // 初始全灭
    while (1)
    {
    }
}

void UART_Routine() interrupt 4
{
    if (RI == 1)
    {
        data_LED = SBUF;
        P2 = ~data_LED;      // 读取数据，取反后输出到LED
        UART_SendByte(data_LED);
        RI = 0;
    }
}