#include <REGX52.H>
#include <math.h>
sbit LCD_RS=P2^6;
sbit LCD_WS=P2^5;
sbit LCD_E=P2^7;
#define LCD_DATA P0

void Delay1ms(void)	//@11.0592MHz  设置时间为1ms
{
	unsigned char data i, j;

	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

void writecommand(unsigned char command ) //写指令
{
                     
 LCD_RS=0;                    //选择指令 
 LCD_WS=0;                    //写数据
 LCD_DATA=command;            //写入数据
 LCD_E=1;                     //设置使能为1
 Delay1ms();
 LCD_E=0;                     //执行指令
 Delay1ms();
}

void writedata(unsigned char DATA)     //写数据
{
 LCD_RS=1;                    //选择指令 
 LCD_WS=0;                    //写数据
 LCD_DATA=DATA;               //写入数据
 LCD_E=1;                     //设置使能为1
 Delay1ms();
 LCD_E=0;                     //执行指令
 Delay1ms();
}

void LCD_init(void)           //初始化
{                             
	writecommand(0x38);         //8位数据接口，两行显示
	writecommand(0x0c);         //显示开，光标关，闪烁关
	writecommand(0x06);         //读写操作之后，AC自动加1，显示画面不动
	writecommand(0x01);         //清屏
}

void LCD_showchar(unsigned char Line,Column,Char)
{
	char AC;
	if(Line==1)                 //第一行写入
	{
		AC=Column-1;
		writecommand(0x80|AC);    //DDRAM地址设置，光标的位置
	}
	else
	{                           //第二行光标的位置
		AC=Column-1;         
		writecommand(0x80|AC+0x40);  //注意事项：+的优先级大于|
	}
	writedata(Char);
}

void test(unsigned char Line,Column)   //光标的位置
{
	char AC;
	if(Line==1)                 //第一行写入
	{
		AC=Column-1;
		writecommand(0x80|AC);    //DDRAM地址设置，光标的位置
	}
	else
	{                           //第二行光标的位置
		AC=Column-1;         
		writecommand(0x80|AC+0x40);  //注意事项：+的优先级大于|
	}
}



void  LCD_String(unsigned char Line,Column,unsigned char Char[])  //传入字符数组的地址，光标位置    显示字符串
{
	char i=0;
  LCD_showchar(Line,Column);
	while(Char[i]!='\0')                                            //当读到字符串末尾时跳出循环
	{
		
		writedata(Char[i]);
		i++;
	}
}

int Pow(int y,x)  //y的x次方
{
	int Power=1;
	int i;
	for(i=0;i<x;i++)
	{
		Power=Power*y;
	}
	return Power;
}

void LCD_Shownumber(unsigned char Line,Column,int number,int lenth)   //显示数字
{
	 char i;
	 char Num;
   test(Line,Column);
	 for(i=lenth;i>0;i--)  //9999  3   9    2  9   1 9   0   9
	 {
	 //Num=number/Pow(10,i)      ;
	 writedata(number/Pow(10,i-1)%10+'0');
	 }
}

void LCD_Showsigned(unsigned char Line,Column,int number,lenth)   //显示带正负的数字
{
	int Num;
	int i;
	test(Line,Column);
	if(number>0)
	{
		Num=number;
		writedata('+');
	}
	if(number<0)
	{
		Num=-number;
		writedata('-');
	}
	for(i=lenth;i>0;i--)  //9999  3   9    2  9   1 9   0   9
	{
	 writedata(Num/Pow(10,i-1)%10+'0');
	}
	
}