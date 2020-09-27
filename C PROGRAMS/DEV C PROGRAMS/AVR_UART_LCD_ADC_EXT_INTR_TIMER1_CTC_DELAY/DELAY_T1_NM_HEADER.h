#ifndef _DELAY_T1_NM_HEADER_H
#define _DELAY_T1_NM_HEADER_H

#include<avr/io.h>
#include<avr/interrupt.h>

//#define F_CPU 16000000
//#include<util/delay.h>

#define MILLI_SEC 1000 // EDIT AS REQ. Units in milli sec. : 1000 for 1 sec, 500 for 0.5s etc.

volatile uint8_t timer_overflow;
volatile uint8_t time;

void delay_millis(int ms);
{
	DDRC = 0xFF; // SET PORT C AS OUTPUT PORT
	PORTC = 0X55;
	time=ms;
	timer_overflow = 0 ;
	
	TCCR1A =0x00; // NORMAL MODE
	
	TCCR1B|=(1<<CS10); // NO PRESCALING
	// TCCR1B|=(1<<0); // CS10 IS BIT 0 OF TCCR1B
	
	TCNT1=0xC17F; // SET FOR 1ms DELAY TILL TIMER OVERFLOWS
	
	TIMSK|=(1<<TOIE1); // SET TIMER1 INTERRUPT ENABLE BIT
	
	sei(); // GLOBAL INTERRUPT ENABLE
	
	//while(timer_overflow <= ms); //  IF UNCOMMENTED, USE ISR_BB FOR THIS LINE, COMMENT OUT ISR_AA
	
	//return 0;
}

ISR(TIMER1_OVF_vect) // ISR_AA
{
	timer_overflow ++;
	
	//if(timer_overflow >= MILLI_SEC)
	
	if(timer_overflow >= time)
	{	PORTC=~PORTC;
		timer_overflow = 0 ;
	}
}

/*
ISR(TIMER1_OVF_vect) // ISR_BB
{
	timer_overflow ++;
	//TIFR|=(1<<TOV1);
}*/


#endif

