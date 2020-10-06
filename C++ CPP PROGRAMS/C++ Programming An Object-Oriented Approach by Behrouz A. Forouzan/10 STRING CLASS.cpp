/*

A C-string is a NULL-terminated array of characters.
To be a C-string, the last character in the array must be the null character ('\0').
To construct a C string, we must create an array of characters and set the last element to the null character '\0'.

The C-string name is a constant pointer to the first character.

A C++ string is an array of characters, but it is not null terminated.
The C++ string is a class that matches the idea of object-oriented programming

#include<cstring> // The <cstring> header file is needed to use C strings.

Prototypes for functions in the <cstring> header: 

A C string is not a class type, which means there is no constructor defined in the library. 

char* str = new char [3];		// Creaton on HEAP of nonconstant string of two characters
const char* str = new char [3]; // Creaton on HEAP of constant string of two characters

delete [ ] str; // Deletion of C-string created on the HEAP

// Copy construction (two member functions are designed for copying a string)
char* strcpy (char* str1, const char* str2)
char* strncpy (char* str1, const char* str2, size_t n)

// Finding the length
size_t strlen (const char* str) 

// Searching for a character (forward and backward)
char* strchr (const char* str, int c)
char* strrchr (const char* str, int c)

// Searching for a substring
char* strstr (const char* str, const char* substr) 

// Searching for a character in a set (only forward search)
char* strpbrk (const char* str, const char* set)

// Comparing two strings
int strcmp (char* str1, const char* str2)
int strncmp (char* str1, const char* str2, size_t n)

// Concatenation (appending a string at the back of another)
char* strcat (char* str1, const char* str2)
char* strncat (char* str1, const char* str2, size_t n)

// Tokenizing
char* strtok (char* str, const char* delimit)



cin.getline (str, length); 			// Using '\n' as the delimiter
cin.get (str, length, 'delimeter'); 	// Using a specifc delimiter



*/

/***************************************************************
* The program shows how to use strcpy and strncpy to replace *
* the whole string or part of it with the whole or part of *
* another string. *
***************************************************************/
#include <cstring> // <cstring> header file is needed to use C strings
#include <string> // To use C++ strings, we need the <string> header file. 
#include <iostream> // get, getline 

using namespace std;

int main ( )
{	
	{
		// '\0' explicitly required at the end
		char str1 [ ] = {'A', 'B', 'C', 'D', '\0'}; // Nonconstant C-string (array of characters)
		const char str2 [ ] = {'A', 'B', 'C', 'D', '\0'}; // Constant C-string
		
		// '\0' implicitly appended at the end in case of compact intialization
		char str3 [ ] = "ABCD"; // Nonconstant compact C-string -> compact initialization 
		const char str4 [ ] = "ABCD"; // Constant compact C-string
		
		
		
		char* pstr = new char [3];		// Creation on HEAP of nonconstant string of two characters
		const char* cpstr = new char [3]; // Creation on HEAP of constant string of two characters
		delete [] pstr; // Deletion of C-string created on the HEAP
		delete [ ] cpstr; // Deletion of C-string created on the HEAP
		
	}
	
	{
		// A string literal is a null-terminated array of characters whose name is 
		// the sequence of characters in the array enclosed by two quotation marks.
		
		// A string literal is a constant entity; it cannot be changed.
		// C++ forbids assigning a string literal to a nonconstant pointer to a character.
		// Assigning a string literal to a nonconstant pointer results in a compilation error.
		//char* str = "Hello"; 		// Error. String literal is a constant
		const char *str = "Hello";  // OK
		const char ch [] = "buddy!";
		cout << str << ch << endl;
				
		char str1 [ ] = "Hello1"; 		// MUTABLE CHAR ARRAY // "Hello" is a compact initializer
		const char str2 [] = "Hello2";  // CHAR ARRAY: IMMUTABLE BY CHOICE // "Hello" is a compact initializer
		const char *str3 = "Hello3"; 	// STRING: IMMUTABLE BY DESIGN // "Hello" is a string literal
				

		
		cout << "Hello world!" << endl; // Printing a string literal	
	}
	
	
	{
		// Copy the whole str2 to str1. String str1 is erased.
		char str1 [] = "This is the first string....";
		char str2 [] = "This is the second string!!!!!";
		strcpy (str1, str2); // char* strcpy(char*, const char*)
		cout << "str1: " << str1 << endl;
		cout << "str2: " << str2 << endl;
		
		// Copy part of str4 to str3. str3 is partially erased.
		char str3 [] = "abcdefghijk.";
		const char *str4 = "ABCDEFGHIJK";
		strncpy (str3, str4, 4);
		cout << "str3: " << str3 << endl;
		cout << "str4: " << str4 << endl;
		
		const char *strPtr = "I am pointer to the new char array";
		cout << "strPtr: " << strPtr << endl;
		
		strcpy(str1, strPtr); // char* strcpy(char*, const char*)
		cout << "str1: " << str1 << endl;
		
		// string names str1, str2, str3 are rvalue pointers, not variables. 		
		// To create a variable, declare a variable of type char* or const char* 
		// and assign the name of the string to that variable.
		char *pStrVar = str1;
		const char *cpStrVar = str3; 
		
		strcpy(pStrVar, cpStrVar); // char* strcpy(char*, const char*)
		// return pStrVar; // we can return a pointer variable pointing to a C-string from a function.

		
		// Finding and printing the length of each string
		cout << "Length of str1: " << strlen (str1) << endl;
		cout << "Length of str2: " << strlen (str2) << endl;
	}
	
	{
		// Declaration of an array of strings
		char lines [3][80];
		// Inputting three lines
		for (int i = 0; i < 3; i++)
		{	cout << "Enter a line of characters: ";
			cin.getline (lines [i], 80); // '\n' is the default delimiter or input line terminator  
			// cin.get(lines, 80, '\n'); // equivalent to above, here delimiter can be changed as desired 
		}
		// Outputting three lines
		cout << endl << "Output: " << endl;
		for (int i = 0; i < 3; i++)
		{	cout << lines [i] << endl;
		}
	}
	
	return 0;
}
