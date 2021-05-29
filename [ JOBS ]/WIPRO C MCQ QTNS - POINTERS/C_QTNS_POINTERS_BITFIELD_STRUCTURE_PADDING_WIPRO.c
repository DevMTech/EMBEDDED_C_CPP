/*
	WIPRO - C - topics

	C Preprocessor  
	C Enum n Typedef  
	C Recursive  
	C Switch n Loop  
	C Bitwise Operators
	C BitField  
	C Operators  
	C Link List  
	C Formatted Output
	C File Operations 
	C Memory Allocation
	C Variables n Scope
	C Pointers

*/

//What will be output of the following program? NO OUTPUT
//#include <stdio.h> // COMPILATION ERROR IF NOT INCLUDED
//int main()
//{
//	FILE *fp = stdin;
//	int n;
//	fprintf(fp, "%d", 45);
//}



//What will be output of the following program?
//#include <stdio.h>
//#define OFFSET 0
//void main()
//{
//	int x = 0x87654321;
//	int *p = &x;
//	char *q = (char *)&x; //	char *q = (char *)p;
//
//	printf(" &x = 0x%x\t= %d\n", &x, &x);
//	printf("  q = 0x%x\t= %d\n", q, q);
//	printf("  x = %d = 0x%x = %c\n", x, x, x);
//	printf(" *(q+0) =   %d = 0x%x = %c\n", *(q+OFFSET), *(q+OFFSET), *(q+OFFSET));
//	printf(" *(q+1) =   %d = 0x%x = %c\n", *(q+1), *(q+1), *(q+1));
//	printf(" *(q+2) =  %d = 0x%x = %c\n", *(q+2), *(q+2), *(q+2));
//	printf(" *(q+3) = %d = 0x%x = %c\n", *(q+3), *(q+3), *(q+3));
//	printf("  p = 0x%x\t= %d\n", p, p);
//	
//	q++;
//	printf("q++ = 0x%x\t= %d\n", q, q);
//	
//	int *k = p++; //	int *k = ++p;
//	printf("  k = 0x%x\t= %d\n", k, k);
//		
//	int r = p - k; // implicitly 4 bytes evaluates to one int value 
//
//	printf("  p = 0x%x\t= %d\n", p, p);
//	printf("  k = 0x%x\t= %d\n", k, k);
//	printf("\n\n  r = p - k = %d\n", r);
//	
//	k = k++;
//	r = p - k;
//	printf("\n\n r = p - k = %d", r);
//	printf("\n p = %u", p);
//	printf("\n k = %u", k);
//	
//	k = ++k;
//	r = p - k;
//	printf("\n\n r = p - k = %d", r);
//	printf("\n p = %u", p);
//	printf("\n k = %u", k);
//}




//What is the value of the following statement?
//x = x&(x-1);
//Ans. Right-most Bit will be Off




//Output of following program ?
//#include <stdio.h>
//int main(void)
//{
//	int a = 100;
//	char* x = (char*)&a;
//	printf(" x = 0x%x\t= %d\n", x, x);
//	printf(" a = %d = 0x%x = %c\n", *x, *x, *x);
//	char** y = &x;
//	y[0] = (char*)0x62fe15;
//	printf(" x = 0x%x\t= %d\n", x, x);
//	printf(" *x = %d = 0x%x = %c\n", *x, *x, *x);
//	printf(" y = 0x%x", *y);
//}





//What will be the output of the following code? 
//#include <stdio.h>
//void main()
//{
//	int const* p = 5; // [Warning] initialization makes pointer from integer without a cast
//	printf("%d", ++(*p)); // [Error] increment of read-only location '*p'
//}
//ANS. COMPILATION ERROR 
	
 	
 	
 	
//What does the following function do for a given Linked List with first node as head?
//void fun1(struct node* head)
//{
//	if(head == NULL)
//		return;
//	
//	fun1(head->next);
//	printf("%d ", head->data);
//} 	
//ANS. Prints all nodes of linked list in reverse order




//What will be output of the program?
//#include <stdio.h>
//int f1(int *a, int n)
//{
//	if(n<=0) return 0;
//	else if(*a%2==0) return *a+f1(a+1, n-1);
//	else return *a-f1(a+1, n-1);
//} 
//
//int main()
//{
//	int a[] = {15, 9 ,16, 3, 11, 6};
//	printf("%d\n", f1(a,6));
//	return 0;
//}
//ANS.20



//Calculate the % of memory saved when bit-fields are used for the following C structure as compared to without use of bit-fields for the same structure? (Assuming size of int = 4)
//#include <stdio.h>
//struct temp
//{	int a : 1;
//	int b : 2;
//	int c : 4;
//	int d : 4;
//}s;
//
//int main()
//{	printf(" sizeof(s) = %u bytes \n", sizeof(s));
//	//printf("%u", &s.a); // [Error] cannot take address of bit-field 'a'
//	printf(" &s = %u\n", &s);
//	char* x = (char*)&s;
//	printf(" x = %u\n", x);
//	printf(" *x = %d = 0x%x = %c\n", *x, *x, *x);
//	int i = s.d;
//}


