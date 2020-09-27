#infdef _LCD_H
#define _LCD_H

#define F_CPU 16000000UL
#include<util/delay.h>

void lcd_init();
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void set_bit(unsigned int);
void clear_bit(unsigned int);
void enable();
void lcd_goto(unsigned int, unsigned int);
void lcd_string(char *);

void lcd_init()
{
	lcd_cmd(0x28);
	lcd_cmd(0x14);
	lcd_cmd(0x06);
	lcd_cmd(0x0E);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
}

void lcd_cmd(unsigned char ch)
{
	PORTA=(ch&0xF0));
	clear_bit(0);
	enable();
	
	ch=(ch<<4);
	
	PORTA=(ch&0xF0));
	clear_bit(0);
	enable();
}
void lcd_data(unsigned char ch)
{
	PORTA=(ch&0xF0));
	set_bit(0);
	enable();
	
	ch=(ch<<4);
	
	PORTA=(ch&0xF0));
	set_bit(0);
	enable();
}

void set_bit(unsigned int bit)
{
	PORTA|=(1<<bit);
}

void clear_bit(unsigned int bit)
{
	PORTA&=~(1<<bit);
}


void enable()
{
	set_bit(2);
	_delay_ms(20);
	clear_bit(2);
	_delay_ms(20);
}

void lcd_goto(unsigned int x, unsigned int y)
{
	if(x==0) {lcd_cmd(0x80|y);}
	if(x==1) {lcd_cmd(0xC0|y);}
}

void lcd_string(char * str)
{
	while(*str!='\0')
	{
		lcd_data(*str++);
	}
}

#endif
