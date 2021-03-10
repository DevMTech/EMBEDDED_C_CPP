/***************************************************************
* This the implementation for the Student class whose interface *
* fle is given in Program 8-11. *
***************************************************************/

/* // <-------------------------------------------- MOVED TO Student.h -------------------------------------------------->

#include "Student.h"

// Default constructor
Student :: Student()
{ }

// Parameter Constructor
Student :: Student (string nm, int sc)
:name (nm), score (sc)
{	char temp [ ] = {'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};
	grade = temp [score /10];
}

// Destructor
Student :: ~Student()
{ }

// Print member function
void Student :: print()
{	cout << setw (12) << left << name;
	cout << setw (8) << right << score;
	cout << setw (8) << right << grade << endl;
}

*/
