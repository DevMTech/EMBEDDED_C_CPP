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


void swap (int& frst, int& second) ; // Prototype


int main ( )
{
// Creation of reference relations
int score = 92;
int& rScore = score;
// Using data variable
cout << "Accessing value through data variable." << endl;
cout << "score: " << score << endl;
// Using reference variable
cout << "Accessing value through reference variable." << endl;
cout << "rScore: " << rScore;

// Defnition of two variables
int x = 10;
int y = 20;
// Printing the value of x and y before swapping
cout << "\n\nValues of x and y before swapping." << endl;
cout << "x: " << x << " " << "y: " << y << endl;
// Calling swap function to swap the values of x and y
swap (x , y);
// Printing the value of x and y after swapping
cout << "Values of x and y after swapping." << endl;
cout << "x: " << x << " " << "y: " << y;

return 0;
}

/***************************************************************
* The swap function swaps the values of the parameters and *
* pass-by-reference allows the corresponding arguments in main *
* to be swapped accordingly. *
***************************************************************/
void swap (int& rX, int& rY)
{	int temp = rX;
	rX = rY;
	rY = temp;
}
