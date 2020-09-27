

#include<stdio.h>

long long int  g_data = 0xFFEEABCD22442345; // 16 * 4 = 64 BITS

int main(void)
{

	char *pAddress1;
	pAddress1 = (char*)&g_data;
	printf("CHAR Value at address \t\t %p is : %X\n", pAddress1, *pAddress1);
	
	short *pAddress3;
	pAddress3 = (short*)&g_data;
	printf("SHORT INT Value at address \t %p is : %X\n", pAddress3, *pAddress3);
	
	int *pAddress2;
	pAddress2 = (int*)&g_data;
	printf("INT Value at address \t\t %p is : %X\n", pAddress2, *pAddress2);
	printf("INT Value at address \t\t %p is : %X\n", pAddress2+1, *(pAddress2+1));
	
	long *pAddress4;
	pAddress4 = (long*)&g_data;
	printf("LONG INT Value at address \t %p is : %I64X\n", pAddress4, *pAddress4);
	
	long long *pAddress5;
	pAddress5 = (long long*)&g_data;
	printf("LONG LONG INT Value at address   %p is : %I64X\n", pAddress5, *pAddress5);

 return 0;
}
