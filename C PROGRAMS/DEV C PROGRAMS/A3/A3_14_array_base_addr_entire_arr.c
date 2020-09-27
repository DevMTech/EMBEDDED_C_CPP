#include<stdio.h>

int * ret_arr_base_addr();
int * ret_entire_arr();


int main()
{
	int * p, (*parr)[10], i=0;
	//int * p = arr, (*parr)[10] = &arr;
	
	parr=ret_entire_arr();
	
	p=ret_arr_base_addr();
	
	
	printf("\tsizeof(p) = %u bytes\n\n", sizeof(p));
	printf("\tsizeof(parr) = %u bytes\n\n", sizeof(parr));
	
	for(i=0; i<10; i++)
	{   printf("  p[%d] = %p\t",i,p+i);
		printf("*parr[%d] = %p\n\n",i,*parr+i);
		//printf("*p[%d] = %d\t",i,*(p+i));
		//printf("**parr[%d] = %d\n\n",i,*(*parr+i)); //*(*parr+i)==(**parr + i) 
		//printf("\t**parr[%d] = %d\n\n",i,(**parr + i));
	}
	
	printf("\n\n\n");
		
		for(i=0; i<10; i++)
	{   //printf("  p[%d] = %p\t",i,p+i);
		//printf("*parr[%d] = %p\t",i,*parr+i);
		printf("*p[%d] = %d\t",i,*(p+i));
		printf("**parr[%d] = %d\n\n",i,*(*parr+i)); //*(*parr+i)==(**parr + i) 
		//printf("\t**parr[%d] = %d\n\n",i,(**parr + i));
	}
	
	return 0;
}

int * ret_arr_base_addr()
{
	static int arr_a[]= {23,15,22,32,46,58,63,72,84,94};
	//int *p = &arr_a[0];
	int *p = arr_a; // pointer to the 0th element of an array
	printf("\tsizeof(p) inside ret_arr_base_addr() = %u bytes\n\n", sizeof(p));

	//return &arr_a[0];
	return arr_a; // arr_a <==> &arr_a[0] <==> p
	//return p;
}

int * ret_entire_arr()
{
	static int arr_b[]= {115,127,131,148,152,160,178,189,193,204};
	int (*parr)[10] = &arr_b; //  pointer to an entire array of 10 integers	
	printf("\tsizeof(parr) inside ret_entire_arr() = %u bytes\n\n", sizeof(parr));
	return *parr;
	//return &arr_b;
}