//For what minimum value of x in a 32-bit Linux OS would make the size of s equal to 8 bytes?
//struct temp
//{
//int a : 13;
//int b : 8;
//int c : x;
//}s;
//Options  
//8 
//32
//12 // CORRECT
//4


//What will be the output of the following code? // COMPILATION ERROR
//#include <stdio.h>
//main() 
//{
//	{
//		register int weight = 60;
//		int *ptr=&weight; // [Error] address of register variable 'weight' requested
//		printf("%d", *ptr);
//	}
//}


//What will be output of the program?
//#include <stdio.h>
//int main(void)
//{
//	int b = 20;
//	int* x = &b;
//	char n = 'A';
//	char* z = &n;
//	
//	printf("\n *x = %d = 0x%x = %c\n", *x, *x, *x);
//	
//	x[0] = z[0]; // COPYINH int VALUE OF 'n' TO 'b' 
//	
//	printf("\n *x = %d = 0x%x = %c\n", *x, *x, *x);
//	
//	printf((*x == *z) ? "True" : "False");
//	
//	return 0;
//}




//What will be output of the program?
//#include <stdio.h>
//#define L 10
//void main()
//{
//	int a = 10;
//	switch (a, a*2, a*3, a*4, a*5) // ONLY LAST EXPRESSION IS EVALUATED & CHECKED WITH AVAILABLE CASES
//	{   case L:
//		printf("ABC");
//		break;
//		
//		case L*2:
//		printf("XYZ");
//		break;
//		
//		case L*3:
//		printf("PQR");
//		break;
//		
//		case L*4:
//		printf("www");
//		break;
//		
//		default:
//		printf("MNO");
//		 	 
//		case L*6:
//		printf("www");
//		break;
//	}
//}
// ANS. MNOwww

// Assuming x as 32 bit signed int, what would be value of x after executing this snippet?
//#include <stdio.h>
//void printBinary(unsigned int n)
//{
//	if(n>>1)
//	{	printBinary(n>>1);
//	}
//	putc((n & 1)?'1':'0', stdout);
//}
//
//int main()
//{	
//	int x = 15;
//	printf("\n x = %d \n", x);
//	printBinary((unsigned int)x);
//	
//	x = x|(x=-15);
//	printf("\n x = %d \n", x);
//	printBinary((unsigned int)x);
//	
//	return 0;
//}



//What will be output of the following program?
//#include <stdio.h>
//int main()
//{
//	int i = 10, j = 2;
//	printf("%d\n", printf("%d %d ", i, j));
//}
// ANS. 10 2 5

//What is the value of the following statement?
//(x<<1) + x + (x>>1)
// ANS. 3.5x

//What will be output for the following program?
//#include <stdio.h>
//int main()
//{
//	int x = 032; // Octal 032 = 011 010b = 26 
//	printf(" x = %d", x);
//	return 0;
//}

//  Correct syntax to pass a Function Pointer as an argument?
//OPTIONS:
//void pass(int (*fptr)(int, float, char)){} // CORRECT
//void pass(*fptr(int, float, char)){}
//void pass(*fptr){}
//void pass(int (*fptr)){}


//Assuming x as 32 bit signed int, what would be value of x after executing this statement?
//x= -2 >> 1;
//OPTIONS:
//-2
//-4
//2^31-1
//-1 // CORRECT


//What will be output of this program?
//int main()
//{
//	static int a=5;
//	if(--a)
//	{
//		main();
//		printf("%d\n", a);
//	} 
//	return 0;
//}
// OPTIONS
//4 3 2 1
//0 3
//2 1 0
//0 0 0 0 // CORRECT

//What will be the output of the following code? // ORDER OF PRECEDENCE: RIGHT TO LEFT 
//#include <stdio.h>
//int main()
//{
//char ch = 10;
//void* ptr = &ch;
//printf("%d, %d", ++*(char*)ptr, *(char*)ptr);
//return 0;
//}
//
// ANS: 11 10


//What will be output for the following program?
//int main()
//{
//	int i=-1, j=-1, k=-1, l=2, m;
//	m= i++ && j++ && k++ || l++; // l++ doesn't get executed // -1 & -1 & -1 = 1 ??
//	printf("%d%d%d%d%d", i, j, k, l, m);
//	return 0;
//}
//ANS: 00021

//What will be output of the following program?
//#include <stdio.h>
//enum foundry {a,b,c=5};
//enum foundry s;
//void main()
//{
//	c++; // [Error] lvalue required as increment operand
//	printf("%d",c);
//}


//Output of following program ?
//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	printf("%d", ++a++); //	[Error] lvalue required as increment operand
//}


//What will be the output of the following code?
//#define square(x) x*x
//int main()
//{
//	int x;
//	x = 36/square(6);
//	printf("%d",x);
//	return 0;
//}
// ANS. 36/6*6 = 6*6 = 36



