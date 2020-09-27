#include<stdio.h>

main()
{ 	int a[3][4]= {1,2,3,4,5,6,7,8,9,10,11,12};
  	int (*q)[3][4]=&a;
	
  	printf("sizeof(q) =  %u \n\n",sizeof(q));
	printf("sizeof(*q) =  %u \n\n",sizeof(*q));
	printf("sizeof(**q) =  %u \n\n",sizeof(**q));
	printf("sizeof(***q) =  %u \n\n",sizeof(***q));
}
