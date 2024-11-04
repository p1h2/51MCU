#include <REGX52.H>
#include "Delay.h"

/**
  * @brief  获取独立按键键码
  * @param  无
  * @retval 按下按键的键码，范围：0~4，无按键按下时返回值为0
  */
	
unsigned char number;
unsigned char K()
{
	unsigned char KeyNumber=0;
	if(P3_1==0){KeyNumber=1;}
	if(P3_0==0){KeyNumber=2;}
	if(P3_2==0){Delay(20);while(P3_2==0);Delay(20);return 3;}
	if(P3_3==0){Delay(20);while(P3_3==0);Delay(20);return 4;}
	return KeyNumber;
}

void key(void)
{
	unsigned char k1,k2;
  k1=k2;        //第一次按下的数据
	k2=K();//第二次按键的数据
	if(k1==1&&k2==0)
	{
		number=1;
	}
	if(k1==2&&k2==0)
	{
	   number=2;
	}
	if(k1==3&&k2==0)
	{
		number=3;
	}
	if(k1==4&&k2==0)
	{
		number=4;
	}
}
	 
