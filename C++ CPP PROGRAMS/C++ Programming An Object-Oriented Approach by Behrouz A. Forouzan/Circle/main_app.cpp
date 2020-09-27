/***************************************************************
* Program 7.9 The application fle
* This is the application fle that instantiates objects and *
* lets the object operate on themselves using member functions. *
* To be to compiled, it needs a copy of the interface fle. *
***************************************************************/

#include "Circle.h"

int main ( )
{
	// Instantiation of frst object and applying operations
	Circle circle1 (5.2);
	cout << "Radius: " << circle1.getRadius() << endl;
	cout << "Area: " << circle1.getArea() << endl;
	cout << "Perimeter: " << circle1.getPerimeter() << endl;
	cout << endl;
	

	// Instantiation of second object and applying operations
	Circle circle2 (circle1);  // Pass-by-reference in Copy constructor
	cout << "Radius: " << circle2.getRadius() << endl;
	cout << "Area: " << circle2.getArea() << endl;
	cout << "Perimeter: " << circle2.getPerimeter() << endl;
	cout << endl;
	
	// Instantiation of third object and applying operations
	Circle circle3;
	cout << "Radius: " << circle3.getRadius() << endl;
	cout << "Area: " << circle3.getArea() << endl;
	cout << "Perimeter: " << circle3.getPerimeter() << endl;
	cout << endl;
	
	return 0;
}
