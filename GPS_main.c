//#include "gps.h"
//#include"delay.h"
#include "lpc214x.h"
//#include "uart.h"
void delay_fv(unsigned int x)
{
	int i,j;
	for(i=0;i<=x;i++)
		for(j=0;j<=100;j++);

}
int main()
{
	        int pclk=12000000, value;
	        PINSEL0|=0x05;
	        IO0DIR|=0x01;
	        VPBDIV|=0x01;
	        U0FCR=0x07;
	        U0LCR=0x83;
		  // UART0REG.FDR.bit.DIVADDVAL = 1;
	        // UART0REG.FDR.bit.MULVAL = 12;
	        U0FDR=0xC1;
	        value=pclk/(16*115200);
	        U0DLL=value & 0x0FF;
	        U0DLM=(value & 0xFF00)>>8;
	        U0TER=0x80;
	        U0LCR=0x03;

	        //ConfigUart(Uart1,9600);
	        PINSEL0|=0x05<<16;
	        IO0DIR|=0x01<<8;
	        // VPBDIV|=0x01;
	        U1FCR=0x07;
	        U1LCR=0x83;
              value=pclk/(16*9600);
	        U1DLL=value & 0x0FF;
	        U1DLM=(value & 0xFF00)>>8;
	                       U1TER=0x80;
	                       U1LCR=0x03;
	//ConfigUart(Uart1,9600);
	//ConfigUart(Uart0,115200);
	                       delay_fv(500);
			while(1)
		                 {
		while(!(U1LSR & 0x01));
		char data1= U1RBR;
		 U0THR=data1;
		while(!(U0LSR & 0x20));

				          }

}
