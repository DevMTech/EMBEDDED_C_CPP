//============================================================================
// Name        : ARRAYS_&_FUNCTIONS.cpp
// Author      : DEBAJYOTI_MAITRA
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#define arrSize(x) sizeof(x)/sizeof(x[0])

#include <iostream>
using namespace std;

string numbers[] = {"one", "two", "three", "four", "five", "six"}; // Could declare variables here!




void show1(const int n, string texts[])
{	cout << " show1(const int n, string texts[]) " << endl << endl;
	cout << " sizeof(texts) = " << sizeof(texts) << " bytes (= size of ptr = size of long) // returns sizeof string pointer!" << endl << endl; // returns sizeof string pointer!

	for(int i=0; i<n; i++) // for(int i=0; i < arrSize(texts); i++)  // DOESN'T WORK
	{	cout << texts[i] << endl;
	}
	cout << endl << "<<<<<<<<<<<<<<<<<" << endl << endl;
}






void show2(const int n, string *texts)
{	cout << " show2(const int n, string *texts) " << endl << endl;
	cout << " sizeof(texts) = " << sizeof(texts) << " bytes (= size of ptr = size of long) // returns sizeof string pointer!!" << endl << endl; // returns sizeof pointer!

	for(int i=0; i<n; i++) // for(int i=0; i < arrSize(texts); i++)  // DOESN'T WORK
	{	cout << texts[i] << endl;
	}
	cout << endl << "<<<<<<<<<<<<<<<<<" << endl << endl;
}






// NOT SCALABLE
void show3(string (&texts)[4]) // void show3(string (&texts)[arrSize(texts)]) // DOESN'T WORK !!
{	cout << " show3(string (&texts)[4])  // NOT A SCALABLE TECHNIQUE " << endl << endl;
	cout << " sizeof(texts) = " << sizeof(texts) << " bytes [24 bytes for each element of the string array]" << endl << endl; // returns sizeof pointer!

	for(unsigned int i=0; i<arrSize(texts); i++) // for( int i=0; i<sizeof(texts)/sizeof(string); i++)
	{		cout << texts[i] << endl;
	}
	cout << endl << "<<<<<<<<<<<<<<<<<" << endl << endl;
}





void show4()
{	cout << " show4() // GLOBAL string VARIABLE, NO string PASSED AS PARAMETER " << endl << endl;	//cout << " show4(string (&numbers)[arrSize(numbers)]) " << endl << endl;
	cout << " sizeof(numbers) = " << sizeof(numbers) << " bytes [24 bytes for each element of the string array]" << endl << endl; // returns sizeof pointer!

	for(unsigned int i=0; i<arrSize(numbers); i++)
	{		cout << numbers[i] << endl;
	}
	cout << endl << "<<<<<<<<<<<<<<<<<" << endl << endl;
}

char* getMemory()
{	char* pMem = new char[100];
	return pMem;
}

void freeMemory(char* pMem)
{	delete [] pMem;
}

int main()
{
	string texts[] = {"apples", "oranges", "bananas", "pears"};

	cout << " sizeof(texts) = " << sizeof(texts) << " bytes [24 bytes for each element of the string array]" << endl << endl; // returns sizeof pointer!

	show1(arrSize(texts), texts);
	show2(arrSize(texts), texts);
	show3(texts);
	show4(); // show4(texts);

	char *pMemory = getMemory();
	freeMemory(pMemory);

	return 0;
}
