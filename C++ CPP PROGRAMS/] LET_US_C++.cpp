#include<iostream>
#include<string>
#include<cmath>
using namespace std;

/*	
https://docs.oracle.com/cd/E19253-01/817-6223/chp-typeopexpr-2/index.html

Type Name 		32–bit Size 	64–bit Size 

char 			1 byte 			1 byte 
short			2 bytes 		2 bytes 
int				4 bytes 		4 bytes 
long			4 bytes			8 bytes 
long long 		8 bytes 		8 bytes 
float			4 bytes 		4 bytes 
double			8 bytes 		8 bytes 
long double		16 bytes		16 bytes 

int8_t					1 byte signed integer 
int16_t					2 byte signed integer 
int32_t					4 byte signed integer 
int64_t					8 byte signed integer 
intptr_t				Signed integer of size equal to a pointer 
uint8_t					1 byte unsigned integer 
uint16_t				2 byte unsigned integer 
uint32_t				4 byte unsigned integer 
uint64_t				8 byte unsigned integer 
uintptr_t				Unsigned integer of size equal to a pointer 

*/

int main()
{
	int i=0, k=1, n=0;	// 4294967296
	int j=1;
	cout<<" sizeof(j) = "<<sizeof(j)<<" bytes"<<endl;
	
	cout<<" sizeof(n) = "<<sizeof(n)<<" bytes"<<endl;
	
	cout<<" j = "<<j<<endl;
//	n=i * (j);
	n=i* long (j);

	while(j>-2)
	{
		j=pow(2,i)-1;
		if(j>-2)
		{cout<<"\t"<<i++<<"\t j = "<<j<<"\t\t j+1 = "<<j+1<<endl;
		}
	}
		
	cout<<" n = "<<n<<endl;
	

	
	float f = pow(2,32);
	
	cout<<" 2^(32) = "<<f<<" "<<endl;
//	cout<<" 2^(16) = "<<2^(16)<<" "<<endl;
//	cout<<" 2^(32) = "<<2^(32)<<" "<<endl;
//	cout<<" 2^(64) = "<<2^(64)<<" "<<endl;
//

	 cout << "\n\nThe size of an int is:\t\t";
	 cout << sizeof(int) << " bytes.\n";
	 cout << "The size of a short int is:\t";
	 cout << sizeof(short) << " bytes.\n";
	 cout << "The size of a long int is:\t";
	 cout << sizeof(long) << " bytes.\n";
	 cout << "The size of a char is:\t\t";
	 cout << sizeof(char) << " bytes.\n";
	 cout << "The size of a float is:\t\t";
	 cout << sizeof(float) << " bytes.\n";
	 cout << "The size of a double is:\t";
	 cout << sizeof(double) << " bytes.\n";
	 cout << "The size of a bool is:\t\t";
	 cout << sizeof(bool) << " bytes.\n\n";
	 
	 
	 
	 unsigned short int smallNumber;
	 smallNumber = 65535;
	 cout << "\nWrapping Around an Unsigned Integer : \n\n";
	 cout << "\nThe size of a short int is:\t";
	 cout << sizeof(short) << " bytes.\n";
	 cout << "unsigned short : small number:" << smallNumber << endl;
	 smallNumber++;
	 cout << "unsigned short : small number:" << smallNumber << " (65536 gets wrapped to 0) " << endl;
	 smallNumber++;
	 cout << "unsigned short : small number:" << smallNumber << endl;
		
	 short int shortInt;
	 shortInt = 32767;
	 cout << "short int : small number:" << shortInt << endl;
	 shortInt++;
	 cout << "short int : small number:" << shortInt << endl;
	 shortInt++;
	 cout << "short int : small number:" << shortInt << endl;


	return 0;
	
}
