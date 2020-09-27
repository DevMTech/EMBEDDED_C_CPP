#include<stdio.h>

void min_max_sum(int *, int);
void arr_addition(int (*)[], int (*)[], int);



main()
{	int arr1D[] = {1,2,3,4,5,6,7,8,9,0};
	int i,j,n=4;
	//int * p1D = a;
	int arr2D_1[][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int arr2D_2[][4]={16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	
	printf("\n\n\t ELEMENTS OF 1D ARRAY : \n\n\n");
	for(i=0; i<10; i++)
	{ printf("\t%d",arr1D[i]);
	}
	
	
	min_max_sum(arr1D, 10);
	
	

	printf("\n\n\t ELEMENTS OF MARIX A : \n\n\n");
	for(i=0; i<n; i++)
	{for(j=0; j<n; j++)
		{printf("\t%d",arr2D_1[i][j]);
		}
		printf("\n\n");
	}
	
	printf("\n\n\t ELEMENTS OF MARIX B : \n\n\n");
	for(i=0; i<n; i++)
	{for(j=0; j<n; j++)
		{printf("\t%d",arr2D_2[i][j]);
		}
		printf("\n\n");
	}
	
	
	arr_addition(arr2D_1,arr2D_2,4);
	
	
	printf("\n\n\t PRINTING FROM MAIN AFTER ADDITION OF MARIX A AND MATRIX B IN FUNCTION arr_addition() \n\n");

	printf("\n\n\t ELEMENTS OF MARIX A AFTER ADDITION WITH THOSE OF MATRIX B : \n\n\n");
	for(i=0; i<n; i++)
	{for(j=0; j<n; j++)
		{printf("\t%d",arr2D_1[i][j]);
		}
		printf("\n\n");
	}

	return 0;
	
}

void min_max_sum(int * ptr, int n)
{
	int i=0, max=0, min=0, sum=0;
	for(;i<n;i++)
	{sum+=ptr[i];
	 if(ptr[i]>max) max = ptr[i];
	 if(ptr[i]<min) min = ptr[i];
	}
	 
	 printf("\n\n\n\n\t sum of array elements : %d \n\n", sum);
	 printf("\n\n\t minimum of array elements : %d \n\n", min);
	 printf("\n\n\t maximum of array elements : %d \n\n", max);
	 
}

void arr_addition(int (*arr1)[4], int (*arr2)[4], int n)
{
	int i, j;
	for(i=0; i<n; i++)
	{for(j=0; j<n; j++)
		arr1[i][j]+=arr2[i][j];
		//*(*(arr1+i) + j) = *(*(arr1+i) + j) + *(*(arr2+i) + j);
	}
}
