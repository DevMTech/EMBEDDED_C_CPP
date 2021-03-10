/***************************************************************
* The program reads a list of integers from a fle and creates a *
* frequency array and histogram for the list of integers between *
* 0 and 9 (inclusive). *
***************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main ( )
{
	// Declaration and initialization
	const int CAPACITY = 10;
	int frequencies [CAPACITY] = {0};
	ifstream integerFile;
	
	// Opening integer fle
	integerFile.open ("integerFile.txt");
	if (!integerFile)
	{	cout << "Error. Integer fle cannot be opened." << endl;
		cout << "The program is terminated.";
		return 0;
	}
	
	// Reading from the integer fle and creating frequency array
	int data;
	int size = 0;
	while (integerFile >> data )
	{	if (data >= 0 && data <= 9)
		{	size++;
			frequencies[data]++;
		}
	}
	
	// Closing integer fle
	integerFile.close();
	
	// Printing frequencies and histogram
	cout << "There are " << size << " valid data items.\n\n HISTOGRAM (frequency of occurance of each integer) : \n" << endl;
	for (int i = 0; i < 10 ; i++)
	{	cout << setw (3) << i << " ";
		for (int f = 1; f <= frequencies [i] ; f++)
		{	cout << '*' ;
		}
		cout << " " << frequencies [i] << endl;
	}
	return 0;
}
