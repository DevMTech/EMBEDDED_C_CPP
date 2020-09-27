#include<iostream>
#include<string>
using namespace std;

	class Father
	{
		public:
			Father(){};	
			void greet(string s)
			{	cout << endl << " Hi " << s << "!" << endl;
			}
	};
	
	class Mother
	{
		public:
			Mother()
			{	cout << endl << "MOTHER CTOR" << endl;
			}
			
			~Mother()
			{
				cout << endl << "MOTHER DTOR" << endl;	
			}
			//Mother(int a): protecVar(a){}
			
			void printName(string n)
			{
				cout << endl << " I am " << n << endl;
			}
			
		protected:
			int protecVar;	
			
	};
	
	// The Base class is specified using a colon and an access specifier: public means, that all public members of the base class are public members of the derived class.
	class Daughter : public Father, public Mother  
	{
		public:
			//Daughter(int b): protecVar(b){}
			Daughter()
			{	cout << endl << "DAUGHTER CTOR" << endl;
			}
			
			~Daughter()
			{	cout << endl << "DAUGHTER DTOR" << endl;
			}
						
			printVar()
			{
				cout << " " << protecVar;
			}
		
	};
	
	int main()
	{	Mother m;
		Daughter d;
		
		m.printName("Mother");
		d.printName("Daughter");
		d.greet("Dad");
		
		d.printVar();
		
		return 0;
	}	
	


/*
The idea of inheritance implements the is a relationship. For example, mammal IS-A animal, dog IS-A mammal, hence dog IS-A animal as well.

A derived class inherits all base class methods with the following exceptions:
- Constructors, destructors
- Overloaded operators
- The friend functions

A class can be derived from multiple classes by specifying the base classes in a comma-separated list.

A protected member variable or function is very similar to a private member, with one difference - it can be accessed in the derived classes.


Public Inheritance: public members of the base class become public members of the derived class and protected members of the base class become protected members of the derived class. 
A base class's private members are never accessible directly from a derived class, but can be accessed through calls to the public and protected members of the base class.

Protected Inheritance: public and protected members of the base class become protected members of the derived class.

Private Inheritance: public and protected members of the base class become private members of the derived class.

If no access specifier is used when inheriting classes, the type becomes private by default.

When inheriting classes, the base class' constructor and destructor are not inherited.
However, they are being called when an object of the derived class is created or deleted.

When the object of a derived class is created, the base class' constructor is called first, and the derived class' constructor is called next.
When the object is destroyed, the derived class's destructor is called first, and then the base class' destructor is called. 



*/
