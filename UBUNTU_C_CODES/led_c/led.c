/*=====================================================
|   TASK:  TOGGLING THE LED ATTACHED TO A PARTICULAR PORT
|   DIFFICULTY LEVEL: VERY BASIC
|   Author:  BISWARUP BANERJEE
|   Language:  EMBEDDED C
|   To Compile:  RUN THE SCRIPT AS MENTIONED BY THE AUTHOR
|
|   Date:  June 2017
|	
	Setting Up AVR-GCC toolchain and avrdude To Program An AVR Development Board In UBUNTU
	http://www.linuxandubuntu.com/home/setting-up-avr-gcc-toolchain-and-avrdude-to-program-an-avr-development-board-in-ubuntu
	
	//sudo apt-get install avrdude gcc-avr avr-libc avrdude-doc codeblocks
	
	sudo apt-get install binutils gcc-avr avr-libc uisp avrdude flex byacc bison avrdude-doc
	
	
	contents of 'compile_script':
	avr-gcc -g -Os -mmcu=“microcontroller” -c “filename”.c
	avr-gcc -g -mmcu=“microcontroller” -o “filename”.elf “filename”.o
	avr-objcopy -j .text -j .data -O ihex “filename”.elf “filename”.hex
	avr-size --format=avr --mcu=“microcontroller” “filename”.elf ​
	
	Here the filename that we want to compile is: led.c and 
	the microcontroller is: atmega32​So the code becomes :- 
	
	avr-gcc -g -Os -mmcu=atmega32 -c led.c
	avr-gcc -g -mmcu=atmega32 -o led.elf led.o
	avr-objcopy -j .text -j .data -O ihex led.elf led.hex
	avr-size --format=avr --mcu=atmega32 led.elf 
	
	add permisions:
	sudo chmod 755 compile_script
	
	contents of 'upload_script':
	avrdude -c arduino -p m32 -P /dev/ttyUSB0 -b 19200 -U flash:w:led.hex
	
	
	add permisions:
	sudo chmod 755 upload_script
	
	
	flash code to AVR board:
	sudo ./upload_script
	
	Starting out with avrdude
	https://www.ladyada.net/learn/avr/avrdude.html
	https://linux.die.net/man/1/avrdude
	https://medium.com/@ppatil/avr-programing-using-avrdude-in-ubuntu-93734c26ad19
	
	
---------------------------------------------------------------------------------------------------------------------------

================================================*/
#ifndef F_CPU
#define F_CPU 16000000UL // or whatever may be your frequency
#endif

#include <avr/io.h>                    // adding header files
#include <util/delay.h>                // for _delay_ms()

int main(void)
{
   DDRC = 0x01;                       // setting DDR of PORT C
   while(1)
   {
       // LED on
       PORTC = 0b00000001;            // PC0 = High = LED attached on PC0 is ON
       _delay_ms(500);                // wait 500 milliseconds

       //LED off
       PORTC = 0b00000000;            // PC0 = Low = LED attached on PC0 is OFF
       _delay_ms(500);                // wait 500 milliseconds
   }
}