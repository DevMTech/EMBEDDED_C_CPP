

#include<stdint.h>
#include<stdio.h>

long long int  g_data = 0xFFEEABCD22442345; // 16 * 4 = 64 BITS

typedef union 
{	
	uint16_t shortAddr;
	uint32_t longAddr;
	
}Address;

typedef struct //DataSet
{	
	char  data_char;
	short data_short;
	int   data_int;
	long  data_long;
	
	
}DataSet;


void displayStructMembers(DataSet);

int main(void)
{	

	
	
	DataSet data; // struct DataSet data;

	data.data_char  = 0x45;	
	data.data_int  = 0X89ABCDEF;
	data.data_long  = 0x12345678;
	data.data_short  = 0x2468;
	
	displayStructMembers(data); // passing struct

	char ch = 0x88;

	uint8_t *ptr, *pChar, *pInt;

	ptr = (uint8_t*)&data;
	
	pChar = (char*)&ch;
	

	uint32_t totalSize = sizeof(data); // sizeof(struct Dataset);
	
	
	
	 
	
	printf("\n\n=====================================\n");
	printf("\t  Memory address      Content ");
	printf("\n=====================================");

	uint32_t i;
	
	uint8_t byteCount = 16; // 4; going 4 extra bytes to find char ch defined in memory
	
	ptr-=byteCount;
	
	for(i = 0 ; i < totalSize+byteCount ; i++)
	{
		printf("\n %d)\t %p      0x%X", i, ptr, *ptr);
		ptr++;
		
		if(i%4==3)
			printf("\n-------------------------------------");
	}
	printf("\n=====================================\n");
	
	printf("\nTotal memory consumed by this struct variable = %I64u bytes\n", totalSize); 

	printf("\n byteCount \t: addr. = %p     contents = 0x%X \t %d", &byteCount, byteCount, byteCount);
	printf("\n i \t\t: addr. = %p     contents = 0x%X \t %d", &i, i, i);
	printf("\n *totalSize \t: addr. = %p     contents = 0x%X \t %d", &totalSize, totalSize, totalSize);
	printf("\n ch \t\t: addr. = %p     contents = 0x%X \t %c \n\n", pChar, *pChar, ch);

//	for(i=0; i < byteCount; i++)
//	{
//		printf("\n i: \t\t addr. = %p     contents = 0x%X \t %d", &i, i, i);
//	}
	
	
	printf("\n\n*********************************************************************************\n\n");

	
	long long *pAddress5;
	pAddress5 = (long long*)&g_data;
	printf("LONG LONG INT \tValue at address %p is : %I64X \t-> reads 8bytes\n", pAddress5, *pAddress5);
	
	
	char *pAddress1;
	pAddress1 = (char*)&g_data;
	printf("CHAR \t\tValue at address %p is : %X \t\t\t-> reads 1byte\n", pAddress1, *pAddress1);
	
	short *pAddress3;
	pAddress3 = (short*)&g_data;
	printf("SHORT INT \tValue at address %p is : %X \t\t\t-> reads 2bytes\n", pAddress3, *pAddress3);
	
	int *pAddress2;
	pAddress2 = (int*)&g_data;
	printf("INT \t\tValue at address %p is : %X \t\t-> reads 4bytes\n", pAddress2, *pAddress2);
	printf("INT \t\tValue at address %p is : %X \t\t-> reads 4bytes\n", pAddress2+1, *(pAddress2+1));
	
	long *pAddress4;
	pAddress4 = (long*)&g_data;
	printf("LONG INT \tValue at address %p is : %I64X \t\t-> reads 4bytes\n", pAddress4, *pAddress4);
	printf("LONG INT \tValue at address %p is : %I64X \t\t-> reads 4bytes\n", pAddress4+1, *(pAddress4+1));



	printf("\n\n*********************************************************************************\n\n");
	
	
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



void displayStructMembers(DataSet dataS)
{
	printf("\n data_char  = %X", dataS.data_char);
	printf("\n data_short = %X", dataS.data_short);
	printf("\n data_int   = %X", dataS.data_int);
	printf("\n data_long  = %X", dataS.data_long);
}
