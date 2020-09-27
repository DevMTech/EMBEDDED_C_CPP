#ifndef _DELAY_MILSEC_H
#define _DELAY_MILSEC_H

#include <avr/io.h>
#include <avr/interrupt.h>

void delay_milsec(int ms)
{
	int i;
	TCNT1 = 0x00;
	TCCR1A = 0x00;
	TCCR1B|=(1<<WGM12)|(1<<CS10); //TCCR1B = 0x09; // NORMAL CTC MODE, WITHOUT PRESCALER
	OCR1A = 0x3E7F; // clear TIMER1 on compare with 15999, i.e. TIMER1 RESET AT 15999, For 1ms delay
	
	for(i = 0; i <ms; i++)// repeat x times for x ms delay
	{
		while ((( TIFR &(1<<OCF1A))!= 0x10)); // CHECK FOR OCF1A FLAG TO BE RAISED
		
		TCNT1 = 0x00; // RE-INITIALIZE TCNT1
		TIFR|=(1<<OCF1A);//TIFR= 0x10;
	}
}

/* // TIMER 0 CTC MODE 
void delay_milsec( unsigned long ms)
{
	unsigned long i;
	TCNT0=0x00;								//counter
	TCCR0|=(1<<CS00)|(1<<WGM01);			//ctc & no prescaling
	OCR0=0xA0; 								//counter final
	for(i=0;i<ms;i++)
	{
		while((TIFR & (1<<OCF0))!=0x02);
		TCNT0=0x00;
		TIFR|=(1<<OCF0);
		
	}
}
*/

#endif
