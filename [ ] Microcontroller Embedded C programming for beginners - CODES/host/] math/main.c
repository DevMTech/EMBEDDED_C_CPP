
#include <stdio.h>
#include "math.h"

int math_add(int n1, int n2)
{
	return n1+n2;
}


int math_sub(int n1, int n2)
{
   return n1-n2;
}


long long int math_mul(int n1, int n2)
{
	return (long long int )n1 * n2 ;
}


float math_div(int n1, int n2)
{
    return (float)n1 / n2;
}

int main(void)
{
	printf("Add : %X\n",math_add(0x0FFF1111 , 0x0FFF1111 ) );

	printf("Mul : %I64x\n",math_mul(0x0FFF1111 , 0x0FFF1111 ) );

	printf("Div : %0.2f\n", math_div(506 , 36));

	return 0;
}
