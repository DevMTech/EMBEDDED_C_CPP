#include <stdio.h>

#define ArrSize(x) sizeof(x)/sizeof(x[0])

typedef struct point 
{  int x, y;
}pnt;

struct square
{	int side;
}s1;

void showArr(int *p, int n);

void printArr(int *p[5]);

int main(void) 
{	
	pnt p; /* struct omitted */
	p.x = 10;
  	printf(" %d ", p.x);

  	s1.side=20;
  	
  	
	
	int arr[]={10, 20, 30, 40, 50};
	//int *pArr = arr;
	int n = ArrSize(arr);
	
	printf("\n\n Starting address of Array: %u \n\n", arr);
	showArr(arr, n);
	
	int *ptr[] = {arr, arr+1, arr+2, arr+3, arr+4}; // ptr is an array of int pointers
	printf("\n\n addr. of pointer to arr[0] = %u \n addr. of arr[0] = %u \n contents of arr[0] = %d \n", ptr, *ptr, *(*ptr));
	
	//printArr(arr);  	
}


void showArr(int *p, int n)
{	int i=0;
	
	printf("\n n = %d \n\n", n);
	
	while(i<n)
	{	printf("%d %d \t %u \n", i, *(p+i), (p+i));
//		printf("%d %d \t %u \n", i, *p, p); 		p++;		
		i++;
	}
}

//void printArr(int *p[5])
//{	int i=0, n=5;
//	//n=ArrSize(*p);
//	printf("\n n = %d \n\n", n);
//	
//	while(i<n)
//	{
//		printf("%d %d \t %u \n", i, *(p+i), (p+i));
//		
//		i++;
//	}
//}

