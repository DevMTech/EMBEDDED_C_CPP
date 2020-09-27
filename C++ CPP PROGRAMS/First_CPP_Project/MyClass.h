#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>
using namespace std;

class MyClass
{
    public:
        MyClass(){} // Ctor
        MyClass(int, int); // Parameterized Ctor 
        ~MyClass(); // Dtor
        //void myConstPrint() const; // const member function -> for const objects of the class
		void myPrint(); // member function/method
		
		MyClass operator+(MyClass &obj) // overloading the + operator. It will return an object of the class and take an object of the class as its parameter. 
		{
			MyClass res;
			res.regVar = this->regVar + obj.regVar; // sum of the member variables of the current object (this) and the parameter object (obj) assigned to the res object's member variable
			
			return res; //  + operator will return a new MyClass object with a member variable equal to the sum of the two objects' member variables.
		}
		
    protected:

    private:
    	int regVar; // member variable
    	//const  
		int constVar; // member variable
    	
    friend void friendFunc(MyClass &obj); // when passing an object to the function, we need to pass it by reference, using the & operator.	
};


void friendFunc(MyClass &obj) // external friend function - not a memeber function/method of the class
{
	obj.regVar = 50;
	
	cout << endl << " FRIEND regVar = " << obj.regVar << endl;
	
	// obj.myPrint();
}


#endif // MYCLASS_H

/*
Normally, private members of a class cannot be accessed from outside of that class.
However, declaring a non-member function as a friend of a class allows it to access the class' private members. 
This is accomplished by including a declaration of this external function within the class, and preceding it with the keyword friend.
The function friendFunc() is defined as a regular function outside the class. 
It takes an object of type MyClass as its parameter, and is able to access & modify the private data members of that object.
*/
