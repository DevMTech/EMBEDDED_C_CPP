	
	G:\[ 21.7GB DESD BKS ] B\[] EMB C & LINUX\[[REAL TIME EMBEDDED C, C++]]\[ ] Interfacing with C++ programming real-world applications
	
	EDITING
	PRE-PROCESSING
	COMPILING
	LINKING
	
	Preprocessor attends to all lines starting with '#' symbol (compiler directives).

The compiler in-turn processes the file produced by the preprocessor and produces
a file known as an object file. The object file contains what is known as object
code, which the Central Processing Unit (CPU) of your computer understands, also
known as machine code.

At this incomplete stage, the object code is said to contain undefined references.
The undefined references refer to pieces of object code that need to be retrieved
from elsewhere to complete the entire program. 

Note that finding the missing bits is not part of
the compiler’s duties – the compiler can be viewed in basic terms as a translator
that checks grammatical content!

The program that bridges all the gaps and completes assembly of the program is
known as the linker. It will search all the object files and the libraries to find the
missing sets of instructions. Sometimes the linker must be told to search certain
libraries and object files. These are either third party libraries you may have
purchased or the libraries and object files you developed.

Linking forms a gaps-free executable code.

At the end of the linking process, we have a
file the PC can execute, known as an executable file.

Most linkers append a loader to the start of the executable file. Therefore, when we
try to run the program, first the loader will run, loading the program into memory
and then actual program execution will begin.

It is very difficult to determine exactly which parts of a header file are
necessary for a particular program. Therefore, compilers run through the entire
header file. The size of the header files will not have any affect on the size of the
executable files, although the time to prepare the program will increase slightly.
	
A function can
produce a result through the return value, which is just one integer. It cannot
produce a result that has more than one integer.	

The main() function and all the other functions are stored in the so-called code
area of program memory, and are generally not expected to change during the life
of the program. The data is stored in the data area where its contents are expected
to change. Apart from the data in fixed data areas, there may be other data that is
created in a temporary area known as the stack, and also in a semi-permanent area
known as the heap (or free store).

the voltage noise margin when a data signal is sent from one
logic circuit to another of the same family is the difference between the 
sends logic-LOW and the receivers valid logic-LOW

For a CMOS circuit outputs a logic-LOW to another CMOS circuit, 
the sending device will output a signal between 0V and
0.2V during normal operation and the receiving device will accept a signal level
between 0V and 1.5V as a valid logic-LOW. If we use an output signal of 0.2V, the
worst case for normal operation, then we can have voltage noise of up to 1.3V
(1.5V – 0.2V) on this logic signal, and the receiving circuit will still recognise a
valid logic-LOW. Here we have a noise margin of 1.3V.

 CMOS circuits typically have better noise margin characteristics than
TTL circuits. Other differences between TTL and CMOS circuits include their
power consumption, their input current requirements, and their output current drive
capacity and speed when switching states.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*****************************************************
This program prints a number you would enter in
decimal format in hexadecimal format.
*****************************************************/
#include <iostream.h>

void main()
{
	int Number;
	cout << "Enter an integer number -> ";
	cin >> Number;
	cout << "The number is:" << endl;
	cout << dec << Number << " in decimal" << endl;
	cout << hex << Number << " in hexadecimal" << endl; // hex - format specifier
}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*****************************************************
WRITING TO A PORT (output operation)
This program outputs a certain bit pattern to the port at
BASE address to light the respective LEDs on the interface
board.
*****************************************************/
#include <dos.h> // This file contains the prototype of the outportb() function.
#define BASE 0x378
void main()
{	// outportb(BASE, 0xFF);
	outportb(BASE, 255); //  a port address and the data to be written to that address
	// in binary, 255 = 1111 1111
	// The number 255 can be changed to any value between 0
	// and 255, causing the eight output signals to
	// correspond to the binary value represented by the
	// number. For example 65 = 0100 0001.
}


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


