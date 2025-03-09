#include <REGX52.H>
#include <math.h>
sbit LCD_RS=P2^6;
sbit LCD_WS=P2^5;
sbit LCD_E=P2^7;
#define LCD_DATA P0

void Delay1ms(void)	//@11.0592MHz  ����ʱ��Ϊ1ms
{
	unsigned char data i, j;

	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

void writecommand(unsigned char command ) //дָ��
{
                     
 LCD_RS=0;                    //ѡ��ָ�� 
 LCD_WS=0;                    //д����
 LCD_DATA=command;            //д������
 LCD_E=1;                     //����ʹ��Ϊ1
 Delay1ms();
 LCD_E=0;                     //ִ��ָ��
 Delay1ms();
}

void writedata(unsigned char DATA)     //д����
{
 LCD_RS=1;                    //ѡ��ָ�� 
 LCD_WS=0;                    //д����
 LCD_DATA=DATA;               //д������
 LCD_E=1;                     //����ʹ��Ϊ1
 Delay1ms();
 LCD_E=0;                     //ִ��ָ��
 Delay1ms();
}

void LCD_init(void)           //��ʼ��
{                             
	writecommand(0x38);         //8λ���ݽӿڣ�������ʾ
	writecommand(0x0c);         //��ʾ�������أ���˸��
	writecommand(0x06);         //��д����֮��AC�Զ���1����ʾ���治��
	writecommand(0x01);         //����
}

void LCD_showchar(unsigned char Line,Column,Char)
{
	char AC;
	if(Line==1)                 //��һ��д��
	{
		AC=Column-1;
		writecommand(0x80|AC);    //DDRAM��ַ���ã�����λ��
	}
	else
	{                           //�ڶ��й���λ��
		AC=Column-1;         
		writecommand(0x80|AC+0x40);  //ע�����+�����ȼ�����|
	}
	writedata(Char);
}

void test(unsigned char Line,Column)   //����λ��
{
	char AC;
	if(Line==1)                 //��һ��д��
	{
		AC=Column-1;
		writecommand(0x80|AC);    //DDRAM��ַ���ã�����λ��
	}
	else
	{                           //�ڶ��й���λ��
		AC=Column-1;         
		writecommand(0x80|AC+0x40);  //ע�����+�����ȼ�����|
	}
}



void  LCD_String(unsigned char Line,Column,unsigned char Char[])  //�����ַ�����ĵ�ַ�����λ��    ��ʾ�ַ���
{
	char i=0;
  LCD_showchar(Line,Column);
	while(Char[i]!='\0')                                            //�������ַ���ĩβʱ����ѭ��
	{
		
		writedata(Char[i]);
		i++;
	}
}

int Pow(int y,x)  //y��x�η�
{
	int Power=1;
	int i;
	for(i=0;i<x;i++)
	{
		Power=Power*y;
	}
	return Power;
}

void LCD_Shownumber(unsigned char Line,Column,int number,int lenth)   //��ʾ����
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

void LCD_Showsigned(unsigned char Line,Column,int number,lenth)   //��ʾ������������
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