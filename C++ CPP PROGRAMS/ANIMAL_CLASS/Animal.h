/*
 * Animal.h
 *
 *  Created on: 07-Sep-2020
 *      Author: DebajyotiMaitra
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>
using namespace std;

class Animal {
public:

	// Initialisation of const must be done right here!
	static int const MAX = 99;

	Animal(): age(10)
	{	cout << endl << " Animal.h  --> No argument Ctor --> Animal() created" << endl;
		id = ++objCount;
		cout << "\t Animal() Object Count = " << objCount << endl << endl;
	}

	Animal(int yrs): age(yrs)
	{	cout << endl << " Animal.h  --> Parameterized Ctor --> Animal() created" << endl;
		id = ++objCount;
		cout << "\t Animal() Object Count = " << objCount << endl << endl;
	}

	virtual ~Animal()
	{	cout << endl << " Animal.h --> Animal() destroyed " << endl;
		id = --objCount;
		cout << "\t Animal() Object Count = " << objCount << endl << endl;
	}

	void speak(){ cout << " Animal::speak() --> Grrrrrr !!!" << endl << endl; }

	void printInfo(){ cout << endl << " Age : " << age << " years" << endl;  }

	int getId() { return id; }

	static void showInfo()
	{
		cout << "\n Object Count = " << objCount << endl;
		cout << " STATIC VARIABLES & STATIC METHODS OF THE CLASS ARE ASSOCIATED WITH THE CLASS, NOT ITS OBJECTS !!!!" << endl;
		cout << " STATIC VARIABLE CAN BE ACCESS ONLY BY THE STATIC METHODS OF THE CLASS" << endl;


	}

private:
	int age;
	int id;
	static int objCount; // shared with all objects of the class
};

//int Animal::objCount = 0;

class Dogs: public Animal
{	public:
		Dogs(): Animal(15)
		{cout << endl << " Animal.h --> No argument Ctor --> Dogs() created " << endl << endl;
		}

		Dogs(int Age): Animal(Age)
		{cout << endl << " Animal.h --> Parameterized Ctor --> Dogs() created " << endl << endl;
		}

		~Dogs()
		{cout << endl << " Animal.h --> Dogs() destroyed " << endl << endl;
		}
		void speak(){ cout << endl << " Dogs --> BARK !!" << endl;}
		void trick1() { cout << endl << " Dogs can JUMP !!!" << endl; }
};

class Pugs: public Dogs
{	public:
		Pugs(): Dogs(5)
		{cout << endl << " Animal.h --> No argument Ctor --> Pugs() created " << endl << endl;
		}
		~Pugs()
		{cout << endl << " Animal.h --> Pugs() destroyed " << endl << endl;
		}
		void speak(){ cout << endl << " Pugs --> RUFF RUFF !!" << endl;}
		void trick2() { cout << endl << " Pugs can FETCH THE BALL !!!" << endl;}
};




#endif /* ANIMAL_H_ */


//#include "Animal.h"
//Animal::Animal() {
//	// TODO Auto-generated constructor stub
//}
//Animal::~Animal() {
//	// TODO Auto-generated destructor stub
//}
