#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define N 40

int main()
{	int na=0, nb=0, i=0;
	int b[N]={43,5,6,7,8,9};
	int a[N]={51,7,8,1,2,4,9,3,0,6};
	int c[N]={NULL};
	
	
	printf("Enter n for a[]\n");
	scanf("%d",&na);
	printf("Enter n for b[]\n");
	scanf("%d",&nb);
	
	printf("\nEnter a[]\n");
	while(i<na)
	{	scanf("%d", &a[i]);	i++;
	}
	
	printf("\nEnter b[]\n");
	i=0;
		while(i<nb)
	{	scanf("%d", &b[i]);	i++;
//	scanf("%d", &(b+i++));	i++;
	}
//	int na=strlen(a);
//	int nb=strlen(b);
	
	concat(a, na, b, nb, c);
	
	/*DOT PRODUCT*/
	int x[]= {1,2,3,4,5};
	int y[]= {1,2,3,4,5};
	int  n=5, *dp;
	assert(!dotproduct(x, y, n, dp));
	printf("\nDot Product : %d\n\n",*dp);
	
//	assert(!dotproduct(NULL, y, n, dp));	
//	printf("\nDot Product : %d\n\n",*dp);
}

int concat(int *a, int na, int *b, int nb, int *c)
{	if(a==NULL || b==NULL || c==NULL) return -1;
	if(na<0 || nb<0)	return -2;
	
	int i=0;
	while(i<na)		{	c[i]=a[i];	i++;}
	
	while(i<na+nb)	{	c[i]=b[i-na];	i++;}
	
	i=0;
	printf("\n\nConcatenated array: \n");
	while(i<na+nb)	{printf("\t%d,", c[i]); i++;}
	
	return 0;
}

int dotproduct(int x[], int y[], int n, int * dp)
{
	if(!x || !y || !dp){	return -1;	} // either of x[], y[], dp is NULL
//	if(x==NULL || y==NULL || dp==NULL)
	if(n<=0) return -2;
	int sum =0, i=0;
	
	for(; i<n; i++)
	{
		sum+=x[i]*y[i];
	}
	
	*dp=sum;
	
	if(*dp) return 0; 	// non-zero dot product
	
	
}
