/***************************************************************
* Use of an array to read a list of integers from a fle, to *
* reverse the order of elements, and to write the reversed *
* elements to another fle *
***************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

int main ( )
{
	// Declarations
	const int CAPACITY = 50;
	int numbers [CAPACITY];
	int size = 0;
	ifstream inputFile;
	ofstream outputFile;
	// Openning the input fle
	inputFile.open ("inFile.txt"); // ("inFile.dat");
	if (!inputFile)
	{	cout << "Error. Input file cannot be opened." << endl;
		cout << "The program is terminated";
		return 0;
	}
	// Reading the list of numbers from the input fle into array
	while (inputFile >> numbers [size] && size <= 50)
	{	size++;
	}
	// Closing the input fle
	inputFile.close();
	// Opening the output fle
	outputFile.open ("outFile.txt"); // ("outFile.dat");
	if (!outputFile)
	{	cout << "Error. Output file cannot be opened." << endl;
		cout << "The program is terminated.";
		return 0;
	}
	// Writing the elements of the reversed array into the output fle
	for (int i = size - 1 ; i >= 0 ; i--)
	{	outputFile << numbers[i] << " " ;
	}
	// Closing the output fle
	outputFile.close();
	return 0;
}
