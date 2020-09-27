#include<stdio.h>

int extra = 100; // accessible to all functions following it


main()
{	extern int sum;

	sum_val();
	
	sum = 100;
	
	sum_val();
	
	sum_val_change();
	
	return 0;
}



void sum_val()
{	extern int sum;

	int total = sum + extra;
	
	printf("\n\n\t PRINTING FROM INSIDE void sum_val() FUNCTION: \n\n");
	printf("\n\n\t sum = %d \n\n", sum);
	printf("\n\n\t extra = %d \n\n", extra);
	printf("\n\n\t total = %d \n\n", total);

}

int sum = 50; // accessible to main() and sum_val() as extern variable

void sum_val_change()
{	sum = 1000;
	extra = 5000; 
	int total = sum + extra;
	
	printf("\n\n\t PRINTING FROM INSIDE void sum_val_change() FUNCTION: \n\n");
	printf("\n\n\t sum = %d \n\n", sum);
	printf("\n\n\t extra = %d \n\n", extra);
	printf("\n\n\t total = %d \n\n", total);

}
