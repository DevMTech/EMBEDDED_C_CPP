

#ifndef _LCD_H
#define _LCD_H

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include<util/delay.h>
//#define BAUD 9600
//#define BAUDRATE ((F_CPU)/(16UL*BAUD)-1)


void lcd_init(void);					//Initializing the LCD to work in the 4-bit
void lcd_cmd(unsigned char);				//Sends a command to LCD
void lcd_data(unsigned char);				//Sends a letter to LCD
void lcd_string(char *);				//Sends a string to LCD
void set_bit(unsigned int);				//Data Register select or Used in Enable
void clear_bit(unsigned int);				//Command Register select or Used in Enable
void enable(void);					// To give a pulse or enable pulse
void lcd_goto(unsigned int x, unsigned int y);//Moves the cursor to the specified address
void lcd_showvalue(unsigned char);			//Coverts a number to a string of digits

void lcd_init()
{
	lcd_cmd(0x28);	//DL=1 means a full 8 bits being utilized
	//N=1 means 2 lines or more
	//F=0 means that 5x7 dot characters are used
	
	//N=0 means 1 line
	//F=1 means 5x10 dot characters are used
	clear_bit(0); // PA0 --> RS cleared to 0 -> write instruction to LCD
	enable(); // PA2 --> send Enable pulse through PA2 pin to E pin (Pin 2) of LCD
	
					//RS R/W D7 D6 D5 D4  D3     D2     D1  D0
	lcd_cmd(0x14);  //0  0   0  0  0  1   S/C=0  R/L=1  —   —  => 0 0 0 0 0 1 0 1 0 0 = 0x14 
					//cursor moves from left to right
					//S/C = 0: Cursor moves
					//R/L = 1: Cursor shift to the right

 	lcd_cmd(0x06);	// CURSOR MOVES FROM LEFT TO RIGHT(I/D=1), WITH NO DISPLAY SHIFT (S=0)
	    			// 0 0 0 0 0 0 0 1 I/D=1 S=0 => 0 0 0 0 0 0 0 1 1 0 = 0x06 
	    				
				// Entry mode set : Sets cursor move direction and specifies display shift.
			  	// I/D=1 means the cursor position is incremented (moves left to right).
				// S=0 means No display shift: normal operation, the display remains still, and the cursor moves.
					
				//S=1 means the display moves with the cursor
				//I/D=0 means the cursor position is decremented (moves right to left).
				// These operations are performed during data write and read.
			

	lcd_cmd(0x0e); // Display on/off control
	    		// Sets entire display (D=1) on, cursor on (C=1), and no blinking of cursor position character (B=0).
			   	// 0 0 0 0 0 0 1 D=1 C=1 B=0 =>  0 0 0 0 0 0 1 1 1 0 = 0x0e 
			   
			   	
	lcd_cmd(0x01);	// Clear Display
				// 0 0 0 0 0 0 0 0 0 1 = 0x01
				// Clears entire display and sets DDRAM address to 0 in address counter.
		
	lcd_cmd(0x80); // Set DDRAM address
				//0 0 1 ADD ADD ADD ADD ADD ADD ADD => 0 0 1 0 0 0 0 0 0 0 = 0x80
				// DDRAM data is sent and received after this setting.	     
}

void enable() // send Enable pulse
{
	set_bit(2);// PORTA= PORTA|(1<<bit); // PA2 is set to 1
	_delay_ms(20);
	clear_bit(2);// PORTA= PORTA&(~(1<<bit)); // PA2 is cleared to 0
	_delay_ms(20);
}

void set_bit(unsigned int bit)
{
	PORTA= PORTA|(1<<bit);
}

void clear_bit(unsigned int bit)
{
	PORTA= PORTA&(~(1<<bit));
}

void lcd_cmd(unsigned char CH)
{
	PORTA=(CH & 0xF0); //Upper Nibble (D7-D4)
	clear_bit(0);
	enable();
	
	CH=CH<<4;			//Lower nibble shifted to D7-D4 and sent to PA7-PA5
	PORTA=(CH & 0xF0);
	clear_bit(0);
	enable();
}

void lcd_data(unsigned char CH)
{
	PORTA=(CH & 0xF0); //Upper Nibble (D7-D4)
	set_bit(0);
	enable();
	
	CH=CH<<4;			//Lower nibble shifted to D7-D4 and sent to PA7-PA5
	PORTA=(CH & 0xF0);
	set_bit(0);
	enable();
}

void lcd_string(char *str)
{
	while(*str!='\0')
	{
		lcd_data(*str++);
	}
}

void lcd_goto(unsigned int x, unsigned int y)
{
	if(x==0) lcd_cmd(0x80|y);
	if(x==1) lcd_cmd(0xC0|y);
}

void lcd_showvalue(unsigned char num)
{
	unsigned char H=0,T=0,O=0;
	H=num/100;
	T=(num - (H*100))/10;
	O=(num - (H*100) - (T*10));
	
	lcd_data(H+48);
	lcd_data(T+48);
	lcd_data(O+48);
}


#endif
