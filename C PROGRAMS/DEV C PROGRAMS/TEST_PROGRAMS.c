#include <stdio.h>
//int print_star( int n)
//{
//int i = 0;
//if ( n > 1)
//print_star(n-1);
//for (i = 0; i < n; i++)
//printf("*");
//printf("\n");
//}

//int main()
//{int fun();
//int i = fun();
//i = fun();
//printf("%d\n", i);
//return 0;
//}
//
//int fun()
//{auto int i = 5;
//i++;
//return i;
//}   


// use any of the three function declarations, each works equivalently
myfuncn(int *, int);
//myfuncn(int [], int);
//myfuncn(int var1[], int var2);


// use any of the two function defenations, both work equivalently
//myfuncn( int *var1, int var2)
myfuncn( int var1[], int var2)
{ int x;
    for( x=0; x<var2; x++)
    {
        printf("Value of var_arr[%d] is: %d \n", x, *var1);
        var1++; /*increment pointer for next element fetch*/
    }
}

int main()
{
     int var_arr[] = {11, 22, 33, 44, 55, 66, 77};
     // use any of the two statements, both work same 
     //myfuncn(&var_arr, 7);
     myfuncn(var_arr, 7); // doesn't matter if '&' is not written, result is same

     return 0;
}

//f(a[]);
//
//main()
//{ int b[] = {1,2,3,4,5,6,7,8,9,0};
//	f(b);
//}
//
//f(a[])
//{
//}
//f(int a, int b);
//main()
//{ int c=f(5,6);
//printf(" \n\n c = %d ", c);
//}
//f(int a, int b)
//{int a;
//a=20;
//return a;
//}


//int a = 5;
//void main ()
//{int a =6;
//printf("%d",a);
//}

//int main()
//{
//int n=5;
//switch (n) 
//{
//default : printf("default"); n=5;
//case 1: printf("1");
////default : printf("default"); n=1;
//case 2: printf("2");
//case 3: printf("3"); break;
//} return 0;
//}

#define sq(x) (x*x)
//main()
//{ //print_star(3);
//int r;	
//int x =10, y=20, result;
//result =(x==10 || y >20);
//printf("%d \n \n ",result);
//// (x>y) ? ( printf("%d",x) : printf("%d",y) );
////r=(x>y) ? x : y;
//r=x>y ? x:y;
//printf("\n\n r = %d", r);
//x>y ? x:y;
//printf("\n\n r = %d", x>y ? x:y);
//printf("\n\nsquare of %d is %d", 5, sq(5));
//prinf(" \n\n larger of the two %d",(x>y) ? (x : y));
//  unsigned char uc = 255; 
//	short s = 127;
//	unsigned short us = 255;
//	long L = 2147483647;
//	unsigned long ut, uL = 2147483647;
//	//unsigned long ut, uL = 4294967290;
//	unsigned ui = 65535; //unsigned = unsigned int
//	int i = 32767;
//    printf(" %d %f %c", 23451, 124.658, 'd');
//    printf(" \n \n %c %ld", uc, 78948L);
//    printf(" \n \n short(127) %d \n \n ushort(255) %d \n \n int(32767) %d \n \n uint(65535) %d", s, us, i, ui);
//    printf(" \n \n long(2147483647) %d \n \n \n \n ulong(2147483647) %d", L, uL); 
//    
//	// ulong(2147483647) =   2147483647
//	// ulong(2147483648) = - 2147483648
//	// ulong(4294967296) = 0 
//	
//    printf(" \n \n ulong(2147483648) %d \n \n ulong(4294967296) %d", uL+1, 4294967296); 
//    
//    printf(" \n\n\n\n\n\n ***********************************************************  \n\n\n");
//
//    uL = 2147483647;
//	
//    for (i = -4 ; i<5; i++)
//    {     printf(" \n \n \n ulong  2147483647 + %d  = %d", i, uL+i);
//	}
//	
//	printf(" \n\n\n\n\n\n ***********************************************************  \n\n\n");
//	
//    
//	uL =4294967296;
//    for (i = -4 ; i<5; i++)
//    {     printf(" \n \n \n ulong  4294967296 + %d  = %d", i, uL+i);
//	}
//	
//   
//}

