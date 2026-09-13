#include <REGX52.H>

//独立按键控制LED亮灭
//当按键按下，IO口接地，与按键相接的P3口为低电平
void main ()
{
	while(1)
	{
		if(P3_1==0 ||P3_0==0)  //如果K1按键或K2按键按下
		{
			P2_0=0 ;	//LED1输出0，点亮
		}
		else
		{
			P2_0=1 ;	//LED1输出1，熄灭
		}
	}	
}