Listing 3-2 Reading the port at address BASE+1.
/*****************************************************
READING THE PORT AT ADDRESS BASE+1
This program will read the port at address BASE+1 and
print the number read on the screen. The number is
formed by combining the five signal lines read in
through the port. Bits 0, 1 and 2 have no valid data as
they are not dedicated to BASE+1 internally in the PC.
Bits 3, 4, 5 and 6 will be read as normal. Bit 7 is
permanently inverted by the parallel port hardware.
*****************************************************/
#include <dos.h>
#include <conio.h>
#include <stdio.h>

#define BASE 0x378

void main()
{
	unsigned char InputData; // Declare data type for various InputData.
	InputData = inportb(BASE+1); // Read port at BASE+1.
	printf("%2X\n",InputData); // Print result to screen as a hexadecimal number.
	// format specifier denoting that a hexadecimal format of 
	// field width 2 to be used to denote a byte of data (0xAB).
	getch(); // Wait for key press.
}

C 			Examples of frequently used format specifiers
%10.3f 		Floating point format with a field width of 10 and 3 decimal places.
%5d 		Integer format with a field width of 5.
%c 			Character format.
%s 			String format (used for a sequence of characters such as a sentence).
%X or %x 	Hexadecimal format. 
			X will print upper case hexadecimal letters and 
			x will print lower case hexadecimal letters.
			

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

			
Listing 3-3 Writing to the port at BASE+2 with compensation for internal inversions.
/*****************************************************
WRITING TO PORT @ BASE+2, INTERNAL INVERSIONS COMPENSATED
This program outputs 4 bits of data to the port at address
BASE+2, compensating for the inverted bits 0, 1 and 3.
You can change the value of the actual bit pattern you
want to see output to the interface board.
*****************************************************/
#include <dos.h>

#define BASE 				0x378
#define DATA 				0x0F
#define XOR_MASK 			(1<<3)|(1<<1)|(1<<0)
#define BIT_INVERT_MASK 	XOR_MASK


void main()
{
	// BASE+2 bits 0,1 and 3 are internally inverted by
	// the parallel port hardware before being output. This
	// can be compensated in software by carrying out an
	// exclusive OR operation with the output data and 0x0B
	// (0000 1011). Bits 4-7 do not matter as they are not
	// connected.
	
	// outportb(BASE+2, BIT_INVERT_MASK ^ DATA);
	outportb(BASE+2, 0x0B ^ 0x0F);
	
	// NOTE: In binary 0x0F = 0000 1111
	// The number being output (0x0F) can be changed to any
	// value between 0x00 and 0x0F. The four output signals
	// will correspond to the binary bit pattern represented by
	// the number.			
	// Examples:
	// Bit No: 7 6 5 4 3 2 1 0
	// 0x0F 0 0 0 0 1 1 1 1
	// 0x05 0 0 0 0 0 1 0 1
}


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


Listing 3-4 Reading the port BASE+1 with internal inversions compensated.
/*****************************************************
READING THE PORT @ BASE+1, INTERNAL INVERSIONS COMPENSATED
This program reads the port at address BASE+1 (0x379). It
compensates for the hardware inversion of bit 7 after
reading the data. The net result is as if the hardware
inversions had not taken place.
*****************************************************/
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#define BASE 0x378
void main()
{
	unsigned char InputPort1;
	InputPort1 = inportb(BASE+1);
	InputPort1 ^= 0x80;
	printf("%2X\n",InputPort1);
	getch();
}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// Listing 5-7 Writing to port at address BASE using object-oriented approach.
/*****************************************************
WRITING TO A PORT (object-oriented approach)
The program uses the fundamental ParallelPort object
class to output a byte of data to the interface board.
*****************************************************/



#include <dos>
#include <iostream>
#include <stdio>
#include <conio>

using namespace std;

