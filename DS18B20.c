#include <REGX52.H>
#include <oneWire.h>
#include <LCD1602.h>
#define SEARCH_ROM 0xF0
#define READ_ROM 0x33
#define MATCH_ROM 0x55
#define SKIP_ROM 0xcc
#define ALARM_SEARCH 0xEC
#define CONVERT 0x44    //温度转换功能命令
#define WRITE_SCRATCHPAD 0x4E
#define READ_SCRATCHPAD 0xBE
#define COPY_SCRATCHPAD 0x48
#define RECALL_E2 0xB8
void convert()   //初始化
{
	oneWire();
	sendbyte(SKIP_ROM);
	sendbyte(CONVERT);
}


float read_temperature()    //读取温度
{     
	unsigned char TLSB,TMSB;
	int temperature;
	float T;
	oneWire();
	sendbyte(SKIP_ROM);         //跳过ROM
	sendbyte(READ_SCRATCHPAD);  //读寄存器
	TLSB=recivebyte();          //接受数据
	TMSB=recivebyte();  
	temperature=(TMSB<<8)|TLSB;
	T=temperature/16.0;           //世界第一皮卡锤
	return T;
}