/***************************************************************
* Use of an array to read a list of integers from a file, to *
* reverse the order of elements, and to write the reversed *
* elements to another fle *
***************************************************************/
#include <iostream>
#include <fstream>
using namespace std;


//void function (const type array [], int size);		// Only for accessing, array will not change
//void function ( type array [], int size); 			// For modifying, array will change
//void (const type array1 [ ], type array2 [ ], int size); // array1 will not change, but array 2 can be modifed version of array1.
// type [ ] function (const type array [], int size); // It is not allowed in C++
/***************************************************************
* Function reverse is a function that takes two arrays. It uses *
* the frst array to reverse the element in the second array. *
***************************************************************/
void reverse (const int array1[], int array2[], int size)
{	for (int i = 0, j = size - 1; i < size; i++, j--)
	{	array2 [j] = array1 [i];
	}
return;
}

/***************************************************************
* Function multiplyByTwo is a modifying function that changes *
* the array in main. There is no const modifer here. *
* The function accesses the array in main and modifes it. *
***************************************************************/
void multiplyByTwo (int numbers [ ], int size)
{
for (int i = 0; i < size; i++)
{
numbers [i] *= 2;
}
return;
}

/***************************************************************
* Function print accepts the name and the size of an array. *
* It then prints the elements of the array without modifying it. *
***************************************************************/
void print (const int array [], int size)
{	for (int i = 0; i < size; i++)
	{	cout << array [i] << " ";
	}
	cout << endl;
	return;
}

int main ( )
{	
	// Declaration of two arrays
	int array1 [5] = {150, 170, 190, 110, 130};
	int array2 [5];
	// Calling reverse function to modify array2 to be the reverse of array1
	reverse (array1, array2 , 5);
	// Printing both arrays
	print (array1, 5);
	print (array2, 5);
	
	// Array and variable declarations
	const int CAPACITY = 50;
	int numbers [CAPACITY];
	int size = 0;
	ifstream inputFile; // File declaration
	ofstream outputFile;
	
	// Initialization
	int sum = 0;
	double average;
	int smallest = 1000000;
	int largest = -1000000;
	int value = 0;
	int index = 0;
	
	// Openning the input file with opening validation
	inputFile.open ("inFile.txt"); // ("inFile.dat");
	if (!inputFile)
	{	cout << "Error. Input file cannot be opened." << endl;
		cout << "The program is terminated";
		return 0;
	}
	
	cout << "\n CONTENTS OF ORIGINAL FILE : \n";
	// Reading (copying) the list of numbers from the input file into array
	while (inputFile >> numbers [size] && size <= 50)
	{	//cout << numbers[size] << " " ;
		size++;
	}
	// Closing the input file
	inputFile.close();
	
		// Printing the array before being modifed
	print (numbers, size);
	
	// Finding sum, average, smallest, and the largest
	for (int i = 0; i < size; i++)
	{	sum += numbers[i];
		if (numbers[i] < smallest)
		{		smallest = numbers[i];
		}
		if (numbers[i] > largest)
		{		largest = numbers[i];
		}
	}
	average = static_cast <double> (sum) / size;
	// Printing results
	cout << "\n\nThere are " << size << " numbers in the list" << endl;
	cout << "The sum of them is: " << sum << endl;
	cout << "The average of them is: " << average << endl;
	cout << "The smallest number is: " << smallest << endl;
	cout << "The largest number is: " << largest << endl;
		
		
	cout << "Enter the number you wish to search : ";
	cin >> value;	
	bool found = false;
	for (int i = 0; (i < size) && (!found); i++)
	{	if (numbers [i] == value)
		{		index = i;
				found = true;
		}
	}
	
	if (found)
	{	cout << "\nThe value was found at index: " << index << endl;
	}
	else
	{	cout << "\nThe value was not found!!\n";
	}	
		
	
	cout << "\n ARRAY ELEMENTS * 2 : \n";
	// Modifying the array in multiplyByTwo function
	multiplyByTwo (numbers , size);
	// Printing the array after being modifed
	print (numbers, size);	
		
	// Opening the output file
	outputFile.open ("outFile.txt"); // ("outFile.dat");
	if (!outputFile)
	{	cout << "Error. Output file cannot be opened." << endl;
		cout << "The program is terminated.";
		return 0;
	}
	
	cout << "\n CONTENTS OF NEW FILE : \n";
	// Writing the elements of the reversed array into the output fle
	for (int i = size - 1 ; i >= 0 ; i--)
	{	outputFile << numbers[i] << " " ;
		cout << numbers[i] << " " ;
	}
	
	
	// Closing the output fle
	outputFile.close();
	

	
	return 0;
}
