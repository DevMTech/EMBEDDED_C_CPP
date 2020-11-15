// Interfacing with C++ programming real-world applications
// Listing 7-12 Dynamic memory allocation and exception handling for the LED walk .
/*****************************************************

*****************************************************/
//#include <dos>
#include <iostream>
#include <stdio.h>
#include <conio.h>

#define MAXINDEX 8

#define SetArray(x) SetPatternAddress(x, sizeof(x)) 

using namespace std;

class ParallelPort
{	private:
		unsigned int BaseAddress;
		unsigned char InDataPort1;
		
	protected:
		//unsigned int BaseAddress;
		
	public:
		ParallelPort();
		ParallelPort(int baseaddress);
		void WritePort0(unsigned char data);
		void WritePort2(unsigned char data);
		void ChangeAddress(unsigned int newaddress);
		unsigned char ReadPort1();
};

ParallelPort::ParallelPort() // default constructor
{	BaseAddress = 0x378;
	InDataPort1 = 0;
}

// ParallelPort::ParallelPort(int baseaddress) // parameterized constructor
// {	BaseAddress = baseaddress;
// 		InDataPort1 = 0;
// }

// SHOWING USE OF this POINTER
ParallelPort::ParallelPort(int BaseAddress) // parameterized constructor
{	this->BaseAddress = BaseAddress; // data member = parameter;
	InDataPort1 = 0;
}

void ParallelPort::WritePort0(unsigned char data)
{	//outportb(BaseAddress, data);		
}

void ParallelPort::WritePort2(unsigned char data)
{	//outportb(BaseAddress+2, data ^ 0x0B);
	// Invert bits 0, 1 and 3 to compensate for
	// internal inversions by printer port hardware.
}

void ParallelPort::ChangeAddress(unsigned int newaddress)
{	BaseAddress = newaddress;
}

unsigned char ParallelPort::ReadPort1()
{	
	//InDataPort1 = inportb(BaseAddress+1);	
	InDataPort1 ^= 0x80; // Invert bit 7 to compensate for internal inversion by printer port hardware.
	InDataPort1 &= 0xF8; // Filter to clear unused data bits D0, D1 and D2 to zero.	
	return InDataPort1;
}


// LED is derived class of base class ParallelPort
class LEDs : public ParallelPort
{
	private:
		unsigned char Pattern[8]; // DEFAULT PATTERN
		unsigned char* PatternPtr; // CUSTOM USER PATTERN
		int PatternIndex;
		int MaxIndex;

	public:
		LEDs();
		LEDs(int baseaddress);
		void SetPatternAddress(unsigned char* pattern, int maxidx);
		void LightLEDs(int option);	
};

LEDs::LEDs()
{
	// Fill in the Pattern array
	for(int i = 0; i < MAXINDEX; i++)
	{	*(Pattern + i) = 1 << i;
		cout << hex << *(Pattern+i) << endl;
	}

	MaxIndex = 0;		
	PatternIndex = 0; // initialise to 0
}

LEDs::LEDs(int baseaddress): ParallelPort(baseaddress)
{
	// Fill in the Pattern array
	for(int i = 0; i < MAXINDEX; i++)
		*(Pattern + i) = 1 << i; // Shift '1' left 'i' places
								 // and fill Pattern array.

	MaxIndex = 0;
	PatternIndex = 0; // initialise to 0
}


void LEDs::SetPatternAddress(unsigned char* pattern, int maxidx)
{
	PatternPtr = pattern; // Ptr PatternPtr assigned address of pattern
	MaxIndex = maxidx;
}


void LEDs::LightLEDs(int option)
{
	switch (option)
	{
		case 1:  // DEFAULT LED PATTERN
				while(!kbhit()) // key press terminates function
				{	WritePort0(*(Pattern + PatternIndex++)); 

					// Reset PatternIndex when it gets to 8
					if(PatternIndex == MAXINDEX)	PatternIndex = 0;

					//delay(500);
				}
				break;

		case 2:	// USER DEFINED LED PATTERN
				if(MaxIndex <= 0)
				{	cout << "No Patterns to display " << endl;
					return;
				}

				while(!kbhit()) // key press terminates function
				{	WritePort0(*(PatternPtr + PatternIndex++));

					// Reset PatternIndex when it gets to MaxIndex.
					if(PatternIndex == MaxIndex) PatternIndex = 0;	

					//delay(500);
				}
		
	}

	getch(); // absorb the key that was hit		

}



int main()
{	int i, n, UserPattern;

	LEDs Leds;

	unsigned char* LightPattern;
	//unsigned char LightPattern[MAXINDEX];
	
	cout << " Pass in the desired size of LightPattern => " << endl;
	cout << " Enter number of pattern (> 0) " << endl;
	cin >> n;

	try
	{
		//if((n < 1) || (n > MAXINDEX)) // Note: || is logical OR
		if(n < 1)	
			throw(n);
		
		LightPattern = new unsigned char[n];

		if(LightPattern == NULL)
			throw("Memory error");
	}

	catch(int n) // catches the throw of integer
	{
		cout << "Illegal number of elements requested" << endl;
		cout << "Array size defaults to " << MAXINDEX << endl;
		n = MAXINDEX;
		LightPattern = new unsigned char[n];
	}

	catch(char* memerror) // // catches the throw of the string
	{	cout << " Error : " << memerror << endl;
		cout << "Memory allocation failed " << endl;
		cout << "Terminating program " << endl;
		exit(1);
	}	

	//cout << "Enter "<< MAXINDEX <<" user patterns in the range 0(0x00)-255(0xFF) " << endl;
	
	//for(i = 0; i < MAXINDEX; i++) // fill MAXINDEX element Array
	for(i = 0; i < n; i++)
	{	cin >> UserPattern;
		*(LightPattern + i) = UserPattern;
	}

	Leds.SetPatternAddress(LightPattern, n); // LightPattern as char pointer
	//Leds.SetPatternAddress(LightPattern, MAXINDEX); // LightPattern as char pointer or []
	//Leds.SetPatternAddress(LightPattern, sizeof(LightPattern)); // LightPattern as char []
	// Leds.SetArray(LightPattern); // LightPattern as char []

	Leds.LightLEDs(2);	// Displays a 'walking' LED.
	getch(); // absorb the key that was hit

	//cout << endl << "Halted !"� << endl;
	cout << "Press a key to continue" << endl;
	getch();

	Leds.LightLEDs(1); 	// 'Walking' restarts with the LED
						// alight in the next position.
	
	return 0;

}
