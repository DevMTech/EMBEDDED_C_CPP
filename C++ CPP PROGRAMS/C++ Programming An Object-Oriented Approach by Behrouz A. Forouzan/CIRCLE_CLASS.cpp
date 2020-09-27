// Program 7.2 A complete Circle class

#include <iostream>
//#include <string>
//#include <cmath>

using namespace std;

class Circle
{	private:
		double radius;	// non-static instance(object) data member
		static int count; // static data member
	
	public:
		Circle();						// default constructor
		Circle(double radius);			// paramater constructor
		Circle(const Circle &circle);	// copy constructor
		~Circle();						// destructor
		
		void setCount(int countVal);
		static int getCount(); // static member function
		
		void setRadius(double radius);	// mutator
		
		double getRadius () const; // {	return radius;	} // INLINE FUNCTION 
		
		double getArea() const;			// const qualifer makes the host object read-only
		double getPerimeter() const;	// accessor	
};

int Circle::count = 0;

Circle::Circle(): radius(1.0)
{	cout << " DEFAULT CONSTRUCTOR -> CAN'T BE OVERLOADED \t radius = " << this->radius << " cm" << endl;
	++count;	cout << "Object count : " << count << endl;
}

Circle::Circle(double r): radius(r)
{	cout << " PARAMETER CONSTRUCTOR -> CAN BE OVERLOADED \t radius = " << this->radius << " cm" << endl; 
	++count; cout << "Object count : " << count << endl;
}

Circle::Circle(const Circle &c): radius(c.radius)
{	cout << " COPY CONSTRUCTOR -> CAN'T BE OVERLOADED \t radius = " << this->radius << " cm" << endl;
	++count; cout << "Object count : " << count << endl;
}

Circle::~Circle()
{	cout << " DESTRUCTOR " << radius << endl;
	--count; cout << "Object count : " << count << endl;
}

void Circle::setCount(int cnt)
{	this->count = cnt;
}

int Circle::getCount()
{	return Circle::count;
}



void Circle::setRadius(double r) // Without using the this pointer
{	radius = r; // this->radius = r; // (*this).radiuys = r; // (this->radius) is same as (*this).radius
}

//	void Circle :: setRadius (double r) // Using the 'this' pointer
//	{this -> radius = r;
//	}


double Circle::getRadius() const // Written by the user
{	return radius;
}

//	double Circle::getRadius (Circle* this) const // Changed by the compiler
//	{	return (this -> radius);
//	}

double Circle::getArea() const
{	const double PI = 3.14;
	return (PI*radius*radius);
}



int main()
{
	Circle c1(2.7);
	Circle c2;
	Circle c3(c1);
	
	c2.setCount(10); // initialization of static data member
	
//	Circle circle1, *this;		
//	circle1.getRadius(); // Written by the user
//	this = &circle1; // Changed by the system to
//	getRadius (this); // Changed by the system to
	
	cout << "\n Radius " << c2.getRadius() << endl;
	cout << "\n Area " << c2.getArea() << endl << endl;
	
	//c2.setRadius(4);
	cout << "\n Radius " << c2.getRadius() << endl;
	cout << "\n Area " << c2.getArea() << endl << endl;
	
	return 0; 
}









