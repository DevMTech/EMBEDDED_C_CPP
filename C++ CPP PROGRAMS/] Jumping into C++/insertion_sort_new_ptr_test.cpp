#include<iostream>

int* arrInput(int arr[], int* size);
int* growArray(int* arr, int* curSize, int growSize);
void printArr(int* arr, int size);
int smallestInRemaining(int arr[], int cur_index, int size);
void swap(int* arr, int index1, int index2);
void insertionSort(int* arr, int size);

int size = 5; // DEFAULT SIZE OF ARRAY
int count;

#define ARR2DSIZE 20

int main()
{	
	std::cout << "\n -----------------INSERTION SORT------------------- \n";
	//std::cout<< "\n\n Enter array size : ";
	//std::cin>> size;
	
//	if(size < 1)
//	{
//		std::cout<<" Invalid array size entered .. taking default array size of 5 .. \n";
//		size = 5;
//	}
//	
//	if(size > ARR2DSIZE)
//	{
//		std::cout<<" Max. array size exceeded .. taking default MAX. array size of 20 .. \n";
//		size = 20;
//	}	
	
	int* arr = new int[size];  
	arr=arrInput(arr, &size);
	
	std::cin.ignore();
	
	std::cout<< "\n Array Elements (Unsorted): \n";
	printArr(arr, count);
	//std::cout<<"\n";
	
	std::cout << "\n -----------------INSERTION SORTING------------------- \n";	
	insertionSort(arr, count);
	
	std::cout<< "\n Array Elements (Sorted): \n";
	printArr(arr, count);
	
	
	std::cout<< "\n Press Enter Key to Exit \n";
	std::cin.get();
	
	return 0;
}


int* arrInput(int arr[], int* size)
{
	int i = 0, val, growSize;
	std::cout << "\n current size = " << *size << "\n";
	while(val != 1000) // int('e'))
	{	
		
		if(*size == i+1)
		{	growSize = 10;
			std::cout << "\n GROWING THE ARRAY : current size = " << *size << "\n";
			arr=growArray(arr, size, growSize);
		}
		
		std::cout<< "Enter a number (enter \'1000\' to stop entering) : "; 
		std::cin>> val;
		if(val == 1000) // int('e')) 
		{
			break;
		}
		else
		{
			arr[i++]=val;	
			count = i;
		}
		
		std::cout<< "\n";
	}
	
	return arr;
}

int* growArray(int* arr, int* curSize, int growSize)
{
	int* newArrPtr = new int[*curSize + growSize] ;
	int i;
	for(i=0; i<*curSize; i++)
	{
		newArrPtr[i]=arr[i];
	}
	*curSize += growSize;
	std::cout << "\n GROWING THE ARRAY by 10 : current size = " << *curSize << "\n\n";
	delete arr;
	return newArrPtr;
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

