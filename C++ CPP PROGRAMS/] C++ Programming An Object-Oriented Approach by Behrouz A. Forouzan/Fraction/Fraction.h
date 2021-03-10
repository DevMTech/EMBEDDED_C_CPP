/***************************************************************
* The interface fle fraction.h defning the class Fraction *
***************************************************************/
#include <iostream>
using namespace std;
#ifndef FRACTION_H
#define FRACTION_H
class Fraction
{
	// Data members
	private:
		int numerator;
		int denominator;
		
	// Public member functions
	public:
		// Constructors
		Fraction (int num, int den);
		Fraction ();
		Fraction (const Fraction& fract);
		~Fraction ();
		// Accessors
		int getNumerator () const;
		int getDenominator () const;
		void print () const;
		// Mutators
		void setNumerator (int num);
		void setDenominator (int den);
		int gcd (int n, int m);
	// Helping private member functions
	private:
		void normalize ();
		//int gcd (int n, int m);
};


	/***************************************************************
	* The implementation fle fraction.cpp defning the instance *
	* member functions and helper functions for the Fraction class *
	***************************************************************/
	#include <iostream>
	#include <cmath>
	#include <cassert>
	#include "fraction.h"
	using namespace std;
	/***************************************************************
	* The parameter constructor gets values for the numerator *
	* and denominator, initializes the object, and normalizes the *
	* value of the numerator and the denominator according to the *
	* conditions defned in the class invariant. *
	***************************************************************/
	Fraction :: Fraction (int num, int den = 1)
	: numerator (num), denominator (den)
	{	normalize ();
	}
	/***************************************************************
	* The default constructor creates a fraction as 0/1. It does *
	* not need validation. *
	***************************************************************/
	Fraction :: Fraction ( )
	: numerator (0), denominator (1)
	{
	}
	/***************************************************************
	* The copy constructor creates a new fraction from an exisiting *
	* object. It does not need normalization because the source *
	* object is already normalized. *
	***************************************************************/
	Fraction :: Fraction (const Fraction& fract )
	: numerator (fract.numerator), denominator (fract.denominator)
	{
	}
	/***************************************************************
	* The destructor simply cleans up a fraction for recycling. *
	***************************************************************/
	Fraction :: ~Fraction ()
	{ 
	}
	
	/***************************************************************
	* The getNumer function is an accessor function returning the *
	* numerator of the host object. It needs the const modifer. *
	***************************************************************/
	int Fraction :: getNumerator () const
	{	return numerator;
	}
	/***************************************************************
	* The getDenum function is an accessor function returns the *
	* denominator of the host object. It needs the const modifer. *
	***************************************************************/
	int Fraction :: getDenominator () const
	{	return denominator;
	}
	/***************************************************************
	* The print function is an accessor function with a side effect *
	* that display the fraction object in the form x/y. *
	***************************************************************/
	void Fraction :: print () const
	{	cout << numerator << "/" << denominator << endl;
	}
	/***************************************************************
	* The setNumer is a mutator function that changes the numerator *
	* of an existing object. The object needs normalization. *
	***************************************************************/
	void Fraction :: setNumerator (int num)
	{	numerator = num;
		normalize();
	}
	/***************************************************************
	* The setDenom is a mutator function that changes the denominator *
	* of an existing object. The object needs normalization. *
	***************************************************************/
	void Fraction :: setDenominator (int den)
	{	denominator = den;
		normalize();
	}
	
	/***************************************************************
	* Normalize function takes care of three fraction invariants. *
	***************************************************************/
	void Fraction :: normalize ()
	{	if (denominator == 0) // Handling a denominator of zero
		{	cout << "Invalid denomination. Need to quit." << endl;
			assert (false);
		}		
		
		if (denominator < 0) // Changing the sign of denominator
		{	denominator = - denominator;
			numerator = - numerator;
		}
				
		int divisor = gcd (abs(numerator), abs (denominator)); // Dividing numerator and denominator by gcd
		numerator = numerator / divisor;
		denominator = denominator / divisor;
	}
	
	/***************************************************************
	* The gcd function fnds the greatest common divisor between *
	* the numerator and the denominator. *
	***************************************************************/
	int Fraction :: gcd (int n, int m)
	{	int gcd = 1;
		int smaller = n < m ? n : m;
		
		for (int k = 1; k <= smaller; k++)
		{	if ( n % k == 0 && m % k == 0)
			{	gcd = k;
				//cout << " " << gcd;
			}
		}
		//cout << " " << endl;
		return gcd;
	}

#endif
