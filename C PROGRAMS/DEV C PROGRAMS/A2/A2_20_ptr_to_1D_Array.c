#include<stdio.h>

main()
{	int i=0, j=0;
	int arr[3][4] =  {1,2,3,4,5,6,7,8,9,10,11,12}; 
	int (*p)[4]; // a pointer that holds the address of a 1D array of 4 elements
	p=arr;
	
	
	printf(" sizeof(int) \t= %u bytes \n\n", sizeof(i));
	printf(" sizeof(p) \t= %u bytes \n\n", sizeof(p)); 
	printf(" sizeof(*p) \t= %u bytes \n\n", sizeof(*p)); //size of 4 integers = 4x4 = 16 bytes
	printf(" sizeof(**p) \t= %u bytes\n\n\n\n\n", sizeof(**p)); // size of 1 integer = 4 bytes
	
	
	printf(" p \t\t= %p \n\n", p); // p points to the entire 0th 1D array = row 0
	printf(" value of p = *p = %p \n\n", *p);
	printf(" value of *p = **p = arr[0][0] = %d \n\n\n", **p);
	
	
	printf(" p+1 \t\t= %p \n\n", p+1); // p+1 points to the entire 1st 1D array = row 1
	printf(" value of (p+1) = *(p+1) = %p \n\n", *(p+1));
	printf(" value of *(p+1) = **(p+1) = arr[1][0] = %d \n\n\n", **(p+1));
	
	
	printf(" p+2 \t\t= %p \n\n", p+2); // p+1 points to the entire 2nd 1D array = row 2
	printf(" value of (p+2) = *(p+2) = %p \n\n", *(p+2));
	printf(" value of *(p+2) = **(p+2) = arr[2][0] = %d \n\n\n", **(p+2));
	
	
	printf("\n\n Hence, \n ");
	printf(" (p+i) points to the ith row \n"); //= &arr[0]
	printf(" *(p+i) points to the 0th element of the ith row \n"); //= *(&arr[0])
	printf(" **(p+i) gives the value of the 0th element of the ith row \n\n\n\n\n"); //= arr[i][0]


	printf("The elements of the 3x4 array are as follows: \n\n ");
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)
		{  	printf("\t%d",arr[i][j]);
		}
		printf("\n\n");
	}
	
	printf("\n\n\nThe following section shows the equivalence of: \n\n\t arr[i][j], (*(p+i))[j], *(*(p+i)+j).");
	printf("\n\n And also that *(p+i)[j] = arr[i+j][0]\n\n\n");
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)
		{  	printf(" value of arr[%d][%d] \t= %d \n", i, j, arr[i][j]);
			printf(" value of (*(p+%d))[%d] \t= %d \n", i, j, (*(p+i))[j]);	
			printf(" value of *(*(p+%d))%d) \t= %d \n", i, j, *(*(p+i)+j));
			printf(" value of *(p+%d)[%d] \t= arr[%d+%d] = arr[%d][0] = %d \n\n", i, j, i, j, i+j, *(p+i)[j]);	
		}
	}
	return 0;
}



