// https://www.sololearn.com/Play/CPlusPlus

#include "MyClass.h"

#include <iostream>
using namespace std;



template<class T> // FUNCTION TEMPLATE
T sum(T a, T b) // The function returns a value of the generic type T, taking two parameters, also of type T.
{ return a+b;
}

template<class I, class D> // FUNCTION TEMPLATE WITH MULTIPLE PARAMETERS
D larger(I a, D b)
{
	return(a > b ? a : b);
} 


template<class T> // CLASS TEMPLATE
class Pair
{	private:	T first, second;
		
	public:		Pair(T a, T b): first(a), second(b){}
								
				T smaller() // MEMBER FUNCTION OF CLASS TEMPLATE DEFINED INSIDE THE CLASS TEMPLATE
				{	return (first < second ? first : second);
				}
				
				T bigger();
};

template<class T> // MEMBER FUNCTION OF CLASS TEMPLATE DEFINED OUTSIDE THE CLASS TEMPLATE
T Pair<T>::bigger() 
{	return (first > second ? first : second);
}

//MyClass::MyClass()
//{
//    cout << "MyClass() CONSTRUCTOR called" << endl;//ctor
//}

MyClass::MyClass(int a, int b) : regVar(a), constVar(b) // Ctor Initialization List
{	
	cout << endl << "MyClass(int, int) CONSTRUCTOR called" << endl;//ctor
	cout << "regVar   " << regVar << endl;
	cout << "constVar " << constVar << endl;
}

MyClass::~MyClass() // dtor
{
    cout << endl << "~MyClass() DESTRUCTOR called" << endl;
}

void MyClass::myPrint()
{
	cout << endl << "MY_PRINT()" << endl;
	
	cout << " regVar         " << regVar << endl;
	
	cout << " this->regVar   " << this->regVar << endl;
	
	cout << " (*this).regVar " << (*this).regVar << endl;
	
}

//void MyClass::myConstPrint() const
//{
//	cout << "constVar   " << constVar << endl;
//}

int main()
{
	int i = 9, j = 8;
	double a = 125.254, b = 547.365; 
    //const 
	MyClass obj(20, 30); // The constructor is used to create the object, assigning two parameters to the member variables via the member initialization list.
    
    //const 
	MyClass *objPtr;
    
    obj.myPrint();
	
	objPtr = &obj;
	
	objPtr->myPrint();
	
	friendFunc(obj);
	
	objPtr->myPrint();
	
	MyClass obj1(70, 80), obj2(100, 120);
	
	MyClass obj3(150, 200);
	
	obj3 = obj1+obj2;
	
	cout << endl << " obj3 = obj1+obj2; " << endl;
	  
	obj3.myPrint();
	
	
	cout << endl << " " << i << " + " << j << " = " << sum(i, j) << endl;
	
	cout << endl << " " << a << " + " << b << " = " << sum(a, b) << endl;
	
	
	cout << endl << " " << b << " vs " << j << " larger " <<  larger(b, j) << endl; 
	
	
	Pair<int> objI(i, j);
	
	cout << endl  << " " << i << " vs " << j << " bigger " << objI.bigger() << endl;
	
	
	Pair<double> objD(a, b);
	
	cout << endl << " " << a << " vs " << b << " smaller " << objD.smaller() << endl;
	
    return 0;
}

/*
It's a good practice to use public methods to access private class variables.

Since myPrint() is a regular member function, it's necessary to specify its return type in both the declaration and the definition.
The type of the pointer ptr is MyClass, as it points to an object of that type.
When working with an object, use the dot member selection operator (.).
When working with a pointer to the object, use the arrow member selection operator (->).

All constant variables must be initialized at the time of their creation.

When you've used const to declare an object, you can't change its data members during the object's lifetime.
Only non-const objects can call non-const functions.
A constant object can't call regular functions. Hence, for a constant object to work you need a constant function.

To specify a function as a const member, the const keyword must follow the function prototype, outside of its parameters' closing parenthesis. 
For const member functions that are defined outside of the class definition, the const keyword must be used on both the function prototype and definition.

Attempting to call a regular function from a constant object results in an error.
In addition, a compiler error is generated when any const member function attempts to change a member variable or to call a non-const member function.

The initialization list eliminates the need to place explicit assignments in the constructor body. Also, the initialization list does not end with a semicolon.

The member initialization list may be used for regular variables, and must be used for constant variables.

In C++, object composition involves using classes as member variables in other classes.

Every object in C++ has access to its own address through an important pointer called the this pointer.
this pointer points to the address of the current object.
Inside a member function this may be used to refer to the invoking object.
this is a pointer to the object, so the arrow selection operator is used to select the member variable.
Only member functions have a this pointer.
Friend functions do not have a this pointer, because friends are not members of a class. 

Most of the C++ built-in operators can be redefined or overloaded.
Thus, operators can be used with user-defined types as well (for example, allowing you to add two objects together).
Operators that can't be overloaded include :: | .* | . | ?:

Overloaded operators are functions, defined by the keyword operator followed by the symbol for the operator being defined.
An overloaded operator is similar to other functions in that it has a return type and a parameter list.
With overloaded operators, you can use any custom logic needed. 
However, it's not possible to alter the operators' precedence, grouping, or number of operands.

The idea of inheritance implements the is a relationship. For example, mammal IS-A animal, dog IS-A mammal, hence dog IS-A animal as well.

Template functions can save a lot of time, because they are written only once, and work with different types. 
*/
