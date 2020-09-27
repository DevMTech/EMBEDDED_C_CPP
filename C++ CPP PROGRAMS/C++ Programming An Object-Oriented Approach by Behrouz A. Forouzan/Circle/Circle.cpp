/***************************************************************
* Program 7.8 The implementation fle
* This is the implementation fle that defnes the defnition *
* of all member functions. A copy of the interface fle is *
* included at the top to allow compilation of this fle. *
***************************************************************/




#include "Circle.h"

#ifndef NOTEPAD_PLUS_PLUS

/***************************************************************
* The parameter constructor with one argument that initializes *
* a circle with the given value. It uses the assert function to *
* validate that the radius is a positive double value. If not, *
* the program is aborted. *
***************************************************************/
Circle :: Circle (double rds)
: radius (rds)
{
	if (radius < 0.0)
	{	assert (false);
	}
}

/***************************************************************
* The default constructor that initializes a circle set to 0.0. *
* It does not need an assertion. *
***************************************************************/
Circle :: Circle ()
: radius (0.0)
{ }

/***************************************************************
* The copy constructor that copies the radius of another circle *
* to create a new one. The source circle is already validated, *
* which means that we do not need validation. *
***************************************************************/
Circle :: Circle (const Circle& circle)
: radius (circle.radius)
{ }

/***************************************************************
* A destructor that cleans up an object when the application is *
* terminated. *
***************************************************************/
Circle :: ~Circle ()
{ }

/***************************************************************
* The setRadius function is defned to change the circle *
* by decreasing or increasing the size of the radius. It needs *
* validation because the new size of must be a positive value. *
***************************************************************/
void Circle :: setRadius (double value)
{
	radius = value;
	if (radius < 0.0)
	{	assert (false);
	}
}

/***************************************************************
* The getRadius is a function that returns the radius *
* of an object. It needs the const modifer to prevent the *
* accidental change of the host object. *
***************************************************************/
double Circle :: getRadius () const
{	return radius;
}

/***************************************************************
* The getArea accessor function returns the area of the host *
* object. It needs the const modifer to prevent the accidental *
* change of the host object. *
***************************************************************/
double Circle :: getArea () const
{	const double PI = 3.14;
	return (PI * radius * radius);
}

/***************************************************************
* The getPerimeter accessor function returns the perimeter of *
* the host object. It needs the const modifer to prevent the *
* accidental change of the host object. *
***************************************************************/
double Circle :: getPerimeter () const
{	const double PI = 3.14;
	return (2 * PI * radius);
}

#endif
