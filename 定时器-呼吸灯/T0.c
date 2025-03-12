#include <REGX52.H>
void TO()
{	
	TMOD=0x01;//选择模式  计时 计数  只要选择了T0 T1才能启动
	TH0=0xFC;
	TL0=0x66;
	EA=1;//中断允许标志位
	ET0=1;//允许中断信号通过
	TF0=0;//溢出标志位
  TR0=1;//启动定时器
}