#include <iostream>
#include <conio.h>
using namespace std; /*This signals to the compiler that the code is within the std (standard) namespace. In effect,
it tells the compiler that when it sees cout it is to treat it like std::cout.*/
int main()
{
 cout << "Decryptix. Copyright 1999 Liberty ";	
 /*<<, >> -> Operator Overloading--The capability of user-created types to use the operators that built-in types use, such as +, =, and ==*/
 cout << "Associates, Inc. Version 0.2\n " << endl;	/*end line*/
 cout << "There are two ways to play Decryptix: ";
 cout << " either you can guess a pattern I create, ";
 cout << "or I can guess your pattern.\n\n";

 cout << "If you are guessing, I will think of a\n ";
 cout << "pattern of letters (e.g., abcde).\n\n";

 cout << "On each turn, you guess the pattern and\n";
 cout << " I will tell you how many letters you \n";
 cout << "got right, and how many of the correct\n";
 cout << " letters were in the correct position.\n\n";
 cout << "The goal is to decode the puzzle as quickly\n";
 cout << "as possible. You control how many letters \n";
 cout << "can be used and how many positions\n";
 cout << " (e.g., 5 possible letters in 4 positions) \n";
 cout << "as well as whether or not the pattern might\n";
 cout << " contain duplicate letters (e.g., aabcd).\n\n";

 cout << "If I'm guessing, you think of a pattern \n";
 cout << "and score each of my answers.\n\n" << endl;

 const int minLetters = 2;
 const int maxLetters = 10;
 const int minPositions = 3;
 const int maxPositions = 10;

 int howManyLetters = 0, howManyPositions = 0;
 bool duplicatesAllowed = false, valid = false;
 int round = 1;

 
 while ( ! valid )
 {
	 while ( howManyLetters < minLetters || howManyLetters > maxLetters )
	 {
		 cout << "How many letters? (";
		 cout << minLetters << "-" << maxLetters << "): ";
		 cin >> howManyLetters;
		 if ( howManyLetters < minLetters || howManyLetters > maxLetters )
		 { cout << "please enter a number between ";
		   cout << minLetters << " and " << maxLetters << endl;
		 }
	 }

	 while ( howManyPositions < minPositions || howManyPositions > maxPositions )
	 {
		cout << "How many positions? (";
		cout << minPositions << "-" << maxPositions << "): ";
		cin >> howManyPositions;
		if ( howManyPositions < minPositions || howManyPositions > maxPositions )
		{
		 cout << "please enter a number between ";
		 cout << minPositions <<" and " << maxPositions << endl;
		}
	 }
	
	 char choice = ' ';
	 while ( choice != 'y' && choice != 'n' )
	 {
		  cout << "Allow duplicates (y/n)? ";
		  cin >> choice;
	 }
	
	 duplicatesAllowed = choice == 'y' ? true : false;
	
	 if ( ! duplicatesAllowed && howManyPositions > howManyLetters )
	 {
		  cout << "I can't put " << howManyLetters;
		  cout << " letters in " << howManyPositions;
		  cout << " positions without duplicates! Please try again.\n";
		  howManyLetters = 0;
		  howManyPositions = 0;
	 }
	 else
	 	valid = true;
} 
 
 
  cout << endl << " ASCII Table : " << endl << endl;	
	 for(int i = 32; i<128; i++)
		{	cout << "\t"<< i << "\t->\t"<< (char) i << " \n";	
		}
	
 _getch();
 	
 return 0;
}
