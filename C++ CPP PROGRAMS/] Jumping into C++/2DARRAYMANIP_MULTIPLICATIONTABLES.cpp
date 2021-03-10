#include<iostream>

int size = 0;

#define ARR2DSIZE 20

void arrInput(int arr[], int s);
void printArr(int* arr, int size);

//void arrMultiplicationTable(int arr[][size], int size);
//void printMultiplicationTable(int arr[][size], int size);
void arrMultiplicationTable(int arr[][ARR2DSIZE], int size);
void printMultiplicationTable(int arr[][ARR2DSIZE], int size);

int main()
{	
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

	return 0;
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
