// Interfacing with C++ programming real-world applications
// Listing 6-13 Replacing WritePort0() of DAC class by SendData().
/*****************************************************
In this program, the Function WritePort0() of the DAC
class is given the new name SendData() which is more
appropriate for the DAC class.
*****************************************************/
//#include <dos>
#include <iostream>
#include <stdio.h>
#include <conio.h>

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
// 	InDataPort1 = 0;
// }

// SHOWING USE OF this POINTER
ParallelPort::ParallelPort(int BaseAddress) // parameterized constructor
{	this->BaseAddress = BaseAddress; // data member = parameter;
	InDataPort1 = 0;
}

void ParallelPort::WritePort0(unsigned char data)
{	outportb(BaseAddress,data);		
}

void ParallelPort::WritePort2(unsigned char data)
{	outportb(BaseAddress+2, data ^ 0x0B);
	// Invert bits 0, 1 and 3 to compensate for
	// internal inversions by printer port hardware.
}

void ParallelPort::ChangeAddress(unsigned int newaddress)
{	BaseAddress = newaddress;
}

unsigned char ParallelPort::ReadPort1()
{	InDataPort1 = inportb(BaseAddress+1);	
	InDataPort1 ^= 0x80; // Invert bit 7 to compensate for internal inversion by printer port hardware.
	InDataPort1 &= 0xF8; // Filter to clear unused data bits D0, D1 and D2 to zero.	
	return InDataPort1;
}


// DAC is derived class of base class ParallelPort
class DAC : public ParallelPort 
{	private:
		unsigned char LastOutput;
		
	public:
		DAC();
		DAC(unsigned int baseaddress);
		unsigned char GetLastOutput();
		void WritePort0(unsigned char data);
		void SendData(unsigned char data);
}; 

DAC::DAC()
{	LastOutput = 0;
}

DAC::DAC(unsigned int baseaddress): ParallelPort(baseaddress)
{	//LastOutput = 0;
	this->LastOutput = 0; // BOTH WORK
}

unsigned char DAC::GetLastOutput()
{	//return LastOutput; 
	return this->LastOutput; // BOTH WORK
}

/*
// USED IF BaseAddress is a protected data member
void DAC::WritePort0(unsigned char data)
{	outportb(BaseAddress,data);	// when BaseAddress is a protected data member
	//ParallelPort::WritePort0(data); // if BaseAddress is a private data member
	LastOutput = data;
}
*/

// USED IF BaseAddress is a private data member
void DAC::SendData(unsigned char data) 
{	ParallelPort::WritePort0(data); // if BaseAddress is a private data member
	// LastOutput = data;
	this->LastOutput = data; // BOTH WORK
}

int main()
{		
	DAC D_to_A, DAC1, DAC2; // ParallelPort Object for DAC 

	//DAC * DACptr = &D_to_A;
	DAC * DACptr = new DAC(0x379); // new operator passes baseaddress 0x379 to DAC constructor 
	if(DACptr == NULL)
	{
		cout << " Memory allocation failed ! ";
		exit(1);
	}


	ParallelPort *PPortPtr;
	// Pointers to Base Class Objects can point to Derived Class Objects
	PPortPtr = &D_to_A; // this usage is associated with virtual functions 
	// Ref. Pg 212 8.5 Virtual Functions – An Introduction for details

	//clrscr(); // clear screen
/*
	// WritePort0() USED IF BaseAddress is a protected data member
	cout << " Measure voltage and press a key" << endl;
	getch();
	D_to_A.WritePort0(0);
	cout << " Measure voltage and press a key" << endl;
	getch();
	DAC1.WritePort0(32);
	cout << " Measure voltage and press a key" << endl;
	getch();
	DAC2.WritePort0(64);
	cout << " Measure voltage and press a key" << endl;
	getch();
	D_to_A.WritePort0(128);
	cout << " Measure voltage and press a key" << endl;
	getch();
	D_to_A.WritePort0(255);
	cout << " Measure voltage and press a key" << endl;
	getch();
*/	
	// getch() allows time to measure the DAC output voltage to verify whether 
	// the correct analog voltage has been generated by the DAC system.

	
	// SendData() USED IF BaseAddress is a private data member
	D_to_A.SendData(0); 
	printf("\nDAC byte:%3d ", D_to_A.GetLastOutput());
	cout << " Measure voltage and press a key" << endl;
	getch(); // absorb the key that was hit

	DACptr.SendData(32);
	printf("\nDAC byte:%3d ", D_to_A.GetLastOutput());
	cout << " Measure voltage and press a key" << endl;
	getch();

	DACptr->SendData(64);
	printf("\nDAC byte:%3d ", D_to_A.GetLastOutput());
	cout << " Measure voltage and press a key" << endl;
	getch();

	PPortPtr.SendData(128);
	printf("\nDAC byte:%3d ", D_to_A.GetLastOutput());
	cout << " Measure voltage and press a key" << endl;
	getch();

	PPortPtr->SendData(255);
	printf("\nDAC byte:%3d ", D_to_A.GetLastOutput());
	cout << " Measure voltage and press a key" << endl;
	getch();

	delete DACptr;
	
	return 0;

}
