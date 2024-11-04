// #ifndef _DELAY_H
// #define _DELAY_H

#ifndef a2352
//#define _A_H
  void Delay(unsigned int ms);
 #endif
 
 //sbit SCL=P2^1;
//sbit SDA=P2^0;
// void start()
// { 
//	  SDA=1;
//	  SCL=1;
//	  SDA=0;//开始
//	  SCL=0;//放数据
// }
// 
// void stop()
// {
//	 SCL=0;  //准备放数据
//	 SDA=0;  //放数据 为啥将SDA拉低?前面是应答位，若不应答，将SDA拉低，应答则没事
//	 SCL=1;  //读取数据
//	 SDA=1;  //将SDA拉高，停止
// }
// 
// void send(unsigned int byte) //发送数据
// {
//	 int i;
//	 for(i=0;i<8;i++)
//	 {
//		SDA=byte&(0x80>>i); //将数据放在SDA上
//		SCL=1;              //将数据发出去,SCL前面是低电平，所以要将SCL拉高
//		SCL=0;              //准备发送下次数据
//	 }
// 
// }
// 
// unsigned char RECIVEBYTE()      //接受数据
// {
//	 unsigned char byte,i=0x00;
//	 SDA=1;//主机将权利交给从机，释放SDA
//	 for(i;i<8;i++)
//	 {
//	        if(SDA)
//	        {
//		        SCL=1;    //从机发送数据
//		        byte=byte|(0x80>>i);
//		        SCL=0;    //准备发送下次数据
//	        }
//   }
//	 return byte;
// }
// 
// 
// void sendanswer(bit answer)   //接受数据以后发送应答
// {
//	 SDA=answer;
//	 SCL=1;  //发送应答
//	 SCL=0;  //准备下次数据发送
// }
// 
// unsigned char reciveanswer()  //接受从机发送的应答
// {
//	 bit answer;
//	 SDA=1;  //释放SDA
//	 SCL=1;    //就可以读取数据线了
//	 answer=SDA;
//	 SCL=0;   //准备下次数据发送
//	 return answer;
// }