class ParallelPort
{	private:
		unsigned int BaseAddress;
		unsigned char InDataPort1;
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

ParallelPort::ParallelPort(int baseaddress) // parameterized constructor
{	BaseAddress = baseaddress;
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

void main()
{	unsigned char BASE1Data;
	
	ParallelPort OurPort; // object instantiation
	OurPort.WritePort0(255); // calling a member function
	printf("\n\nData sent to Port at BASE\n");
	getch();
	
	unsigned int NEW_ADDR = 0x3AB;
	OurPort.ChangeAddress(NEW_ADDR); // correct way to manipulate a private data member
	OurPort.WritePort0(0xFE);	
	printf("\n\nData sent to Port at %2X \n", NEW_ADDR);
	getch();
	
	BASE1Data = OurPort.ReadPort1();
	printf("\nData read from Port at BASE+1: %2X\n", BASE1Data);
	getch();
	
	OurPort.WritePort2(0x00);
	printf("\nData sent to Port at BASE+2\n");
	getch();
	
	
	// Listing 6-1 Digital-to-Analog Conversion using the ParallelPort object class.
	/*****************************************************
	This program uses the ParallelPort object developed in the
	previous chapter to write a byte of data to the Digital to
	Analog Convertor (DAC). The DAC generates an analog voltage
	proportional to the value of the data byte it receives.
	*****************************************************/

	ParallelPort D_to_A; // ParallelPort Object for DAC 
	
	cout << "Press a key to continue ... " << endl;
	getch();
	D_to_A.WritePort0(0);
	cout << "Press a key to continue ... " << endl;
	getch();
	D_to_A.WritePort0(32);
	cout << "Press a key to continue ... " << endl;
	getch();
	D_to_A.WritePort0(64);
	cout << "Press a key to continue ... " << endl;
	getch();
	D_to_A.WritePort0(128);
	cout << "Press a key to continue ... " << endl;
	getch();
	D_to_A.WritePort0(255);
	cout << "Press a key to continue ... " << endl;
	getch();
	// getch() allows time to measure the DAC output voltage to verify whether 
	// the correct analog voltage has been generated by the DAC system.

}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

6.5.1 Access specifiers
Consider the line:
class DAC : public ParallelPort

The keyword public in this line is an access specifier. Access specifiers change
the access attributes as follows. The protected variables of the ParallelPort
class can be accessed by the member functions of the DAC class, if and only if, the
DAC class is derived from ParallelPort using a public or protected
base class access specifier. Access specifiers can also be private. Figure 6-16
shows how the access specifiers determine access attributes of inherited members.

Access Specifier - public

When deriving a class using a public base class access specifier, all inherited
public members of the base class will become public members of the derived
class, all inherited protected members of the base class will become
protected members of the derived class. All inherited private members will
remain private to the base class, and so the derived class cannot access them.

Access Specifier - protected

When deriving a class using a protected base class access specifier, all
inherited public and protected members of the base class will become
protected members of the derived class. All inherited private members will
remain private to the base class, and so the derived class cannot access them.

Access Specifier - private

When deriving a class using a private base class access specifier, all inherited
public and protected members of the base class will become private
members of the derived class. All inherited private members will remain
private to the base class, and so the derived class cannot access them.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Listing 6-13 Replacing WritePort0() of DAC class by SendData().
/*****************************************************
In this program, the Function WritePort0() of the DAC
class is given the new name SendData() which is more
appropriate for the DAC class.
*****************************************************/
#include <dos>
#include <iostream>
#include <stdio>
#include <conio>

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

ParallelPort::ParallelPort(int baseaddress) // parameterized constructor
{	BaseAddress = baseaddress;
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
{	LastOutput = 0;
}

unsigned char DAC::GetLastOutput()
{	return LastOutput;
}

/*
void DAC::WritePort0(unsigned char data)
{	outportb(BaseAddress,data);	// when BaseAddress is a protected data member
	//ParallelPort::WritePort0(data); // if BaseAddress is a private data member
	LastOutput = data;
}
*/

void DAC::SendData(unsigned char data)
{	ParallelPort::WritePort0(data); // if BaseAddress is a private data member
	LastOutput = data;
}

void main()
{		
	DAC D_to_A; // ParallelPort Object for DAC 
	
	clrscr(); // clear screen

/*	
	cout << " Measure voltage and press a key" << endl;
	getch();
	D_to_A.WritePort0(0);
	cout << " Measure voltage and press a key" << endl;
	getch();
	D_to_A.WritePort0(32);
	cout << " Measure voltage and press a key" << endl;
	getch();
	D_to_A.WritePort0(64);
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

	
	D_to_A.SendData(0);
	printf("\nDAC byte:%3d ", D_to_A.GetLastOutput());
	cout << " Measure voltage and press a key" << endl;
	getch();
	D_to_A.SendData(32);
	printf("\nDAC byte:%3d ", D_to_A.GetLastOutput());
	cout << " Measure voltage and press a key" << endl;
	getch();
	D_to_A.SendData(64);
	printf("\nDAC byte:%3d ", D_to_A.GetLastOutput());
	cout << " Measure voltage and press a key" << endl;
	getch();
	D_to_A.SendData(128);
	printf("\nDAC byte:%3d ", D_to_A.GetLastOutput());
	cout << " Measure voltage and press a key" << endl;
	getch();
	D_to_A.SendData(255);
	printf("\nDAC byte:%3d ", D_to_A.GetLastOutput());
	cout << " Measure voltage and press a key" << endl;
	getch();

}


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int a;
int *IntPtr;
int *IntPointers[20];
IntPtr = *IntPointers; // contents of 1st element
a = **IntPointers; // Same as a = *IntPtr;
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*(*(a+i) + j) == a[i][j]

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
#include <conio>
#include <stdio>

int Add(int a, int b)
{
	return a+b;
}

int Subtract(int a, int b)
{
	return a-b;
}

int Multiply(int a, int b)
{
	return a*b;
}

int main()
{
	int (*CalcFuncPtr) (int, int);
	int a, b, result;
	char op;

	cout << " Enter two integer values : "<< endl;
	cin >> a >> b;
	cout << " Enter +, -, * to add, subtract, multiply : " << endl;
	op = getch(); // getch() reads the key pressed

	switch(op)
	{
		case '+': CalcFuncPtr = Add; break;
		case '-': CalcFuncPtr = Subtract; break;
		case '*': CalcFuncPtr = Multiply;

	}

	result = CalcFuncPtr(a, b);

	cout << " Result : " << result << endl;

	return 0;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

FUNCTION POINTER VS FUNCTION RETURNING POINTER !!

//A function with the name FuncRetPtr that receives two int type parameters
//and returns a pointer to an int is declared as follows:
int *FuncRetPtr(int, int); // function declaration with return type 'int *'

// re-interpret above line as:
int *   FuncRetPtr(int, int); // OR
(int *) FuncRetPtr(int, int); // THIS

// a pointer to a function taking two int type parameters and 
// returning an int type value:
int (*FunctionPtr)(int, int); 

// FuncRetPtr is a function name and therefore is a constant pointer.
// FunctionPtr is a pointer variable.

// now the following function ptr can be used as 
int * (*FuncPtr) (int, int);  // ptr to 'int * FuncRetPtr(int, int)' function



~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

VOID POINTER

int a; // declaration of an int
float b; // declaration of a float
void *VoidPtr; // declaration of a void pointer
int Add(int,int); // declaration of a function

VoidPtr = &a; 	// int address assigned to void pointer
VoidPtr = &b; 	// float address assigned to void pointer
VoidPtr = Add; 	// function address assigned to void pointer

// The advantage when using pointers to void is that the same pointer can be used to
// point to many different types of entities without needing to create specific pointers
// to specific objects.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int * IntPtr = new int(0); // int initialized to 0

int * IntArrPtr = new int[10];

int (* 2DArrRow[10]) = new int [10][20];
if(2DArrRow == NULL)
	{
		cout << " Memory allocation failed ! ";
		exit(1);
	}

delete IntPtr;

delete IntArrPtr;

delete 2DArrRow;

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

