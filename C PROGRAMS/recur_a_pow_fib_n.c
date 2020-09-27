#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

#define N 40

int main()
{
	int a=5, b=3, pow=1;
	printf("program to compute 'a' raised to the power of 'n'\n");
	printf("Enter a \n");
	scanf("%d",&a);
	printf("Enter n \n");
	scanf("%d",&b);
	int res = power(a, b, &pow);
	assert(res !=-1);
	printf("\n\n %d raised to the power of %d = %d", a, b, pow);
	
	fibonacci(b);
	  
	return 0;
}

int power(int a, int n, int *s)
{	int i, x, y, z;
	if(n<=0 || s == NULL) return -1;
	
//	for(i=1; i<=n; i++)
//	{
//		*s*=a;
//	}

	*s = power_rec(a, n);
		
	return 0;
}

int power_rec(int a, int n)
{	
	if(n>0)		return(a*power_rec(a, n-1));
	
	return 1;
}

int fibonacci(int n)
{
	int x=0, y=1, z=1, i; 
	printf("\n\nFibonacci series recursively calculated:\n1	");
	
//	for(i=2;i<=n;i++)	// 
//	{
//		z=y;
//		y=x+y;
//		x=z;
//		printf("%d	",y);
//	}
	
	rec_fib(n, &x, &y);
	printf("\n");
	
	int fib[N], fibcat[N];
	
	int error = fib_array(fib, n);
	assert(!error);
	
	int min, max;
	error=minmax(fib, n, &min, &max);	
	assert(!error);	
	printf("\n\n\tMin = %d", min);
	printf("\tMax = %d", max);
//	if(fib_array(fib, n))	printf("Error in fib_array()");

	concat(fib, n, fib, n, fibcat);
		
	return 0;
}

void rec_fib(int n, int *x, int *y)
{	int t=*y;
	*y=*x+*y;
	*x=t;
	printf("%d	",*y);	
	
	if(n>2) rec_fib(n-1, x, y);
}

// int fib_array(int fib[], int n)
int fib_array(int * fib, int n)	
{	int i, j=0;
	if(fib==NULL)	return -1;
	if(n<=0)		return -2;
	
	fib[0]=1;
	if(n>=2)	fib[1]=1;	i=2;
	
	printf("\nFibonacci series calculated by array/pointer:\n\n");
	
	while(i<n)
	{	

		*(fib+i) = *(fib+i-2) + *(fib+i-1);	//		fib[i]=fib[i-2]+fib[i-1];
		
		for(j=0;j<=i;j++)		printf("\t%u",  (fib+j));
		
		printf("\n");
		
		for(j=0;j<=i;j++)		printf("\t%d", *(fib+j));
		
		printf("\n\n");
		
		i++;
	}
	

//	int * fibo = fib+2;
//	while(i<n)
//	{
//		*(fibo)=*(fibo-1)+*(fibo-2);
//		fibo++;	i++;
//	}
	
//	for(i=2; i<n; i++)	{	fib[i]=fib[i-2]+fib[i-1];}
	
	for(i=0;i<n;i++)	printf("%d\t",fib[i]);
		
	return 0;
}

int minmax(int *a, int n, int *min, int *max)
{
	if(a==NULL || min==NULL || max==NULL) 	return -1;
	if(n<=0)					return -2;	
	
	int i=1;
	*min=*max=*a;
	while(i<n) 
	{
		if(*(a+i)<*min) *min = *(a+i);
		 
		if(*(a+i)>*max) *max = *(a+i); 
		
		i++;
	}
	
	return 0;
	
}

