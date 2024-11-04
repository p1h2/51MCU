#include <REGX52.H>
#include <LCD1602.h>
#include <DS18B20.h>
#include <Delay.h>
float T;
void main()
{
  LCD_Init();
	LCD_ShowString(1,1,"T:");
  while(1)
{
	convert();
  Delay(800);
	T=read_temperature();
	if(T<0)
	{
	T=-T;
	LCD_ShowString(1,3,"-");
	}
  else
 {
	LCD_ShowString(1,3,"+");
 }
  LCD_ShowNum(1,4,T,3);
  LCD_ShowString(1,7,".");
  LCD_ShowNum(1,8,(unsigned long)(T*10000)%10000,4); //*和%的优先级是同级的，从左往右运算     
 LCD_ShowString(1,12,"C");
}




}