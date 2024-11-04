#include <REGX52.H>
#include <LCD1602.h>
sbit oneWire_DQ=P3^7;
unsigned char i;
unsigned char oneWire()   //初始化
{
	unsigned char ack;
	oneWire_DQ=1;
	oneWire_DQ=0;          //主机将数据线拉低
	i = 227;
	while (--i);           //延迟500微秒
	oneWire_DQ=1;          //主机释放数据线
	i = 29;
	while (--i);           //延迟70微秒   从机将数据线拉低以响应主机
  ack=oneWire_DQ;        //获取数据线的电平
	i = 227;
	while (--i);  
	return ack;
}

void send(unsigned char byte)  //发送一位
{
	oneWire_DQ=0;     
	i = 4;
	while (--i);                 //延迟10微秒
	oneWire_DQ=byte;  //如果发送1，释放总线，如果发送0，不释放总线
	
	i = 25;
	while (--i);      //延迟55微秒
	oneWire_DQ=1;	  //如果发送0，释放总线
}

void DELAY5us(void)	//@11.0592MHz  5微秒
{
}


unsigned char recive()      //主机接受一位
{
	unsigned char byte;
	oneWire_DQ=0;
  DELAY5us();	              // 主机拉低5微秒  再将数据线释放掉，控制权交给从机
	oneWire_DQ=1;
	DELAY5us();	 
	byte=oneWire_DQ;          //是高则为1，是低则为0
	i = 22;
	while (--i);               //延时50微秒
	return byte;
}

void sendbyte(unsigned char byte)  //发送一个字节
{
	unsigned char j;
	for(j=0;j<8;j++)
	{
		send(byte&(0x01<<j));
	}
}


unsigned char recivebyte()     //接受一个字节
{
	unsigned char j=0;
	unsigned char byte=0x00;
	for(j;j<8;j++)
	{
		         //接受数据
		if(recive())
		{
		 byte|=(0x01<<j);
		}
	}
	return byte;
}

 