#include <stdio.h>

extern int sum;

void sum_val()
{	int total = 10 + sum;
	printf(" \n\n\t PRINTING FROM INSIDE void sum_val() FUNCTION: \n\n");
	printf("\n\n\t sum = %d \n\n", sum);
	printf("\n\n\t total = %d \n\n", total);

}

void sum_val_change()
{	sum = 1000;
	int total = 10 + sum;
	printf(" \n\n\t PRINTING FROM INSIDE void sum_val_change() FUNCTION: \n\n");
	printf("\n\n\t sum = %d \n\n", sum);
	printf("\n\n\t total = %d \n\n", total);

}
