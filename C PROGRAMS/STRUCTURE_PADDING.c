// STRUCTURE PADDING
// https://fresh2refresh.com/c-programming/c-structure-padding/
// https://embedclogic.com/bit-field-in-c/
// https://www.geeksforgeeks.org/data-structure-alignment/
// https://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/

// size of struct
#include <stdio.h>

// zeroth structure
struct test0 // size = 16 bytes
{
	int i;   // 4 bytes
	char c;  // 1 byte
			 // 1 byte padding
	short s; // 2 bytes
	double d;// 8 bytes
}t0;

// first structure
struct test1 // size = 16 bytes
{
	short s; // 2 bytes
			 // 2 byte padding	
	int i;   // 4 bytes	
	double d;// 8 bytes          
}t1;

// second structure
struct test2 // size = 16 bytes
{
	short s; // 2 bytes
	char c;  // 1 byte
			 // 1 byte padding	
	int i;   // 4 bytes
	double d;// 8 bytes
	          
}t2;

// third structure
struct test3 // size = 24 bytes
{
	short s; // 2 bytes
			 // 2 byte padding	
	int i;   // 4 bytes
	char c;  // 1 byte
	         // 7 bytes padding
	double d;// 8 bytes
	          
}t3;

// fourth structure
struct test4 // size = 24 bytes
{
	short s; // 2 bytes
			 // 2 byte padding	
	int i;   // 4 bytes
	char c;  // 1 byte
	         // 3 bytes padding
	int j;   // 4 bytes         
	double d;// 8 bytes
	          
}t4;

struct bitfield // 4 bytes = 32 bits 
{	int a : 1; // 1 bit
	int b : 2; // 2 bits
	int c : 4; // 4 bits
	int d : 4; // 4 bits
			   // 21 bits padding	
}bf;

struct temp // 8 bytes = 64 bits
{
int a : 13; // 13 bits
int b : 8;  //  8 bits
int c : 12; // 12 bits // 13+8+12 = 33 bits
			// 31 bits padding -> 33+31 = 64 bits
}s;

// We can use zero length data member without a name in bit field structure for further data alignment at next boundary.
struct birthday // (32+32+32)bits = 12 bytes 
{
	unsigned char date :5 ; 	 //1st 5 bits of 1st 4 bytes	
	unsigned int:0;              //1st 32 bit (4 byte) jump -> PADDIING
	unsigned int:0;              //wrong, no effect
	unsigned int:0;              //wrong, no effect
	unsigned char month :4 ;    //1st 4 bits of 2nd 4 bytes
	unsigned int:0;             //2nd 32 bit (4 byte) jump -> PADDING
	short int year :12;    		//1st 12 bits of 3rd 4 bytes
}bday;

// driver program
int main() 	
{	printf("size of struct test0 is %u bytes\n", sizeof(t0));  // 16 bytes
	printf("size of struct test1 is %u bytes\n", sizeof(t1));  // 16 bytes
	printf("size of struct test2 is %u bytes\n", sizeof(t2));  // 16 bytes
	printf("size of struct test3 is %u bytes\n", sizeof(t3));  // 24 bytes
	printf("size of struct test4 is %u bytes\n", sizeof(t4));  // 24 bytes
	printf("size of struct bitfield: %u bytes\n", sizeof(bf)); //  4 bytes
	printf("size of struct temp: %u bytes\n", sizeof(s)); 	   //  8 bytes
	printf("size of struct birthday: %u bytes\n", sizeof(bday));//12 bytes
	return 0;
}

