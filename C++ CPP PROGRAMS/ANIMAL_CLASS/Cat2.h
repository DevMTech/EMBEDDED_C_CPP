/*
 * Cat2.h
 *
 *  Created on: 07-Sep-2020
 *      Author: DebajyotiMaitra
 */

#ifndef CAT2_H_
#define CAT2_H_

#include "Animal.h"
#include <iostream>
using namespace std;

namespace myNamespace
{
	class Cat: public Animal
	{
		public:
			Cat(): color(" Golden ")
			{	cout << endl << " Cat2.h --> Cat() created " << endl << endl;
			}

			Cat(string colors): color(colors)
			{	cout << endl << " Cat2.h --> Cat() created " << endl << endl;
			}

			virtual ~Cat()
			{	cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
				cout << endl << " Cat2.h --> Cat destroyed " << endl;
			}

			void speak()
			{	cout << " Cat2.h speak() --> Ssshhhhhhh!!!!" << endl;
			}

			void jump();

			void getColor()
			{	cout << endl << " Cat2.h getColor() --> It's a " << color << " cat !" << endl;
			}

		private:
				string color;
	};

} /* namespace myNamespace */

#endif /* CAT2_H_ */

