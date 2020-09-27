#include<stdio.h>
	int main()
	{
	int arr[5]={10,20,30,40,50};
	int *p=arr,*q=*(&arr);
	printf("%d\n",*p);	
	
	printf("&arr \t= %p \n",&arr);
	printf("&arr+1 \t= %p \n",&arr+1);
	printf("*(&arr) \t= %p \n",*(&arr));
	printf("%p \n",*(&arr+1));
	printf("%p \n", q)
	printf("%d\n",*q);
	return 0;
	}
