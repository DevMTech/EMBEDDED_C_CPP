#include<string>
#include "Birthday.h"

class Person
{
	public:
		Person(string n, Birthday b): name(n), dateOfBirth(b)
		{
		}
		
	void printInfo()
	{
		cout << " Name : "	<< name << endl << " DOB  : ";
		
		dateOfBirth.printDate();
	}	
	
	private:
		string name;
		Birthday dateOfBirth; // Person class has a member of type Birthday
};

/*
In C++, object composition involves using classes as member variables in other classes.
Composition is used for objects that share a has-a relationship, as in "A Person has a Birthday".
*/
