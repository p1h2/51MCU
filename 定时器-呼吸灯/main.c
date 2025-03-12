#include <REGX52.H>
#include "T0.h"
#include "key.h"
#include "LCD1602.h"
sbit LED=P2^0;
unsigned char compare,current;
void main()
{
	unsigned a;
	int speed=0;
 
	TO();
  LCD_init(); 
	while(1)
	{
		 
		  K_ey();
		  a=kkk();
		 if(a==1)
		 {
			speed++;
			speed%=4;
			LCD_Shownumber(1,9,speed,3);
			if(speed==0)
		  {
					 	current=0;
		  }
			if(speed==1)
			{
		    	 	current=5;
			}
		  if(speed==2)
			{
					 	current=50;
			}
			if(speed==3)
			{
					 	current=100;
		  }
     			P2_0=~P2_0;
		 }
		 
 
			 
			  
	
			}
}

     

void test1()interrupt 1
{
	  TL0 = 0x9C;				//设置定时初始值
	  TH0 = 0xFF;		
    compare++;
	  compare%=100;
	  if(compare<current)
		{
			LED=0;
		}
		else
		{
			LED=1;
		}
}
	 
	
