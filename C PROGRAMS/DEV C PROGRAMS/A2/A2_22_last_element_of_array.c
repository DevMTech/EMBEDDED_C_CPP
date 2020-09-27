#include<stdio.h>

main()
{	int a[5] = {10, 20, 30, 40, 50 };
	
	int *p=*(&a+1) - 1;
	printf(" Expression for the last element of an array: \n\n");
	printf("\t\t *(*(&a+1) - 1) = %d \n\n", *p);
	printf("\n\n This is how is occurs: \n\n");
	printf("\n\n &a \t\t= %p \n\n", &a);
	printf("\n\n &a + 1  \t= %p \n\n", &a + 1);
	printf("\n\n *(&a + 1)  \t= %p \n\n", *(&a + 1));
	printf("\n\n *(&a + 1) - 1 \t= %p \n\n", *(&a + 1)-1);
	printf("\n\n *(*(&a+1) - 1) = %d \n\n", *p);
	
	printf("\n\n Expression for total number of element of an array, a[5]: \n");
	printf("\n\n *(&a + 1) - a \t= %d \n\n", *(&a + 1) - a);

	return 0;
	
}
