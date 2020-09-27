/***************************************************************
* The application fle app.cpp uses the Fraction objects. *
**************************************************************/
#include "Fraction.h"
#include <iostream>
using namespace std;


/***************************************************************
* The program creates two pairs of fractions and then calls a *
* function named larger to fnd the larger in each pair *
***************************************************************/
Fraction& larger (Fraction&, Fraction&); // Prototype

int main ( )
{
	// Instantiation of some objects
	Fraction fract1 ;
	Fraction fract2 (14, -21);
	Fraction fract3 (11, 8);
	Fraction fract4 (fract3);
	
	// Printing the object
	cout << "\nPrinting four fractions after constructed: " << endl;
	cout << "fract1: ";
	fract1. print();
	cout << "fract2: ";
	fract2. print();
	cout << "fract3: ";
	fract3. print();
	cout << "fract4: ";
	fract4. print();
	
	// Using mutators
	cout << "\nChanging the first two fractions and printing them:" << endl;
	fract1.setNumer(4);
	cout << "fract1: ";
	fract1.print();
	
	fract2.setDenom(-5);
	cout << "fract2: ";
	fract2.print();
	
	fract2.setDenom(3);
	cout << "fract3: ";
	fract3. print();
	
	fract4.setNumer(6);
	cout << "fract4: ";
	fract4. print();
	
	// Using accessors
	cout << "\nTesting the changes in two fractions:" << endl;
	cout << "fract1 numerator: " << fract1.getNumer() << endl;
	cout << "fract2 denomenator: " << fract2.getDenom() << endl;
	
	// Creating first pair of fractions and finding the larger
	cout << "\nLarger of the first pair of fraction: " ;
	larger (fract1, fract2).print ();
	
	// Creating second pair of fractions and finding the larger
	cout << "Larger of the second pair of fractions: " ;
	larger (fract3, fract4).print ();
	
	
	
	return 0;
}

/***************************************************************
* The function gets two fractions by reference, compares them *
* and returns the larger. *
***************************************************************/
Fraction& larger (Fraction& fract1, Fraction& fract2)
{	if (fract1.getNumer() * fract2.getDenom() > fract2.getNumer() * fract1.getDenom())
	{	return fract1;
	}
	return fract2;
}
