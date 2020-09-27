/***************************************************************
* This is the interface fle for a Student class with three *
* private data members and four public member functions. *
***************************************************************/
#ifndef STUDENT_H
#define STUDENT_H
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Student
{
	private:
		string name;
		int score;
		char grade;
		
	public:
		Student ();
		Student (string name, int score);
		~Student ();
		void print();
};

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


#endif
