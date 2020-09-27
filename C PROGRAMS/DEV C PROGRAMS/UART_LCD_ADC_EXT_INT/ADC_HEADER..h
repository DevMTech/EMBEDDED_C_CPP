#infdef _ADC_H
#define _ADC_H

#define F_CPU 16000000UL
#include<util/delay.h>

void adc_init()
{
	ADCSRA|=(1<<ADEN)|(1<<ADSC)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	ADMUX|=(1<<ADLAR)|(1<<REFS0);
}

int adc_ret_val()
{	int val=0;
	while(!(ADCSRA&(1<<ADIF)));
	val=ADCH;
	PORTC=(val);
	ADCSRA|=(1<<ADSC);
	return val;
}

#endif
