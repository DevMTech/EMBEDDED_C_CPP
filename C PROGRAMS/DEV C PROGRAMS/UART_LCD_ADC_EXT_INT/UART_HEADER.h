#infdef _UART_H
#define _UART_H

#define F_CPU 16000000UL
#include<util/delay.h>

#define B  9600
#define BR (F_CPU/(16UL*B))-1

void uart_init();
unsigned char uart_rx();
void uart_tx(unsigned char ch);

void uart_init()
{
	UBRRH=(BR>>8);
	UBRRL=BR;
	
	UCSR1B|=(1<<RXEN1)|(1<<TXEN1)|(RXCIE1B);
	UCSR1C|=(1<<UCSZ11)|(UCSZ10); //  | (1<<USBS1) | (1<<UPM11) | (1<<UPM10);
}

void uart_tx(unsigned char ch)
{
	while(!(UCSR1A & (1<<UDR1)));
	UDR1=ch;
}

unsigned char uart_rx()
{
	while(!(UCSR1A & (1<<RXC1)));
	return UDR1;
}

#endif
