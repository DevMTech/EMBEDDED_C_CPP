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


#include <cstring> // <cstring> header file is needed to use C strings
//#include <string> // To use C++ strings, we need the <string> header file. 
#include <iostream> // get, getline 

using namespace std;

int main ( )
{	
	{	// 'str' is a char array, not a C-string as it is not terminated by '\0'
		char str [ ] = {'A', 'B', 'C', 'D'}; 
	
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
		const char ch [] = " buddy!";
		cout << str << ch << endl;
				
		char str1 [ ] = "Hello1"; 		// MUTABLE CHAR ARRAY // "Hello" is a compact initializer
		const char str2 [] = "Hello2";  // CHAR ARRAY: IMMUTABLE BY CHOICE // "Hello" is a compact initializer
		const char *str3 = "Hello3"; 	// STRING: IMMUTABLE BY DESIGN // "Hello" is a string literal
		
		cout << "\nchar str1[] is mutable : " << str1;

/***************************************************************
* The program shows how to access a character in a string *
* using the subscript operator. *
***************************************************************/
		// Changing character at a given position
		str1 [5] = '!';
		cout << "\nstr1 after change: " << str1;
		
		cout << "\n\nconst char str2[] is immutable : " << str2;
		// Retrieving character at a given position
		cout << "\nCharacter at index 5 in str2: " << str2[5] << endl;
		
		cout << "\n\nconst char str3[] is immutable : " << str3;
		// Retrieving character at a given position
		cout << "\nCharacter at index 5 in str3: " << str3[5] << endl << endl << endl;
		
		//str2 [5] = '!'; // [Error] assignment of read-only location 'str2[5]'
		//cout << "str2 after change: " << str2;
		
		//str3 [5] = '!'; // [Error] assignment of read-only location '(str3 + 5u)'
		//cout << "str3 after change: " << str3;
		
		cout << "\'Hello world!\' is a string literal." << endl << endl; // Printing a string literal	
	}
	
/***************************************************************
* The program shows how to use strcpy and strncpy to replace *
* the whole string or part of it with the whole or part of *
* another string. *
***************************************************************/	
	{	// Program 10.1 Copying in a C string library 
		// Copy the whole str2 to str1. String str1 is erased.
		char str1 [] = "This is the first string....";
		char str2 [] = "This is the second string!!!!!";
		cout << "str1: " << str1 << endl;
		cout << "str2: " << str2 << endl;
		strcpy (str1, str2); // char* strcpy(char*, const char*)
		cout << endl << "After strcpy() " << endl << "str1: " << str1 << endl;
		cout << "str2: " << str2 << endl;
		
		// Copy part of str4 to str3. str3 is partially erased.
		char str3 [] = "abcdefghijk.";
		const char *str4 = "ABCDEFGHIJK";
		cout << endl << "str3: " << str3 << endl;
		cout << "str4: " << str4 << endl << endl;
		strncpy (str3, str4, 4);
		cout << "After strcpy() " << endl << "str3: " << str3 << endl;
		cout << "str4: " << str4 << endl << endl << endl;
		
		const char *strPtr = "I am pointer to the new char array";
		cout << " const char *strPtr = " << strPtr << endl;
		
		strcpy(str1, strPtr); // char* strcpy(char*, const char*)
		cout << " strcpy(str1, strPtr) : str1 = " << str1 << endl << endl << endl;
		
		// string names str1, str2, str3 are rvalue pointers, not variables. 		
		// To create a variable, declare a variable of type char* or const char* 
		// and assign the name of the string to that variable.
		char *pStrVar = str1;
		const char *cpStrVar = str3; 
		
		strcpy(pStrVar, cpStrVar); // char* strcpy(char*, const char*)
		// return pStrVar; // we can return a pointer variable pointing to a C-string from a function.

		strcat (str1, str2); // Using strcat function
		cout << "\nstrcat (str1, str2) : str1 = " << str1 << endl;
		
		strncat (str3, str4, 4); // Using strncat function
		cout << "\nstrncat(str3, str4, 4) : str3 = " << str3 << endl << endl << endl;
		
/***************************************************************
* The program shows how to get the length of a C-string, which *
* is the number of characters before the null character *
***************************************************************/		
		// Finding and printing the length of each string
		cout << "Length of str1: " << strlen (str1) << endl;
		cout << "Length of str2: " << strlen (str2) << endl << endl << endl;
	}
	
	
/***************************************************************
* A program to search for a given character using forward *
* search to find the first occurrence or backward search to *
* to find the last occurrence *
***************************************************************/
	{ 	// Program 10.6 Finding the start of a substring(or character)
		// Declaration of a string
		char str [ ] = "Hello friends.";
		
		// char* ptr = strchr  (str, 'o');
		// char* ptr = strrchr (str, 'o');
		
		// cout << endl << " strstr(str, \"Hello\") : " << strstr(str, "Hello") << endl;
		
		cout << " strchr (str, \'c\') and strrchr (str, \'c\') member functions return a pointer to the character being searched !!! \n\n\n";
		cout << " str : " << str << endl << endl;
		
		// Capitalizing the frst occurrence of character e
		char* cPtr = strchr (str, 'e'); // Forward search
		*cPtr = 'E' ;
		cout << "strchr(str, 'e'): FORWARD SEARCH: 1ST OCCURANCE -> \n str after FIRST occurance of \'e\'changed to \'E\': \n str : " << str << endl;
		
		// Capitalizing the last occurrence of character e
		cPtr = strrchr (str, 'e'); // Backward search
		*cPtr = 'E' ;
		cout << "\n\nstrrchr(str, 'e'): BACKWARD/REVERSE SEARCH: LAST OCCURANCE -> \n str after LAST occurance of \'e\'changed to \'E\': \n str : " << str << endl << endl << endl;
	}
	
	
/***************************************************************
* The program shows how we can compare two strings using the *
* strcmp and strncmp functions. *
***************************************************************/
	{ 	// Program 10.9 Comparing C strings
		// Declaration of two C-strings
		const char* str1 = "Hello Alice.";
		const char* str2 = "Hello John.";
		const char* str3 = "Hello Betsy.";
		
		// Comparison use the whole length
		cout << "strcmp (str1, str2): Comparing str1 ("<<str1<<") and str2 ("<<str2<<") : ";
		cout << strcmp (str1, str2) << " (A < J)" << endl;
		
		cout << "strcmp (str2, str3): Comparing str2 ("<<str2<<") and str3 ("<<str3<<") : ";
		cout << strcmp (str2, str3) << " (J > B)" << endl;
		
		// Comparison using one the frst characters
		cout << "strncmp (str1, str2, 5): Comparing first 5 characters of str1 ("<<str1<<") and str2 ("<<str2<<") : ";
		cout << strncmp (str1, str2, 5) << endl << endl;
	}

/***************************************************************
* The program shows how we can use the strtok function to extract *
* tokens from a date. *
***************************************************************/	
	{	// Program 10.11 Tokenizing a string
		// The strtok (...) function splits a string into tokens 
		// using delimiter characters which can be anything 
		// from a  comma (',') or space (' ') to chars ('o'),('f').
		
		int i = 0;
		// Declaration of a sentence and a pointer array
		char str [ ] = "Your Date Of\' Birth : 5th / July, of 2015 ... ! :)";
		cout << endl << " Actual str = " << str << endl << endl;		
		
		// Use strtok to extract all words
		const char delimiter[] = ", . / : "; // string of delimiter characters
		char *pStr[] = {strtok (str, delimiter)}; // first call // delimiter can be both char* & char[]
		cout << endl << " *pStr = "  << *pStr << endl;
		
		char *p[10]; // array of char pointers to collect the tokens 
		const char *delimiters = "!. / , : fo"; // string of delimiter characters
		cout << endl << " Delimiters = " << delimiters << endl; 
		p[0] = strtok(str, delimiters);		
		
		cout << endl << " Tokenized str = \n" ;
		while (p[i])
		{	cout << " p[" << i << "] = " << p[i] << endl; 		//++i;
			// Tokenizing str using a string of delimiter characters
			p[++i] = strtok (0, delimiters); // delimiter can be both char* & char[]	
		}
	}
	
/***************************************************************
* The program shows how to read a set of lines using the *
* get/getline functions and print them. *
***************************************************************/	
	cout << endl << endl;
	{ // Program 10.4 Using an array of strings
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
