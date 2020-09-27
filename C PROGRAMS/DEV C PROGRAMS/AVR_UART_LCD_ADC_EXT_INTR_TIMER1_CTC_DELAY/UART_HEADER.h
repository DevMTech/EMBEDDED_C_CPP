#ifndef _UART_H
#define _UART_H

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#define BAUD 9600
#define BAUDRATE ((F_CPU)/(16UL*BAUD)-1)

//#define len 20
//unsigned char ch[len];
//ch[0]='\0';

void uart_init() // 9600
{	UBRR1H=0x00 ;// (BAUDRATE >> 8);
	UBRR1L=0x67; // for BAUD RATE = 9600
	
	//UBRR1H=(BAUDRATE >> 8); // 0x00
	//UBRR1L=BAUDRATE; // 0x67 = 103
	
	UCSR1B|=(1<<TXEN1)|(1<<RXEN1); /* Enable receiver and transmitter */
	UCSR1B|=(1<<RXCIE1); //  ENABLE RX INTERRUPT
	//UCSR1B|=(1<<RXCIE1)|(1<<TXCIE1); // //  ENABLE RX & TX INTERRUPTS
	UCSR1C|=(1<<UCSZ11)|(1<<UCSZ10)|(1<<USBS1)|(1<<UPM11)|(1<<UPM10); // 8bit data, 2 stop bit, Parity = Odd
	
}

void uart_init_baud(unsigned int MYBAUD)
{
							/* Set baud rate */
	UBRR1H = (unsigned char)(MYBAUD>>8);
	UBRR1L = (unsigned char)MYBAUD;
							
	UCSR1B = (1<<RXEN)|(1<<TXEN); /* Enable receiver and transmitter */
	
	UCSR1B|=(1<<RXCIE1); //  ENABLE RX INTERRUPT
	//UCSR1B|=(1<<RXCIE1)|(1<<TXCIE1); // //  ENABLE RX & TX INTERRUPTS
	UCSR1C|=(1<<UCSZ11)|(1<<UCSZ10)|(1<<USBS1)|(1<<UPM11)|(1<<UPM10); // 8bit data, 2 stop bit, Parity = Odd
							
	//UCSR1C = (1<<USBS1)|(3<<UCSZ10); /* Set frame format: 8data, 2stop bit */
}

unsigned char uart_rx(void) //RECEIVED BY AVR: SENT BY PC
{
	while(!(UCSR1A&(1<<RXC1)));
	
	return UDR1; // DATA COMING INTO UDR1
}

void uart_tx(unsigned char ch) //TRANSMITTED BY AVR: SENT TO PC
{
	
	while(!(UCSR1A&(1<<UDRE1)));

	UDR1=ch; // DATA GOING OUT FROM UDR1
}

/*ISR(USART1_RX_vect) // ECHO BACK RECEIVED CHAR TO TERMINAL AND DISPLAY ON LEDS 
{
	cli(); // DISABLE GLOBAL INTERRUPT
	ch=UDR1;
	PORTC=~(ch-48);
	_delay_ms(20);
	UDR1=ch;
	sei(); // ENABLE GLOBAL INTERRUPT
}*/

#endif
