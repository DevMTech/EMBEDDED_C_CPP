#include <iostream>
//#include <string>
#include <ctime> // time()
#include <cstdlib> // srand(), rand()

namespace Names
{	char name[] = "Ravi";
}

void sizeOfDatatypes(void); // function prototype

bool isPrime(int num);
bool isDivisible(int num, int divisor);

int getRandomNumberBtwnRange(int low, int high);

int size = 0;

#define ARR2DSIZE 20

void arrInput(int arr[], int s);
void printArr(int* arr, int size);

//void arrMultiplicationTable(int arr[][size], int size);
//void printMultiplicationTable(int arr[][size], int size);
void arrMultiplicationTable(int arr[][ARR2DSIZE], int size);
void printMultiplicationTable(int arr[][ARR2DSIZE], int size);


int smallestInRemaining(int arr[], int cur_index, int size);
void swap(int* arr, int index1, int index2);
void insertionSort(int* arr, int size);


int main()
{	int n, m;
	std::string firstName;
	std::string lastName;
	
	
	
	char sample[] = "How are you";
	//char name[10];
	//std::cin>> "Name " >> name ;
	std::cout<< "Hi! \n";
	std::cout<< sample << " " << Names::name << " ?\n";

	sizeOfDatatypes();	
	
//	int size = 0;
	
	std::cout<< "\n\n Enter array size : ";
	std::cin>> size;
	
	if(size < 1)
	{
		std::cout<<" Invalid array size entered .. taking default array size of 5 .. \n";
		size = 5;
	}
	
	if(size > ARR2DSIZE)
	{
		std::cout<<" Max. array size exceeded .. taking default MAX. array size of 20 .. \n";
		size = 20;
	}
	
	//size = ARR2DSIZE;
	//int arr2D[size][size]={0}; 
	int arr2D[ARR2DSIZE][ARR2DSIZE]={0}; 
	arrMultiplicationTable(arr2D, size);
	std::cout<< "\n Multiplication Table : \n";
	printMultiplicationTable(arr2D, size);
	std::cout<< "\n";
	
//	int** arr2Dptr = (int**)arr2D;
//	arrMultiplicationTable(arr2Dptr, size);
//	std::cout<< "\n Multiplication Table : \n";
//	printMultiplicationTable(arr2Dptr, size);
	
	
	int arr[size]={0};  
	arrInput(arr, size);
	
	std::cin.ignore();
	
	std::cout<< "\n Array Elements (Unsorted): ";
	printArr(arr, size);
	
	insertionSort(arr, size);
	
	std::cout<< "\n Array Elements (Sorted): ";
	printArr(arr, size);
	
	
	
	
	std::cout<< "\n\n Enter a number for prime check : ";
	std::cin>> n;
	std::cin.ignore();
	std::cout<< " n = " << n << " \n";
	
	if(isPrime(n))
	{
		std::cout<< n << " is prime \n";
	}
	else
	{
		std::cout<< n << " is non-prime \n";
	}
	
	std::cout<< "\n enter first name : ";
	std::cin>> firstName;
	std::cin.ignore();
	
	std::cout<< "\n enter last name : ";
	std::cin>> lastName;
	std::cin.ignore(); 
	
	std::string fullName = firstName + " " + lastName;
	
	std::cout<< " Full Name : " << fullName << "\n"; 
	
	std::cout<< "\n\n Enter lower limit for random number : ";
	std::cin>> n;
	std::cout<< "\n Enter upper limit for random number : ";
	std::cin>> m;
	
	std::srand(std::time(NULL));
	std::cout<< "\n Random number between " << n << " & " << m << " : " << getRandomNumberBtwnRange(n, m)<< "\n";
	std::cin.ignore();
	//std::cout << " Random number : "<< std::rand() << " \n" ;
	
	std::string username, password;
	
	do
	{
		std::cout<< " Enter username : ";
		std::getline(std::cin, username, '\n');
		
	}while(username != "root");
	
	std::cout<< " You finally got the username right! \n";
	
	
	std::cout<< " Enter password : ";
	std::getline(std::cin, password, '\n');
	
	if(username == "root" && password == "654")
	{
		std::cout<< " Access Granted ! \n";
	}
	else
	{
		std::cout<< " Bad Credentials .. Access Denied! Exiting ... ";
		return 0;
	}
	
	
	
	std::cout<< " Press Enter Key to Exit \n";
	std::cin.get();
	
	return 0;
}

int getRandomNumberBtwnRange(int lo, int hi)
{
	//std::srand(std::time(NULL)); // SEED FOR RANDOM NUMBER
	
	return (std::rand() % (hi-lo) + lo);
}

bool isPrime(int n)
{
	for(int i = 2; i < ((n+1)/2); i++)
	{
		if(isDivisible(n, i))
			return false;
	}
	return true;
}

bool isDivisible(int n, int d)
{
	return (n%d==0);
}

void sizeOfDatatypes()
{
	std::cout<< " size of bool " << sizeof(bool) << " byte \n";
	std::cout<< " size of char " << sizeof(char) << " byte \n";
	std::cout<< " size of short " << sizeof(short) << " bytes \n";
	std::cout<< " size of long " << sizeof(long) << " bytes \n";
	std::cout<< " size of int " << sizeof(int) << " bytes \n";
	std::cout<< " size of float " << sizeof(float) << " bytes \n";
	std::cout<< " size of double " << sizeof(double) << " bytes \n";
}

void arrInput(int arr[], int s)
{
	int i = 0;
	for(; i < s; i++)
	{	std::cout<< "Enter a number : "; 
		std::cin>> arr[i];
		std::cout<< "\n";
	}
}

void printArr(int* arr, int size)
{	
	int n = 0;
	
	for(n = 0; n < size; n++)
	{
		std::cout<< arr[n] << " "; 
	}
	std::cout<< "\n";
}

void insertionSort(int* arr, int size)
{	int n;	
	for(n=0; n<size-1; n++)
	{
		int i = smallestInRemaining(arr, n, size); 
		swap(arr, i, n);
		printArr(arr, size);
	}
}

int smallestInRemaining(int arr[], int cur_index, int size)
{	
	int i, small_index = cur_index; // , flag = 0;
	
	for(i = cur_index+1; i < size; i++)
	{
		if(arr[small_index] > arr[i])
		{	small_index = i;		//	flag = 1;
		}
		
	}
	//swap(arr, small_index, cur_index); // flag = 0;
	//std::cout << "\n smallestInRemaining : " << arr[small_index] << "; small_index : " << small_index << " : ";
	return small_index;
}

void swap(int* arr, int index1, int index2)	
{	
//	std::cout<<"\n sizeof(arr) " << sizeof(arr) << "\n";
//	std::cout<<"\n sizeof(temp) " << sizeof(temp) << "\n";
	
	int temp=arr[index1];
	arr[index1]=arr[index2];
	arr[index2]=temp;
}

void arrMultiplicationTable(int arr[][ARR2DSIZE], int size)
{
	int i = 0, j = 0;
	
	for(; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{	
			arr[i][j] = (i+1)*(j+1);
			// arr(i+j) = (i+1)*(j+1);
		}	
	} 
}


void printMultiplicationTable(int arr[][ARR2DSIZE], int size)
{
	int i = 0, j = 0;
	
	for(; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{	
			std::cout<< "\t" << arr[i][j];
			// arr(i+j) = (i+1)*(j+1);
		}	
		std::cout<< "\n";
	} 
}

/*
Primitive:
boolean(1), char(1), short(2), int(4), long(4), float(4), double(8), void

Derived:
function, array, pointer, reference

User-defined:
class, structure, union, enum, typedef 
*/
