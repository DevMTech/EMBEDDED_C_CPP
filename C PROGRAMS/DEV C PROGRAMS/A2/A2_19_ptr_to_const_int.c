#include<stdio.h>

main()
{
	const int x=10; 
	printf("\n\n\n initial value of const int x (declared in local scope):\n");
	printf("\n\n x = %d\n\n",x);
	
	int *p;
	p=&x; 
	*p=20; 
	
	printf(" value of x after a new value is assigned to *p (i.e. pointer to x) :\n");
	printf("\n\n x = %d\n\n",x);
	
	
	printf(" Hence the value of a constant variable declared in the local scope\n can be changed using a pointer.\n\n");
	printf(" But a constant variable declared in the global scope\n will not allow its value to be changed later by a pointer.\n\n");
		
	return 0;
}
