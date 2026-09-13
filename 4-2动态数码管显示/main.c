#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"

//注意：动态数码管显示要记得  消影
//位选--段选--  消影（段码清零） --位选--段选--

void main ()
{
	while(1)
	{
		Nixie(1,1);			//在数码管的第一位显示1
		//Delay(20);
		Nixie(2,2);			//在数码管的第二位显示2
		//Delay(20);
		Nixie(3,3);			//在数码管的第三位显示3
		//Delay(20);
	}	
}