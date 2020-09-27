/***************************************************************
* The application fle app.cc to use the Time class *
***************************************************************/
#include "time.h"
int main ( )
{
	// Instantiation of a time object
	Time time (4, 5, 27);
	
	// Printing the original time
	cout << "\n\tInitial time: " ;
	time.print();
	
	long seconds = 3600*24; // 143500
	
	// adding 143500 seconds to the original time
	for (int i = 0; i < seconds; i++)
	{	time.tick ();
	}
	// Printing the time after 143500 ticks
	cout << "\n\tTime after " << seconds << " ticks " ;
	time.print();
	
	return 0;
}
