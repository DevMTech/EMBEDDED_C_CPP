/***************************************************************
* The interface fle for time.h class *
***************************************************************/


#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

class Time
{
	private:
	int days;
	int hours;
	int minutes;
	int seconds;
	public:
	Time (int hours, int minutes, int seconds, int days);
	Time ();
	~Time ();
	void print() const;
	void tick();
	private:
	void normalize (); // Helping function
};


/***************************************************************
* The impletation fle time.cpp for functions in Time class *
***************************************************************/

#include "time.h"
/***************************************************************
* The parameter constructor accepts three values corresponding *
* to the data members from the user and initializes and object. *
* It uses the normalize function to ensure that hours, minutes, *
* and seconds are in the predefned ranges. *
***************************************************************/
Time :: Time (int hr, int mi, int se, int day = 0)
: hours (hr), minutes (mi), seconds (se), days (day)
{	normalize ();
}
/***************************************************************
* The default constructor creates a time object. *
***************************************************************/
Time :: Time ( )
: hours (0), minutes (0), seconds (0), days (0)
{ }
/***************************************************************
* The destructor just cleans up the object(s) before recycling. *
***************************************************************/
Time :: ~Time ()
{ }
/***************************************************************
* The print function is an accessor function that has a side *
* effect: it displays the time. *
***************************************************************/
void Time :: print () const
{	cout << "Day: " << days << ", Time(hms):" << hours << ":" << minutes << ":" << seconds << endl;
}
/***************************************************************
* The tick function is a mutator function that increments the *
* number of seconds. *
***************************************************************/

void Time :: tick ()
{	seconds++;
	normalize();
}
/***************************************************************
* The normalize function checks the invariants of the class. *
* It either aborts the creation of the class or normalizes the *
* the hours, minutes, and the seconds. *
***************************************************************/
void Time :: normalize ()
{
	// Handling negative data members
	if ((hours < 0) || (minutes < 0) || (seconds < 0) || (days < 0))
	{	cout << "Data are not valid. Need to quit!" << endl;
		assert (false);
	}
	
	// Handling out of range values
	if (seconds > 59)
	{	int temp = seconds / 60;
		seconds = seconds % 60;
		minutes = minutes + temp;
	}
	
	if (minutes > 59)
	{	int temp = minutes / 60;
		minutes = minutes % 60;
		hours = hours + temp;
	}
	
	if (hours > 23)
	{	int temp = hours / 24;
		hours = hours % 24;
		days += temp;
	}
}

#endif
