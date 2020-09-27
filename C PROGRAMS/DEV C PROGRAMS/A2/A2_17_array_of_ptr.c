#include<stdio.h>

main()
{	int i=0;

	int arr[] = {1,2,3,4,5};
	int b[] = {6,7,8,9,10};
	int *p1=b;
	int *p2=b+1;
	int x = 100;
	

	int (*parr)[5]; 	// a pointer that can point to an entire array of 5 integers
	int *pb[5];			// array of 5 pointers
	
	parr=&arr;
		
	pb[0]=p1;
	pb[1]=p2;
	pb[2]=b+2;
	pb[3]=&x;
	pb[4]=&b[4];
	
	printf(" pb = %p , \t parr = %p \n\n", pb, parr);
	
	printf("sizeof(pb) = %u \t sizeof(parr) = %u \n\n", sizeof(pb), sizeof(parr));
	printf("sizeof(*pb) = %u \t sizeof(*parr) = %u \n\n", sizeof(*pb), sizeof(*parr));
	
	
	for(i=0;i<5;i++)
	{ 
		printf(" pb[%d] \t= %p\n\n",i,pb[i]); 
		printf(" *pb[%d] \t= %d\n\n",i,*pb[i]);
	}	
		
	
	return 0;
}
