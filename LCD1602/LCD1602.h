#ifndef    _LCD1602.H_
#define    _LCD1602.H_
void Delay1ms(void);
void writecommand(unsigned char command );
void writedata(unsigned char DATA);
void LCD_init(void);
void LCD_showchar(unsigned char Line,Column,Char);
void LCD_String(unsigned char Line,Column,unsigned char Char[]);
void test(unsigned char Line,Column);
int Pow();
void LCD_Shownumber(unsigned char Line,Column,int number,int lenth);
void LCD_Showsigned(unsigned char Line,Column,int number,lenth);
#endif