

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include<stdio.h>
#include<stdint.h>

// https://www.cplusplus.com/reference/cstdio/scanf/

// BIG-ENDIAN to LITTLE-ENDIAN & vice-versa
#define ENDIAN_CHANGE_U16(x) ((((x)&0xFF00)>>8) + (((x)&0xFF)<<8))  // uint16_t x = 0xABCD;

void wait_for_user_input(void);

/* global variables */
int g_data1 = 4000;
int g_data2 = 200;
char result = 0;

uint8_t const data = 0x10;

int main(void)
{	
	// constdata 
	printf("\nconst Value = %u\n",data);

	uint8_t *ptr = (uint8_t*)&data; //uint8_t const *

	//*ptr = 50; // ERROR : illegal statement !!! // CAN'T CHANGE const value

	printf("\nValue = %u\n", *ptr); //	printf("Value = %u\n",data);
	
//-----------------------------------------------------------------------------------------------------------------------//	
	
	// ASCII
	char c1,c2,c3,c4,c5,c6; 
	printf("\nEnter any 6 characters of your choice :");
	scanf("%c %c %c %c %c %c",&c1,&c2,&c3,&c4,&c5,&c6);
	
//	c1 = getchar();
//    getchar(); //this getchar is used to clear the input buffer (\n)
//    c2 = getchar();
//    getchar();//this getchar is used to clear the input buffer (\n)
//    c3 = getchar();
//    getchar();//this getchar is used to clear the input buffer (\n)
//    c4 = getchar();
//    getchar();//this getchar is used to clear the input buffer (\n)
//    c5 = getchar();
//    getchar();//this getchar is used to clear the input buffer (\n)
//    c6 = getchar();
		
	
	
	printf("\nASCII codes : %u,%u,%u,%u,%u,%u",c1,c2,c3,c4,c5,c6);
	
//-----------------------------------------------------------------------------------------------------------------------//
	
	// Average
	double number1, number2, number3;
	double average;

	printf("\nEnter 3 numbers: ");
	scanf("%lf %lf %lf",&number1,&number2,&number3);
	
	
//	printf("Enter the first number: ");
//	fflush(stdout);
//	scanf("%f",&number1);
//	printf("\nEnter the second number: ");
//	fflush(stdout);
//	scanf("%f",&number2);
//	printf("\nEnter the third number: ");
//	fflush(stdout);
//	scanf("%f",&number3);


	average = (number1 + number2 + number3) / 3;

	printf("\nAverage is : %0.3lf\n",average);
	
//-----------------------------------------------------------------------------------------------------------------------//	
	
	// bitWise2Numbers
	int32_t num1 , num2; // BITWISE OPERATIONS
	printf("\nEnter 2 numbers(give space between 2 nos):");
	scanf("%d %d",&num1,&num2);

	printf("Bitwise AND(&) : %d\n",(num1 & num2));
	printf("Bitwise OR (|) : %d\n",(num1 | num2));
	printf("Bitwise XOR(^) : %d\n",(num1 ^ num2));
	printf("Bitwise NOT(~) : %d\n",(~num1));
	
	
//-----------------------------------------------------------------------------------------------------------------------//	
	
	// bitWiseEvenOdd
	//int32_t num1;
	printf("\nEnter a number:");
	scanf("%d",&num1);

	if(num1 & 1)	// BITWISE ODD EVEN
	{		printf("%d is odd number\n", num1);
	}
	else
	{		printf("%d is even number\n", num1);
	}
	
//-----------------------------------------------------------------------------------------------------------------------//	
	
	// bitWiseSet
	int32_t output; 
	printf("Enter a number:");
	scanf("%d",&num1);

	output = num1 | 0x90;
	printf("[input] [output] :0x%x 0x%x\n", num1, output);
	
//-----------------------------------------------------------------------------------------------------------------------//	
	 
	// forLoopEvenNum 
	int32_t start_num, end_num; 
	uint32_t even;


	do
	{
		printf("Enter starting and ending numbers(give space between 2 nos):");
		scanf("%d %d",&start_num,&end_num);
		
		if(end_num < start_num)
		{	printf("ending number should be > starting number\n"); //error
		}
		
	}while(end_num < start_num);

//	if(end_num < start_num)
//	{	printf("ending number should be > starting number\n"); //error
//		//		wait_for_user_input();
//		//		return 0;
//	}
//	else
//	{ 
	for(printf("Even numbers are :\n"), even=0; start_num <= end_num ; start_num++ )
	{
		if( ! (start_num % 2 ) ){
			printf("%4d\t", start_num);
			even++;
		}

	}

   printf("\nTotal even numbers : %u\n", even);
//	}




//-----------------------------------------------------------------------------------------------------------------------//
	
	// ifelseBiggestOfTwo
	{ // SCOPE RESOLUTION ---> LOCAL SCOPE
		float num1, num2;
		// double num1 , num2;
		printf("Enter the first number(integer/float):");
		scanf("%f", &num1);
	
		printf("Enter the second number(integer/float):");
		scanf("%f", &num2);
		
		printf("\n num1 = %f", num1);
		printf("\n num2 = %f \n", num2);
	
		int32_t n1, n2, big;
	
		/* we are storing only integer part of the real numbers*/
		n1 = num1;
		n2 = num2;
			
		printf("\n n1 = %d", n1);
		printf("\n n2 = %d \n", n2);
	
		if( (n1 != num1) || (n2 != num2) )
		{	printf("\nWarning !!! comparing only integer part\n");
		}
	
	    if(n1 == n2)
		{  	printf("\nNumbers are equal\n");
	    }
		else
		{	big = (n1 > n2) ? n1 : n2; 
	    	printf("\n %d is bigger\n\n", big);    	
	    }
	}



//-----------------------------------------------------------------------------------------------------------------------//
	
	// ifelseifTax
	// https:// stackoverflow.com/questions/4264127/correct-format-specifier-for-double-in-printf
	uint64_t income;
	uint64_t tax;

	double temp_income;

	printf(" Enter your total income:");
	scanf("%lf", &temp_income);

	if(temp_income < 0){
		printf(" Income cannot be -ve\n");
		wait_for_user_input();
		return 0;
	}


	income = (uint64_t) temp_income; // 
	
	printf("\n income = %d \n\n temp_income = %f", income, temp_income);

	if(income <= 9525)
	{	tax = 0;
	}
	else if( (income > 9525) && (income <= 38700) )
	{	tax = income * 0.12;
	}
	else if((income > 38700) && (income <= 82500))
	{	tax = income * 0.22;
	}
	else if(income > 82500)
	{	tax = income * 0.32;
		tax = tax + 1000; //tax += 1000;
	}
	else
	{	;//NOP
	}

	printf("\n\n Tax payable : Rs.%I64u\n", tax);

//-----------------------------------------------------------------------------------------------------------------------//

	result = g_data1; // + g_data2;

	printf("\n\nResult = %d\n", result);
	
	result = g_data2; // + g_data2;

	printf("Result = %d\n", result);
	
	result = g_data1 + g_data2;

	printf("Result = %d\n\n", result);

//-----------------------------------------------------------------------------------------------------------------------//

	// type cast
	unsigned char data = 0x1FFFFFFFA0B0 + 0x1245;
	
	float  result =  80 / (float)3 ;
	
	printf("Data : %u  result : %f \n", data , result);
	
//-----------------------------------------------------------------------------------------------------------------------//	

	char a1 = 'A';

	unsigned long long int addressOfa1 =  ( unsigned long long int  )&a1;
	
	printf("Address of variable a1 = 0x%I64X\n",addressOfa1);

//-----------------------------------------------------------------------------------------------------------------------//



//-----------------------------------------------------------------------------------------------------------------------//



//-----------------------------------------------------------------------------------------------------------------------//



//-----------------------------------------------------------------------------------------------------------------------//



//-----------------------------------------------------------------------------------------------------------------------//	

    wait_for_user_input();
}


void wait_for_user_input(void)
{
	printf("\n Press enter key to exit this application");
    while(getchar() != '\n')
    {    	//just read the input buffer and do nothing
    }
    getchar();

}
