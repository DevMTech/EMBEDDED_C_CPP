

#include<stdint.h>
#include<stdio.h>

typedef union 
{	uint16_t shortAddr;
	uint32_t longAddr;
}Address;

int main(void)
{

	Address addr;
	
	printf("longAddr  = %#X\n",addr.longAddr);
	printf("shortAddr = %#X\n\n",addr.shortAddr);
	
	addr.shortAddr = 0xABCD;

	printf("longAddr  = 0x%X\n",addr.longAddr);
	printf("shortAddr = 0x%X\n\n",addr.shortAddr);
	
	addr.longAddr = 0xEEEECCCC;
	
	printf("longAddr  = 0x%X\n",addr.longAddr);
	printf("shortAddr = 0x%X\n\n",addr.shortAddr);
	
	addr.shortAddr = 0x1234;

	printf("longAddr  = 0x%X\n",addr.longAddr);
	printf("shortAddr = 0x%X\n\n",addr.shortAddr);

	getchar();

	return 0;

}











