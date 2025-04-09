#include <REGX52.H>
#include "LCD1602.h"
char flat;
char bz=1;
char chr;
unsigned char ar[4];
char i=0;
int time;
void TO()   //计时
{ 
	TMOD&=0xf0;//选择工作模式    00110001
	TMOD|=0x01;
	TH0=0;
	TL0=0;
	TF0=0;
	TR0=0;   //停止计数
}

void TC(char i)
{
	if(i)
  TR0=1;    //开始计时
	else
	TR0=0;     //停止计时
}

unsigned int Count()   //得到计时
{
	int a=TH0;
	int b=TL0;
	return (TH0<<8)|TL0;
}

void Settime()    //设置计时器
{
	TH0=0;
	TL0=0;
}



//----------------------------------------------------------------------------------------------------------


void TW()      //外部中断
{
	IT0=1;       //下降沿有效
	IE0=0;       //中断允许标志位
	EX0=1;       //外部中断允许位
	EA=1;        //中断允许寄存器
}


void TW_() interrupt 0
{
	 		 TC(1);	 
			 if(bz==1)
	  	 {
				 time=Count();
				 Settime();
				 if(13500-1000<time&&13500+1000>time) //开始信号
		      {
						P2_0=0;
				    bz=2;
		      }
	     }
		  else if(bz==2)
	    {
				time=Count();
				Settime();
		    if(620<time&&1620>time)
		    {
			     ar[i/8]&=~(0x01<<(i%8));
					 i++;
		        
		     }
		     else if(1750<time&&2750>time)
		    {
			      ar[i/8]|=(0x01<<(i%8));
					  i++;  
		    } 
	     }
				
				if(i>=32)
	      {
					 LCD_ShowNum(1,1,i,7);
				  	if(ar[0]==~ar[1]&&ar[2]==~ar[3])
			      {
		         i=0;
		         TC(0);
		         Settime();
		         bz=1;
					  }
					  LCD_ShowNum(2,1,ar[0],3);
					  LCD_ShowNum(2,5,ar[1],3);
					  LCD_ShowNum(2,9,ar[2],3);
					  LCD_ShowNum(2,13,ar[3],3);
	      }
}


//-----------------------------------------------------------------------------------------------

unsigned char get_chr()
{
	return ar[0];	       
}