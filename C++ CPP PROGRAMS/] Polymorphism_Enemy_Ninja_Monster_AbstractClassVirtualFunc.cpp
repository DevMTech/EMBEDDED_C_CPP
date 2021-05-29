#include<iostream>
#include<string>
using namespace std;

class Enemy
{	
	public:
		Enemy(){};
		Enemy(int a):attackPower(a){};
		~Enemy(){};	
			
	//	void setAttackPower(int a):attackPower(a){;} // [Error] only constructors take member initializers
 
		
		void setAttackPower(int a) // OVERLOADED FUNCTION  
		{	attackPower = a;
		}
		
		virtual void printAttackPower() // OVER-RIDDEN FUNCTION
		{	cout << endl << "E:: ENEMY     " << attackPower << endl;
		}
		
		virtual void pureVirtualFunc() = 0; // Pure Virtual Function
	
	protected:
		int attackPower = 10; // [Warning] non-static data member initializers only available with -std=c++11 or -std=gnu++11

};

class Ninja : public Enemy
{	public:
	//	Ninja(){}; 	~Ninja(){};	
		void printAttackPower(string e = "NINJA")
		{	cout << endl << "N:: " << e << "     " << attackPower << endl;
		}
		
		void pureVirtualFunc()
		{	cout << "\nN:: pureVF() - NINJA ATTACK \n";
		}
		
//		void pureVirtualFunc(int a = 5)
//		{	cout << "\n NINJA ATTACK";
//			for(int i=0; i<a; ++i)
//				cout << " !";
//				
//			cout << endl;	
//		}


};

class Monster : public Enemy
{	public:
	//	Monster(){}; 	~Monster(){};
		void printAttackPower(int a = 0, int b = 1) // dummy paramaters, for testing  only
		{	cout << endl << "M:: Monster  " << " " << attackPower << endl;
		}
		
//		void pureVirtualFunc(string s = "UNLEASHED")
//		{	cout << "\n MONSTER ATTACK " << s << "!!!\n";
//		}
		
		void pureVirtualFunc()
		{	cout << "\nM:: pureVF() - MONSTER ATTACK !!!\n";
		}
};

int main()
{	
//	Enemy e; // cause an error as it is an Abstract class due to its Pure Virtual Function 
	Ninja n;
	Monster m;
	
//	Enemy *e0 = &e;
	Enemy *eN = &n;
	Enemy *eM = &m;
	
//	e.setAttackPower(75);
	eN->setAttackPower(50); // FUNCTION OVERLOADING
	eM->setAttackPower(100);
	
	
//	e0->printAttackPower(); //e.printAttackPower();


	eN->pureVirtualFunc(); 	// OUTPUT AS PER IMPLEMENTATION OF PURE VIRTUAL FUCNTION IN DERIVED CLASS - BASE CLASS POINTER USED 
	n.pureVirtualFunc(); 	// OUTPUT AS PER IMPLEMENTATION OF PURE VIRTUAL FUCNTION IN DERIVED CLASS - DERIVED CLASS OBJECT USED
		
	eM->pureVirtualFunc(); 	// OUTPUT AS PER IMPLEMENTATION OF PURE VIRTUAL FUCNTION IN DERIVED CLASS - BASE CLASS POINTER USED
	m.pureVirtualFunc(); 	// OUTPUT AS PER IMPLEMENTATION OF PURE VIRTUAL FUCNTION IN DERIVED CLASS - DERIVED CLASS OBJECT USED
	
	eN->printAttackPower(); // OUTPUT AS PER BASE CLASS
	n.printAttackPower("Ninja"); // OUTPUT AS OR DERIVED CLASS
	n.printAttackPower();  // OUTPUT AS PER DERIVED CLASS

	eM->printAttackPower(); // FUNCTION OVERRIDING - Enemy pointer can be used to call printAttackPower() function
	m.printAttackPower(); // OUTPUT AS PER DERIVED CLASS

}

/*

N:: pureVF() - NINJA ATTACK

N:: pureVF() - NINJA ATTACK

M:: pureVF() - MONSTER ATTACK !!!

M:: pureVF() - MONSTER ATTACK !!!

E:: ENEMY     50

N:: Ninja     50

N:: NINJA     50

E:: ENEMY     100

M:: Monster   100

Polymorphism occurs when there is a hierarchy of classes and they are related by inheritance.

C++ polymorphism means that a call to a member function will cause a different implementation to be executed depending on the type of object that invokes the function.
Simply, polymorphism means that a single function can have a number of different implementations; one function, with different implementations.

To be able to call the corresponding printAttackPower() function for each of the derived classes using Enemy pointers, we need to declare the base class function as virtual.
Defining a virtual function in the base class, with a corresponding version in a derived class, allows polymorphism to use Enemy pointers to call the derived classes' functions.

A class that declares or inherits a virtual function is called a polymorphic class.

You have different classes with a function of the same name, and even the same parameters, but with different implementations.

The virtual member functions (inside the base class) without definition are known as pure virtual functions. 
A pure virtual function has no body and must be implemented in derived classes.
It basically defines, that the derived classes will have that function defined on their own.
The syntax is to replace their definition by =0 (an equal sign and a zero) The = 0 tells the compiler that the function has no body.
Every derived class inheriting from a class with a pure virtual function must override that function.

Objects of the base class with a pure virtual function cannot be created. These classes are called abstract. 
They are classes that can only be used as base classes, and thus are allowed to have pure virtual functions.

*/
