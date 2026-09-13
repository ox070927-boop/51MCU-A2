#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"

void main ()
{
	while(1)
	{
		Nixie(1,1);			//在数码管的第1位显示1	
		Nixie(2,2);			//在数码管的第2位显示2
		Nixie(3,3);			//在数码管的第3位显示3
		Nixie(4,4);			//在数码管的第4位显示4
		Nixie(5,5);			//在数码管的第5位显示5
		Nixie(6,6);			//在数码管的第6位显示6
	}	
}