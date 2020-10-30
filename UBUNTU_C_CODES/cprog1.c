#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 10, b = 20, sum = a+b;
	char ch = 'A';
	float flt = 25.3654258;

	printf("hello puku!\n");

	printf("sum : %d + %d = %d\n", a, b, sum);

	printf("ch = %c (%d)\n", ch, ch);

	ch++;

	printf("ch = %c (%d)\n", ch, ch);
	
	printf("float : flt = 25.3654258(actual), %f(saved as), %f(prints as) \n", flt, 25.3654238);
	
	printf("short int : sizeof(short int) = %ldbytes\n", sizeof(short int)); 
	
	printf("int : sizeof(int) = %ldbytes\n", sizeof(int)); 
	
	//printf("long int : sizeof(long int) = %ldbytes\n", sizeof(long int)); 
	
	printf("float : sizeof(float) = %lubytes, sizeof(flt) = %lubytes \n", sizeof(float), sizeof(flt));

	printf("long int : sizeof(long int) = %ldbytes\n", sizeof(long int)); 
	
	printf("double : sizeof(double) = %ldbytes\n", sizeof(double)); 
	
	return 0;
}	





















