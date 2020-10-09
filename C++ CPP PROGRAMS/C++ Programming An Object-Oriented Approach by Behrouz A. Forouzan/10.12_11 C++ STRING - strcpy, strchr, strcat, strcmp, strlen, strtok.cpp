/*

A C-string is a NULL-terminated array of characters.
To be a C-string, the last character in the array must be the null character ('\0').
To construct a C string, we must create an array of characters and set the last element to the null character '\0'.

The C-string name is a constant pointer to the first character.

#include<cstring> // The <cstring> header file is needed to use C strings.

Prototypes for functions in the <cstring> header: 
A C string is not a class type, which means there is no constructor defined in the library. 

char* str = new char [3];		// Creaton on HEAP of nonconstant string of two characters
const char* str = new char [3]; // Creaton on HEAP of constant string of two characters

delete [ ] str; // Deletion of C-string created on the HEAP

//////////////////////////////////////////////////////////////////////////

A C++ string is an array of characters, but it is not null terminated.
The C++ string is a class that matches the idea of object-oriented programming

Selected members of C++ library

// Constructors
string :: string ()
string :: string (size_type count, char c)
string :: string (const char* cstr)
string :: string (const char* cstr, size_type count)

// Destructor
string :: ~string ()

// Copy constructors
string :: string (const string& strg)
string :: string (const string& strg, size_type index, size_type length = npos)

// Operations related to size and capacity
size_type string :: size ( ) const
size_type string :: max_size ( ) const
void string :: resize (size_type n, char c )
size_type string :: capacity ( ) const
void string :: reserve (size_type n = 0)
bool string :: empty ( ) const

// Input and output
istream& operator>> (istream& in, string& strg)
ostream& operator<< (ostream& out, const string& strg)
istream& getline (istream& in, string& strg)
istream& getline (istream& in, string& strg, char delimit)

// Accessing a character given its position
const char& string :: operator[ ] (size_type pos) const
char& string :: operator[ ] (size_type pos)
const char& string :: at (size_type pos) const
char& string :: at (size_type pos)

// Accessing a substring given the position of the frst character and length
string string :: substr (size_type pos = 0, size_typ length = npos) const

// Finding the position of a given character (forward or backward search)
size_type string :: fnd (char c, size_type index = 0) const
size_type string :: rfnd (char c, size_type index = npos) const

// Finding the position of a character in a set (forward or backward search)
size_type string :: fnd_frst_of (const string& temp, size_type pos = 0)
size_type string :: fnd_last_of (const string& temp, size_type pos = npos)

// Finding the position of a character not in a set (forward or backward search)
size_type string :: fnd_frst_not_of (const string& temp, size_type pos = 0)
size_type string :: fnd_last_not_of (const string& temp, size_type pos = npos)

// Comparing two strings
int string :: compare (size_type pos1, size_type n1,const string strg2,
size_type pos2, size_type n2) const
int string :: compare (size_type pos1, size_type n1,
const char* cstr, size_type n2) const

// Logical comparison of two strings (oper can be <, <=, >, >=, ==, !=)
bool string :: operatorOper (const string strg1, const string strg2)
bool string :: operatorOper (const string strg1, const char* cstr)
bool string :: operatorOper (const char* cstr, const string strg1)

// Pushing a character at the end of a string
void string :: push_back (char c)

// Modifying a string using another string (append, insert, replace, and assign)
string& string :: append (const string& temp)
string& string :: insert (size_type pos, const string& temp)
string& string :: replace (size_type pos, size_type n, const string& temp)
string& string :: assign (size_type pos, size_type n, const string& temp)

// Clearing and erasing a string
void string :: clear ()
string& string :: erase (size_type pos = 0, size_type n = npos)

// Using the assignment operator
string& string :: operator= (const string& strg)
string& string :: operator= (const char* cstr)
string& string :: operator= (char c)

// Using the compound assignment (addition)
string& string :: operator+= (const string& strg)
string& string :: operator+= (const char* cstr)
string& string :: operator+= (char c)

// Using the addition operator
string& string :: operator+ (const string& strg1, const string& strg2)
string& string :: operator+ (const string& strg1, const char* cstr2)
string& string :: operator+ (const char* cstr1, const string& strg2)
string& string :: operator+ (const string& strg1, char c)

// Conversion to a character array
const char* string :: data () const

// Conversion to a C-string
const char* string :: c_str () const

*/


//#include <cstring> // <cstring> header file is needed to use C strings
#include <string> // To use C++ strings, we need the <string> header file. 
#include <iostream> // get, getline 


using namespace std;

int main ( )
{	string oldStrg("THIS IS THE OLD STRING !!");
	int index = 8, length = 14;
	
	string strg1 (5 , 'a'); // The string "aaaaa"
	string strg2 ("hello"); // The string "hello"
	string strg3 ("hello", 2); // The string "he
	
	string strg4 (oldStrg); // Using the whole oldStrg
	string strg5 (oldStrg, index, length); // Using part of the oldStrg
	
	cout << "\n oldStrg " << oldStrg <<"\n";
	cout << "\n strg5 \t " << strg5 <<"\n\n\n";


/***************************************************************
* The program creates a string object and then tests the size, *
* maximum size, and capacity before and after reservation. *
***************************************************************/	
// Program 10.12 Testing functions related to size and capacity
	{
		// Creating a string object
		string strg ("Hello my friends");
		size_t n = strg.size(); // Getting the size
		// string::size_type n = strg.size(); // Getting the size
		string::size_type max_n = strg.max_size(); // Getting the maximum size
		
		// Test size, maximum size and capacity
		cout << "Size: " << n << endl;
		cout << "Maximum size: " << max_n << endl;
		cout << "Capacity: " << strg.capacity() << endl;
		cout << "Empty? " << boolalpha << strg.empty() << endl;
		cout << endl;
		cout << "\n strg \t " << strg <<"\n\n\n";
		
		n = n + 10;
		strg.resize (n, 'c'); //Resizing and flling the rest of string with 'c'
		cout << "\n strg \t " << strg <<"\n\n\n";
		
		// Making reservation and test again
		strg.reserve (20);
		cout << "Size: " << strg.size () << endl;
		cout << "Maximum size: " << strg.max_size() << endl;
		cout << "Capacity: " << strg.capacity() << endl;
		cout << "Empty? " << boolalpha << strg.empty();
	}
	

	
	
	return 0;
}
