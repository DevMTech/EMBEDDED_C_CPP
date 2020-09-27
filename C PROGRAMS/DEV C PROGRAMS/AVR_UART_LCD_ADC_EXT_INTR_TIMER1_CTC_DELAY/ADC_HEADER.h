#ifndef _ADC_H
#define _ADC_H

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include<util/delay.h>

void adc_init()
{
	ADCSRA|= (1<<ADEN) | (1<<ADSC) | (1<<ADPS2)  | (1<<ADPS1)  | (1<<ADPS0);
	ADMUX|= (1<<REFS0) | (1<<ADLAR);
}

void adc_led_disp()
{
	DDRC=0XFF;
	
	//while(ADCSRA!=(ADCSRA|(1<<ADIF)));
	while(ADCSRA && (1<<ADIF)==0);
		
		PORTC=ADCH;
		_delay_ms(500);
		
		ADCSRA|= (1<<ADSC);
}

unsigned int ret_adc_val()
{	unsigned int val;

	//while(ADCSRA!=(ADCSRA|(1<<ADIF)));
	while(ADCSRA && (1<<ADIF)==0);
		
		PORTC=ADCH;
		val=ADCH;
		_delay_ms(500);
		
		ADCSRA|= (1<<ADSC);
		return val;
}

#endif
