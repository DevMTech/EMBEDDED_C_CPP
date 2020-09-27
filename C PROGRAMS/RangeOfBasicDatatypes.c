// C program to print range of basic data types 
#include <stdio.h> 

// Prints min and max value for a signed type 
void printUnsignedRange(size_t bytes) 
{ 
	int bits = 8*bytes; 

	// Note that the value of 'to' is "(1 << bits) - 1" 
	// Writing it in following way doesn't cause overflow 
	unsigned int to = ((1 << (bits-1)) - 1) + (1 << (bits-1)) ; 

	printf(" range is from %u to %u \n", 0, to); 
	printf("\t\t\t:  range is from 0 to (2^%d)-1\n", bits); 
} 

// Prints min and max value for an unsigned type 
void printSignedRange(size_t bytes) 
{ 
	int bits = 8*bytes; 
	int from = -(1 << (bits-1)); 
	int to = (1 << (bits-1)) - 1; 
	printf(" range is from %d to %d\n", from, to); 
	printf("\t\t\t:  range is from -2^%d to (2^%d)-1\n", bits-1, bits-1); 
	printf("\t\t\t:  size in bytes: %dbyte", bytes);
	(bytes > 1) ? printf("s\n") : printf("\n");
} 

int main() 
{ 	
	printf("void\t\t\t: "); 
	printSignedRange(sizeof(void)); 

	printf("\nsigned char\t\t: "); 
	printSignedRange(sizeof(char)); 

	printf("unsigned char\t\t: "); 
	printUnsignedRange(sizeof(unsigned char)); 
	
	printf("\nsigned short (int)\t: "); 
	printSignedRange(sizeof(short)); 

	printf("unsigned short (int\t: "); 
	printUnsignedRange(sizeof(unsigned short)); 

	printf("\nsigned int\t\t: "); 
	printSignedRange(sizeof(int)); 

	printf("unsigned int\t\t: "); 
	printUnsignedRange(sizeof(unsigned int)); 

	printf("\nsigned long (int)\t: "); 
	printSignedRange(sizeof(long)); 

	printf("unsigned long (int)\t: "); 
	printUnsignedRange(sizeof(unsigned long)); 
	
	printf("\nsigned long long\t: "); 
	printSignedRange(sizeof(long long)); 

	printf("unsigned long long\t: "); 
	printUnsignedRange(sizeof(unsigned long long)); 
	
	printf("\nfloat\t\t\t: "); 
	printf(" size in bytes: %dbytes", sizeof(float));
	//printSignedRange(sizeof(float)); 

	printf("\ndouble\t\t\t: "); 
	printf(" size in bytes: %dbytes", sizeof(double));
	//printSignedRange(sizeof(double));  
	
	printf("\nlong double\t\t: "); 
	printf(" size in bytes: %dbytes", sizeof(long double));
	//printSignedRange(sizeof(long double)); 

	return 0; 
}

