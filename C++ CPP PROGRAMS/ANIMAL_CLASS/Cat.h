/*
 * Cat.h
 *
 *  Created on: 04-Sep-2020
 *      Author: DebajyotiMaitra
 */

#ifndef CAT_H_
#define CAT_H_

#include "Animal.h"
#include <iostream>
using namespace std;

namespace myCatNSpace
{
	class Cat: public Animal
	{
		public:
			Cat();
			Cat(string color, bool happy);
			Cat(string);
			~Cat();

			void speak();
			void jump();
			void mood(bool);
			void whatColor();

		private:
			bool happy;
			string color;
	};

} // namespace myCatNSpace

#endif /* CAT_H_ */
