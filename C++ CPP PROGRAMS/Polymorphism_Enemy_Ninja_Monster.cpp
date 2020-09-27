#include<iostream>
#include<string>
using namespace std;

class Enemy
{	
	public:
		
	Enemy(){};
	~Enemy(){};	
		
	void setAttackPower(int a) // OVERLOADED FUNCTION
	{	
		attackPower = a;
	}
	
	virtual void printAttackPower() // OVER-RIDDEN FUNCTION
	{
		cout << endl << " ENEMY     " << attackPower << endl;
	}
	
	virtual void pureVirtualFunc() = 0; // Pure Virtual Function
	
	protected:
	int attackPower;
	
	
};

class Ninja : public Enemy
{	public:
//	Ninja(){}; 	~Ninja(){};	

	void printAttackPower(string e)
	{
		cout << endl << " " << e << "     " << attackPower << endl;
	}
	
	void pureVirtualFunc()
	{
		cout << "\n NINJA ATTACK\n";
	}


};

class Monster : public Enemy
{	public:
//	Monster(){}; 	~Monster(){};

	void printAttackPower()
	{
		cout << endl << " Monster " << " " << attackPower << endl;
	}
	
	void pureVirtualFunc()
	{
		cout << "\n MONSTER ATTACK\n";
	}
};

int main()
{	
//	Enemy e; // cause an error as it is an Abstract class due to its Pure Virtual Function 
	Ninja n;
	Monster m;
	
//	Enemy *e0 = &e;
	Enemy *e1 = &n;
	Enemy *e2 = &m;
	
//	e.setAttackPower(75);
	e1->setAttackPower(50); // FUNCTION OVERLOADING
	e2->setAttackPower(100);
	
	
//	e0->printAttackPower(); //e.printAttackPower();


	e1->pureVirtualFunc();
	
//	e1->printAttackPower("Ninja"); // 
	n.printAttackPower("Ninja"); 
	
	e2->pureVirtualFunc();
	
	//m.printAttackPower();
	e2->printAttackPower(); // FUNCTION OVERRIDING - Enemy pointer can be used to call printAttackPower() function
	

}

/*
Polymorphism occurs when there is a hierarchy of classes and they are related by inheritance.

C++ polymorphism means that a call to a member function will cause a different implementation to be executed depending on the type of object that invokes the function.
Simply, polymorphism means that a single function can have a number of different implementations; one function, with different implementations.

To be able to call the corresponding attack() function for each of the derived classes using Enemy pointers, we need to declare the base class function as virtual.
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
