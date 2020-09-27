#include<stdio.h>

//register int global_var=20; // [Error] register name not specified for 'global_var'
//int *p_global=&global_var;

main()
{
	register int local_var=40; 
	//int *p_local=&local_var;
	
	printf("\n\n\t local register variable, local_var = %d \n\n\n\n", local_var);

	//printf("\n\t Address of x = %p", &local_var);  //	[Error] address of register variable 'local_var' requested
	//printf("\n\t Address of y = %p", &global_var); //	[Error] address of global register variable 'global_var' requested
	
	printf(" Trying to declare a global register varible (outside the main) leads to the following error message: \n\n");
	printf("\t[Error] register name not specified for \'global_var\'\n\n");
	
	printf(" Trying to access the address of a local register varible leads to the following error message: \n\n");
	printf("\t[Error] address of register variable \'local_var\' requested\n\n");
	
	printf(" Trying to access the address of a global register variable leads to the following error message: \n\n");
	printf("\t[Error] address of global register variable 'global_var' requested\n\n");
	
	printf("\n\n Hence, \n\n\t 1. There cannot be a global register variable. Register variables have to be local (i.e. auto) variables.");
	printf("\n\n\t 2. Address of a register variable cannot be aaccessed, as they are not"); 
	printf(" stored in the stack frame of the function but in the internal registers of the CPU.\n\n");

	
	return 0;
} 
