#include<stdio.h>
const int y=10; // global
main()
{
	const int x=10; 
	printf(" initial value of const int x (x is a local variable):\n");
	printf(" x = %d\n",x);
	int *p;
	p=&x; 
	*p=20; 
	printf(" value of x after a new value is assigned to *p (i.e. pointer to x) :\n");
	printf(" x = %d\n\n\n",x);
	
	printf(" initial value of const int y :\n");
	printf(" y = %d\n",y);
	int *q=&y;
	/*DO NOT EXECUTE THE FOLLOWING LINES, ELSE THE .EXE FILE WILL CRASH*/
	//*q=20;
	//printf(" value of y after a new value is assigned to *q (i.e. pointer to y) :\n");
	//printf(" y = %d\n",y);
	
	return 0;
}
