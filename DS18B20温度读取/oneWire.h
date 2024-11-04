#ifndef  _ONEWIRE_H_
#define  _ONEWIRE_H_
unsigned char oneWire();
void DELAY5us(void);
void send(unsigned char byte);
unsigned char recive();
void sendbyte(unsigned char byte);
unsigned char recivebyte();
#endif