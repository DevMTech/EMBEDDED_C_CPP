/***************************************************************
* A program to create objects and count them. *
***************************************************************/
#include <iostream>
using namespace std;
/***************************************************************
* Defnitions of the class Rectangle *
***************************************************************/
class Rectangle
{
	private:
		double length;
		double height;
		static int count; //Static data member

	public:
		Rectangle (double length, double height);
		Rectangle ();
		~Rectangle ();
		Rectangle (const Rectangle& rect);
		static int getCount (); // Static member function
};
// Initialization of static data member
int Rectangle :: count = 0;
/***************************************************************
* Defnitions of instance member functions *
***************************************************************/
// Defnition of parameter constructor
Rectangle :: Rectangle (double len, double hgt)
: length (len), height (hgt)
{count++;
}
// Defnition of default constructor
Rectangle :: Rectangle ()
: length (0.0), height (0.0)
{	count++;
}
// Defnition of copy constructor
Rectangle :: Rectangle (const Rectangle& rect)
:length (rect.length), height (rect.height)
{	count++;
}
// Defnition of destructor
Rectangle :: ~Rectangle ()
{	count--;
}
/***************************************************************
* Defnitions of the static member function *
***************************************************************/
int Rectangle :: getCount ()
{	return count;
}
/***************************************************************
* Application to create and count Rectangle objects *
***************************************************************/
int main ( )
{	cout << "Count of objects: " << Rectangle :: getCount() << endl;
	{
		Rectangle rect1 (3.2, 1.2);
		Rectangle rect2 (1.5, 2.1);
		Rectangle rect3;
		Rectangle rect4 (rect1);
		Rectangle rect5 (rect2);
		cout << "Count of objects: " << rect5.getCount() << endl;
	}
	cout << "Count of objects: " << Rectangle :: getCount();
	return 0;
}
