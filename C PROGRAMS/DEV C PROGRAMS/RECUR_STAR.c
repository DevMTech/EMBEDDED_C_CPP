#include <stdio.h>

int print_star( int n)
{
	int i = 0;
	if ( n > 1)
	print_star(n-1);
	for (i = 0; i < n; i++)
	printf("*");
	printf("\n");
}

main()
{ 	
	print_star(3);
}

