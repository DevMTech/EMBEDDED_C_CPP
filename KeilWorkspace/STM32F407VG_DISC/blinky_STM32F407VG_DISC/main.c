//#include "Board_LED.h"
//#include "Board_Buttons.h"
#include <stdint.h> // uint32_t . ..

#define BASE_ADDRESS_OF_SRAM 0x20000000
#define BASE_ADDRESS_OF_FLASH 0x08000000

// Little Endian = LSB at Lowest Address
// 0x17 stored as 0x 00 00 00 17
// 0x12345678 stored as 0x 78 56 34 12

// GLOBAL VARIABLES ALWAYS STORED IN RAM MEMORY

char const my_FLASH_data[] = "FREERTOS"; // const: read-only data; stored in FLASH memory

char my_RAM_data[] = "embedded programming"; // Global; stored from starting address of RAM memory

int value = 0x12345678; // x V 4 . = 0x78 0x56 0x34 0x12 // uint32_t

void ram_read()
{	uint32_t* ram_ptr = (uint32_t*) BASE_ADDRESS_OF_SRAM; // Embedded RAM Memory Base Address
	
	value = *(ram_ptr); // 0x45455246 = EERF // F R E E = 0x46 0x52 0x45 0x45
}

void flash_read()
{	uint32_t* flash_ptr = (uint32_t*) 0x080003E0; 
	// uint32_t* flash_ptr = (uint32_t*) BASE_ADDRESS_OF_FLASH; // FLASH Memory Base Address
	
	value = *(flash_ptr);
}

/*
void delay(void)
{
	uint32_t i = 0;
	
	// for(; i < 500000; i++);
		
}

void func3()
{
	void (*func_ptr) (void) = 0x00000000;
	
	// func_ptr();
	
	void (*func_ptr1) (void) = &delay;
	
	func_ptr1();
	
}

void func2()
{
	func3();
}

void func1()
{
	func2();
}
*/

int main(void)
{	
	char data;
	data = my_RAM_data[0];
	
	data = my_FLASH_data[0];
	
	for(int i = 0; i < sizeof(my_FLASH_data); i++)
	{
		*((uint8_t*)BASE_ADDRESS_OF_SRAM + i) =  my_FLASH_data[i];
	}
	
	ram_read();
	flash_read();
	
	/*
	func1();
	LED_Initialize();
	Buttons_Initialize();
	
	
	while(1)
	{	
		if(Buttons_GetState() == 1) // 1 = BUTTON PRESSED
		{
			LED_On(0);
			delay();
			LED_On(1);
			delay();
			LED_On(2);
			delay();
			LED_On(3);
			delay();	
		}
		
		if(Buttons_GetState() == 0)
		{
			LED_Off(0);
			delay();
			LED_Off(1);
			delay();
			LED_Off(2);
			delay();
			LED_Off(3);
			delay();
		}
	}
	*/
	
	return 0;
	
}