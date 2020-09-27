/***************************************************************
* The program shows how to transform a two-dimensional array to *
* two one-dimensional arrays using row-by-row or column-by-column *
* transformation. *
***************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

/***************************************************************
* The rowTransform function creates a one-dimensional array from *
* a two-dimensional array using row-by-row transformation. The *
* frst array is passed as a const to prevent changes. *
***************************************************************/
void rowTransform (const int originArray [][4], int rowSize, int rowArray[])
{
	int i = 0;
	int j = 0;
	for (int k = 0 ; k < 8; k++)
	{	rowArray [k] = originArray [i] [j];
		j++;
		if (j > 3)
		{	i++;
			j = 0;
		}
	}
}

/***************************************************************
* The colTransform function creates a one-dimensional array from *
* a two-dimensional array using column-by-column transformation. *
* The frst array is passed as a constant to prevent changes. *
***************************************************************/
void colTransform (const int originArray [][4], int rowSize, int colArray[])
{	int i = 0;
	int j = 0;
	for (int k = 0 ; k < 8; k++)
	{	colArray[k] = originArray [i][j];
		i++;
		if (i > 1)
		{	j++;
			i = 0;
		}
	}
}

/***************************************************************
* The function prints the contents of a two-dimensional array *
* passed to it as a constant argument. *
***************************************************************/
void printTwoDimensional (const int twoDimensional [][4], int rowSize)
{	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < 4; j++)
		{	cout << setw (4) << twoDimensional [i][j];
		}
		cout << endl;
	}
	cout << endl;
}

/***************************************************************
* The function prints the contents of a one-dimensional array *
* passed to it as a constant argument. *
***************************************************************/
void printOneDimensional (const int oneDimensional[], int size)
{	for (int i = 0; i < size; i++)
	{	cout << setw (4) << oneDimensional[i];
	}
	cout << endl;
}

int main ( )
{
	// Declaration of three arrays and initialization of the frst
	int originArray [2][4] = {{0, 1, 2, 3}, {10, 11, 12, 13}};
	int rowArray [8];
	int colArray [8];
	
	// Calling two functions to transform arrays
	rowTransform (originArray, 2, rowArray);
	colTransform (originArray, 2, colArray);
	
	// Printing the two-dimensional array
	cout << " Original Array " << endl;
	printTwoDimensional (originArray, 2);
	
	// Printing the row-transformed one-dimensional array
	cout << "Row-Transformed Array: ";
	printOneDimensional (rowArray, 8);
	
	// Printing the col-transformed one-dimensional array
	cout << "Column-Transformed Array: ";
	printOneDimensional (colArray, 8);
	
	return 0;
}


