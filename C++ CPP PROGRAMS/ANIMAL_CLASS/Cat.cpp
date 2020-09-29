/*
 * Cat.cpp
 *
 *  Created on: 04-Sep-2020
 *      Author: DebajyotiMaitra
 */




#include <iostream>
using namespace std;

#include "Cat.h"

namespace myCatNSpace
{

	Cat::Cat():color("white"), happy(false)
	{	cout << endl << " Cat.cpp --> Cat() created " << endl;
	//	color = "white";
	//	happy = false;
	}

	Cat::Cat(string color):color(color), happy(0)
	{	cout << endl << " Cat.cpp --> Cat(string) created " << endl;
	}

	Cat::Cat(string color, bool happy)
	{	cout << endl << " Cat.cpp --> Cat(string, bool) created " << endl;
		this->color = color;
		this->happy = happy;

		cout << endl << " Cat.cpp --> Memory Location of this object : " << this << endl;
	}

	Cat::~Cat()
	{	cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << endl << " Cat.cpp --> Cat destroyed " << endl;
	}

	void Cat::whatColor()
	{	cout << endl << " Cat.cpp --> It's a " << color << " cat !" << endl;
	}

	void Cat::mood(bool m)
	{
		happy = m;
	}

	void Cat::speak()
	{	if(happy)
		{	cout << endl << " Cat.cpp --> Meouwwwww !!!" << endl;
		}
		else
		{	cout << endl << " Cat.cpp --> Pssssssst !!!" << endl;
		}
	}


	void Cat::jump()
	{		cout << endl << " Cat.cpp --> Jumping up & down !!!!" << endl;
	}

} // namespace myCatNSpace
