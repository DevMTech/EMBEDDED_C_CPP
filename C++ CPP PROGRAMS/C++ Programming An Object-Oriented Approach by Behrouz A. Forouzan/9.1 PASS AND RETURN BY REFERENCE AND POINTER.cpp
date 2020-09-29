// A reference is an alternative name for an object

//	int N = 10;
//	N& rN = N; 
//	int& rN = N; // same  as above

//Case 		Data variable 				Reference variable 			Status 		Remark
// 1 		int name = value; 			int& rName = name; 			OK     		no restriction to changing the value either through the original variable 
// 																				or through the reference variable
// 2 		const int name = value; 	int& rName = name; 			Error		compilation error because we try to bind a nonconstant reference variable to a constant variable. 
// 																				As the original variable is already constant, its value can't be changed through the reference variable.
// 3 		int name = value; 			const int& rName = name; 	OK			the data can be changed through the data variable, but we want to restrict it
//																				from being changed through the reference variable.
// 4 		const int name = value; 	const int& rName = name; 	OK			has little application because the data variable and the reference variables can only
//																				be used to retrieve data, not to change them.

//Recommendation: pass-by-value, pass-by-reference, and pass-by-pointer.
//1. If we need to prevent change, we must use
//	a. pass-by-value for small objects.
//	b. pass-by-constant reference or pass-by-constant pointer for large objects.
//2. If there is a need for change, we must use pass-by-reference or pass-by-pointer.


/***************************************************************
* The program shows how to declare and initialize the original *
* and reference variables and then access the common value *
* through either of them. *
***************************************************************/

/***************************************************************
* The program shows how to use pass-by-reference to allow a *
* called function to swap two values in the calling function. *
***************************************************************/

#include <iostream>
using namespace std;


void swap (int *first, int& second) ; 	// PASS-BY-POINTER & PASS-BY-REFERENCE



int& larger(int *x, int *y); 			// PASS-BY-POINTER & RETURN-BY-REFERENCE

int* smaller (int &x, int &y); 			// PASS-BY-REFERENCE & RETURN-BY-POINTER

int& larger (int &x, int *y); 			// PASS-BY-REFERENCE, PASS-BY-POINTER & RETURN-BY-REFERENCE

int* smaller (int *x, int &y); 			// PASS-BY-POINTER, PASS-BY-REFERENCE & RETURN-BY-POINTER


int main ( )
{	// Creation of reference relations
	int score = 92;
	int& rScore = score;
	
// <--------------------------------------------------------------------------------------->

	int *pScore1 = &score; // POINTER TO AN INT
	*pScore1 = 10;  //	OK
	pScore1++; // OK
	
	const int *pScore2 = &score; // POINTER TO A CONST INT
	//*pScore2 = 10;  //	[Error] assignment of read-only location '*pScore2'
	pScore2++; // OK
	
	int *const pScore3 = &score; // CONST POINTER TO AN INT  
	*pScore3 = 30;  //	OK
	// pScore3++; // [Error] increment of read-only variable 'pScore'
	
	const int *const pScore = &score; // CONST POINTER TO A CONST INT 
	//*pScore = 10;  //	[Error] assignment of read-only location '*(const int*)pScore'
	//pScore++; // [Error] increment of read-only variable 'pScore'	
	
// <--------------------------------------------------------------------------------------->
	
	void *nullPtr = 0; // NOT POINTING TO ANY MEM LOC. NOT EVEN 0x0
	nullPtr = NULL; // NULL == 0
	
	void *voidPtr = 0; // GENEREIC POINTER == VOID POINTER
	int ii = 205;
	voidPtr = &ii;
	//*voidPtr = (int)307;	
	
	double dd = 25.63, jj;
	voidPtr = &dd;
	jj = *(double *)voidPtr;
	
// <--------------------------------------------------------------------------------------->
		
	// Using data variable
	cout << "Accessing value through data variable." << endl;
	cout << "score: " << score << endl;
	// Using reference variable
	cout << "Accessing value through reference variable." << endl;
	cout << "rScore: " << rScore;
	
	// Defnition of two variables
	int x = 10;
	int y = 20;
	int z = 0;
	
// <--------------------------------------------------------------------------------------->
		

	// Printing the value of x and y before swapping
	cout << "\n\nValues of x and y before swapping." << endl;
	cout << "x: " << x << " " << "y: " << y << endl;
	// Calling swap function to swap the values of x and y
	swap (&x , y); // PASS-BY-POINTER & PASS-BY-REFERENCE
	// Printing the value of x and y after swapping
	cout << "Values of x and y after swapping." << endl;
	cout << "x: " << x << " " << "y: " << y;
	
// <--------------------------------------------------------------------------------------->
		
	z = larger(&x, &y); // PASS-BY-POINTER & RETURN-BY-REFERENCE
	cout << "\n\n larger of " << x << " & " << y << " is " << z << "\n";
	
	z = *smaller(x, y); // PASS-BY-REFERENCE & RETURN-BY-POINTER
	cout << "\n\n smaller of " << x << " & " << y << " is " << z << "\n";	
		
	z = larger(x, &y); // PASS-BY-REFERENCE, PASS-BY-POINTER & RETURN-BY-REFERENCE
	cout << "\n\n larger of " << x << " & " << y << " is " << z << "\n";
	
	z = *smaller(&x, y); // PASS-BY-REFERENCE, PASS-BY-POINTER & RETURN-BY-REFERENCE
	cout << "\n\n smaller of " << x << " & " << y << " is " << z << "\n";
	
	return 0;
}

/***************************************************************
* The swap function swaps the values of the parameters and *
* pass-by-reference allows the corresponding arguments in main *
* to be swapped accordingly. *
***************************************************************/
void swap (int *rX, int &rY)
{	int temp = *rX;
	*rX = rY;
	rY = temp;
}

int& larger(int *x, int *y) // PASS-BY-POINTER & RETURN-BY-REFERENCE
{	return (*x > *y ? *x : *y); 	
} 

int* smaller (int &x, int &y) // PASS-BY-REFERENCE & RETURN-BY-POINTER
{	return (x < y ? &x : &y);
}

int& larger(int &x, int *y) // PASS-BY-REFERENCE, PASS-BY-POINTER & RETURN-BY-REFERENCE
{	return (x > *y ? x : *y); 	
} 

int* smaller (int *x, int &y) // PASS-BY-POINTER, PASS-BY-REFERENCE & RETURN-BY-POINTER
{	return (*x < y ? x : &y);
}
