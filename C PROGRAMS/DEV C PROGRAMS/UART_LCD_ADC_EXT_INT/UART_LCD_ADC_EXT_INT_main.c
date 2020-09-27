#include<avr/io.h>
#include<avr/interrupt.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include<string.h>

#include"LCD_HEADER.h"
#include"UART_HEADER.h"
#include"ADC_HEADER.h"

#define len 16

int main()
{	int val=0, ln=0;
	unsigned char adc_str[10];
	DDRA=0xFF;
	DDRC=0xFF;
	DDRE=0x00;
	//DDRC=0xFF;
	
	lcd_init();
	uart_init();
	adc_init();
	
	sei();
	
	while(1)
	{
		val=adc_ret_val();
		sprintf(adc_str, "%d", val);
		ln=str_len(adc_str);
		adc_str[ln]='\0';
		lcd_cmd(0x01);
		ldc_data(" ADC = ");
		lcd_goto(1,0);
		ldc_string(adc_str);
		_delay_ms(1000);
		
	};
	
	return 0;
}

ISR(UART_RX_vect)
{
	cli();
	uart_string();
	sei();
}

void uart_string()
{
	unsigned char chr=uart_rx();
	unsigned char uart_str[len];
	int i=0, j=0;
	
	while(chr!='\n' && chr!='\r' && (i<len-1))
	{	
		uart_str[i++]=chr;
		PORTC=~(chr-48);
		chr=uart_rx();		
	}
	
	uart_str[i]='\0';
	
	while(uart_str[j]!='\0' && (j<=i))
	{
		uart_tx(uart_str[j++]);
	}
	
	lcd_string(uart_str);
}

void ext_intr_init()
{
	EICR1B=0x00;
	EIMSK|=(1<<INT7)|(1<<INT6);
}

ISR(INT7_vect)
{
	cli();
	PORTC=~PORTC;
	sei();
}

ISR(INT6_vect)
{
	cli();
	PORTC=~PORTC;
	sei();
}
