#include <REGX52.H>
#include "LCD1602.h"
void main()
{
  LCD_init();
	//LCD_showchar(1,1,'a');
 // LCD_String(2,1,"hello");
//	LCD_Shownumber(2,7,6543,3);
	LCD_Showsigned(1,1,-532,5);
	while(1)
	{
		
		
	}
}