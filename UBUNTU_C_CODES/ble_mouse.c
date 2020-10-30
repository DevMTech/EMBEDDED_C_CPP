/*
Touchscreen based bluetooth mouse

Resistive touch screen based wireless mouse: ATtiny13, HC-05 Bluetooth
https://blog.vinu.co.in/2013/01/resistive-touch-screen-based-wireless.html

 https://github.com/vinodstanur/resistive_touchpad_as_wireless_mouse
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Simulate Mouse Events In Python

https://nitratine.net/blog/post/simulate-mouse-events-in-python/

https://www.youtube.com/c/PyTutorials/playlists

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

microcontroller: ATTiny13
author: Vinod S
email:  vinodstanur at gmail dot com
date:   12/1/2013
homepage:    http://blog.vinu.co.in
 
compiler: avr-gcc
Copyright (C) <2013>  <http://blog.vinu.co.in>

*/
#include <stdio.h>

unsigned char data;

void uart_send_byte(unsigned char data)
{
	unsigned char i;
	printf("%c", data);
	
/*	printf(" (%d) : LSB ", data);
	
	for (i = 0; i < 8; i++) 
	{	if (data & 1)
			printf("1");
		else
			printf("0");
		
		data >>= 1;
	}
	printf(" MSB ; \n");
*/
}

void print(char *p)
{
	while (*p) 
	{	uart_send_byte(*p++);
	}
}

void uart_print_num(int i)
{
	if (i < 0) 
	{	uart_send_byte('-');
		i *= -1;
	} 
	else if (i == 0) 
	{	uart_send_byte('+');
		uart_send_byte('0');
		return;
	} 
	else
		uart_send_byte('+');
	
	char count = 0;
	unsigned char b[5] = { 0 };
	while (i) {
		b[count++] = i % 10;
		i /= 10;
	}
	for (count = 4; count >= 0; count--)
		uart_send_byte(b[count] + '0');
}

int main()
{
	int x, y;

	char a = 0;
	
	//while (1) 
	{

		x = 255;

		y = 15;
		if (x < 900 && y < 900) 
		{
			print("X: ");
			uart_print_num(x);
			
			printf("\n");
			uart_send_byte(' ');			
			printf("\n");
			
			print("Y: ");
			uart_print_num(y);
			uart_send_byte('\n');
		}
	}

	return 0;
}
