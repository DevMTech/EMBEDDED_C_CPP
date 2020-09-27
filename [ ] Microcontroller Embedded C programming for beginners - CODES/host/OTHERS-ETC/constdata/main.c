



#include <stdio.h>
#include <stdint.h>

uint8_t const data = 10;

int main(void)
{

	printf("\nValue = %u\n",data);

	uint8_t *ptr = (uint8_t*)&data; //uint8_t const *

	//*ptr = 50; // ERROR : illegal statement !!! // CAN'T CHANGE const value

	printf("\nValue = %u\n", *ptr); //	printf("Value = %u\n",data);

	getchar();
}
