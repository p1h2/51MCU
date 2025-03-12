#include <REGX52.H>
#include "Delay.h"
char k;
char k1=0,k2;
char key()
{	
	if(P3_0==0){return 1;}
	if(P3_1==0){return 2;}
	if(P3_2==0){return 3;}
	if(P3_3==0){return 4;}
	return 0;
}

void K_ey()
{
	k1=k2;    
	k2=key();
	if(k1==0&&k2==1)
	{
   k=1;
	}		
	if(k1==0&&k2==2)
	{
   k=2;
	}	
	if(k1==0&&k2==3)
	{
   k=3;
	}		
	if(k1==0&&k2==4)
	{
   k=4;
	}			
}

char kkk()
{
	char temp;
	temp=k;
	k=0;
	return temp;
}