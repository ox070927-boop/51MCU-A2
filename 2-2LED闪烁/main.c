#include <REGX52.H>
#include <INTRINS.H> 

void Delay500ms()	//@11.0592MHz
{
	unsigned char  i, j, k;

	_nop_();     //<INTRINS.H>文件
	_nop_();
	i = 22;
	j = 3;
	k = 227;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main ()
{
	while(1)
	{
		P2=0xFE ;        //1111 1110
		Delay500ms();
		P2=0xFF ;
		Delay500ms();    //1111 1111
	}	
}
