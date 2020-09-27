#include<stdio.h>
main()
{	int *pi, i = 10;
	float *pf, f = 10;
	short int *ps, s = 10;
	long int *pl, l = 10;
	char *pch, ch = 10;
	double *pd, d = 10.0;

	pi=&i;
	printf(" pint = &int \t= %d \n\n", *pi);
	pi=&f;
	printf(" pint = &float \t= (print as int) \t%d \n\n", *pi);
	printf(" pint = &float \t= (print as float) \t%f \n\n", *pi);
	pi=&s;
	printf(" pint = &short \t= (print as int) \t%d \n\n", *pi);
	//printf(" pint = &short = (print as short) \t%d \n\n", *pi);
	pi=&l;
	printf(" pint = &long \t= (print as int) \t%d \n\n", *pi);
	printf(" pint = &long \t= (print as long) \t%ld \n\n", *pi);
	pi=&ch;
	printf(" pint = &char \t= (print as int) \t%d \n\n", *pi);
	printf(" pint = &char \t= (print as char) \t%c \n\n", *pi);	
	pi=&d;
	printf(" pint = &double = (print as int) \t%d \n\n", *pi);
	printf(" pint = &double = (print as double) \t%lf \n\n", *pi);
	return 0;
	
	 
}
