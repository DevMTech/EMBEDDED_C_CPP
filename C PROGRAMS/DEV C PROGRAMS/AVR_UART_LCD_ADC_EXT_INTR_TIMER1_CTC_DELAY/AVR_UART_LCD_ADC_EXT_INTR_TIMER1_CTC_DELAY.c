
#include <avr/io.h>
#include<string.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include<util/delay.h>

#include "LCD_HEADER.h"
#include "UART_HEADER.h"
#include "ADC_HEADER.h"
#include "DELAY_CTC_HEADER.h"
#include "DELAY_T1_NM_HEADER.h"

#define BAUD 9600 // CHANGE AS PER REQ.
#define BAUDRATE ((F_CPU)/(16UL*BAUD)-1)
#define len 20

unsigned char ch[len];
unsigned uart_ch;


int main(void)
{	//char ch, str[50];
	//RS R/W D7 D6 D5 D4 D3 D2 D1 D0
	//unsigned char CH;
	unsigned char str_val[10];
	unsigned int val=0;
	ch[0]='\0';
	
	DDRC=0XFF; 		// SET PORTC AS OUTPUT PORT
	PORTC=0XFF;		// 
	
	DDRA= 0xFF; //Configure Port A as output
	
	DDRE=0x00;				//SET PORTE AS INPUT PORT : Switch as input 
	PORTE=0xFF;				//Pull up
	
	lcd_init();
	uart_init(); // DEFAULT SETTING, Br = 9600
	//uart_init_baud(BAUDRATE); // FOR CUSTOM BAUDRATE
	adc_init();
	
	EIMSK=0x80;				//ext interrupt enabled
	
	sei();
	
    while(1)
  	{		  			
		lcd_string("HELLO");
		lcd_goto(1,0);
		lcd_string("WORLD!!");
		_delay_ms(2000);
		
		adc_led_disp();
		/*val = ret_adc_val();
		sprintf(str_val, "%u", val);
		//convert val to a string literal and sent to lcd_string
 		lcd_string(str_val);*/
		
		_delay_ms(2000);
				
    }
}

ISR(USART1_RX_vect)
{	
	cli(); // DISABLE GLOBAL INTERRUPT
	//uart_ch = uart_rx();
	//uart_string_rx_tx(uart_ch);
	uart_string_rx_tx(URD1);
	sei(); // ENABLE GLOBAL INTERRUPT
}

void uart_string_rx_tx(unsigned char chr)
{	
	unsigned char schar[2];
		
	unsigned int i=1, j=0, k=0;
		ch[0]=chr;
		
		//uint8_t clr_buf = UDR1; // Clear the receive buffer
		
		//while(ch[i]!=0x0d)
		while(ch[i-1]!='\r' && i<len)
		{	ch[i]=UDR1;
			//ch[i]=uart_receiver();//RECEIVED BY AVR: SENT BY PC
			PORTC=~(ch[i]-48);
			i++;
			//ch[i]='\0';
		}
		//while((ch[i]!=27 || ch[i]!='\n' || ch[i]!='\r') && (i<len-1));
		
		ch[--i]='\0';
		_delay_ms(50);
		uart_tx('\n');
		//UDR1='\n';
		_delay_ms(50);
		uart_tx('>');
		//UDR1='>';
	
		//uart_tx(10); // LF - LINE FEED '\n' - GO TO NEXT LINE
		//uart_tx(13); // CR - CARRIAGE RETURN - GO TO BEGINNING OF THE LINE
		
		//
		//for(j=0;(ch[j]!='\0')&&j<len;j++)
		for(j=0; j<=i && (ch[j]!='\0'); j++)
		{	
			//UDR1=ch[j];	
			uart_tx(ch[j]);
			_delay_ms(50);
			
			//if(k>15 && k<31) { lcd_goto(1,0);}
			
			//if(k>31) { k=0; lcd_goto(0,0); }
			
			schar[0]=ch[j];
			schar[1]='\0';
			lcd_string(schar);
			
			//k++;
		}
		
	}
	//return 0;
}

ISR(INT7_vect)
{ 
	//DDRA=0xff; //buzzer
	//PORTA=0xff;
	
	cli();
 if((PINE & 0x80)==0x80)
 {	 delay(10000);
	 if((PINE & 0x80)==0x80) 
	 PORTC=0xff;
	}
 if((PINE & 0x80)==0x80)
 { 
	 delay(10000);
	 if((PINE & 0x80)==0x80)
	 PORTC=~PORTC; // TOGGLE LEDS ON PORTC
 } 
 sei();
 
}


/*ISR(USART1_RX_vect)
{
	unsigned int i=0, j=0;
	uart_ch=uart_rx();
	while(uart_ch!='\r')
	{	ch[i++]=uart_ch;
		uart_ch=uart_rx();
		// lcd_cmd(0x01); // clear lcd  display
		
	}
	ch1[i]='\0';
	_delay_ms(500);
	j=0;
	while(ch[i]!='\0')
	{	lcd_data(ch[j++]);
		//uart_tx(ch[j++]);
	}
}*/

