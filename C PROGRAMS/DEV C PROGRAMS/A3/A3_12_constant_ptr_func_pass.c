#include<stdio.h>

void test(const int* );
void test2(int *);

main()
{	int a =10, b=20;
	int *p; 		// pointer to an int (pointer target type = int)
	const int *pc; 	// pointer to a const int (pointer target type = const int)
	p=&a; 
	pc=&b;
	
	printf("\n\n\t * int pointer sent to \t void test(const int* ptr)\n\n");
	test(p);
	printf("\n\n\t const * int pointer sent to \t void test(const int* ptr)\n\n");
	test(pc);
	
	printf("\n\n\t * int pointer sent to \t void test2(int* ptr)\n\n");
	test2(p);
	printf("\n\n\t const * int pointer sent to \t void test2(int* ptr)\n\n");
	test2(pc); 	// [Note] expected 'int *' but argument is of type 'const int *'
				//[Warning] passing argument 1 of 'test2' discards 'const' qualifier from pointer target type
				

	printf("\n\n\n\n\tHence, sending a pointer with pointer target type 'int' or 'const int' to a function"); 
	printf(" where a pointer with pointer target type 'const int' is expected is legitimate.");
	
	printf("\n\n\n\n\tBut trying to sending a pointer with pointer target type 'const int' to a function"); 
	printf(" where a pointer with pointer target type 'int' is expected leads to the following error:");
	
	printf("\n\n\t[Note] expected 'int *' but argument is of type 'const int *'");
	printf("\n\n\t[Warning] passing argument 1 of 'test2' discards 'const' qualifier from pointer target type\n\n\n\n");

	return 0;
}

void test(const int* ptr)
{ 	printf("\n\n\t PRINTING FROM INSIDE \t void test(const int* ptr)\n\n");
	printf("\n\n\t address of variable pointed to by ptr = %p", ptr);
	printf("\n\n\t value of variable pointed to by ptr = %d\n\n\n\n", *ptr);

}


void test2(int * ptrc)
{	printf("\n\n\t PRINTING FROM INSIDE \t void test2(int * ptrc)\n\n");
	printf("\n\n\t address of variable pointed to by ptrc = %p", ptrc);
	printf("\n\n\t value of variable pointed to by ptrc = %d\n\n\n\n", *ptrc);
}
