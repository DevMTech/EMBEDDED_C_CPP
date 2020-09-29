// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "utils.h"


using namespace myCatNSpace;
//using namespace myNamespace;


#define arrSize(x) 		sizeof(x)/sizeof(x[0])
#define arrEndPtr(x) 	(x + arrSize(x) - 2)



class Pet
{
	public:
		Pet(): name("Ricky"), number(1) { cout << endl << this->number << " Pet created" << endl;};
		~Pet(){ cout << endl << this->number << " DESTRUCTOR CALLED : Pet destroyed " <<  endl;	}

		Pet(const Pet& petObj): name(petObj.name), number(petObj.number)
									{ 	cout << endl << " Pet created by custom Copy constructor " << endl;
									//	petObj.name = "Kitty"; // CAN'T MODIFY CONST OBJECT'S ATTRIBUTES HERE
									// CAN ONLY CALL CONST MENTHODS FROM HERE SINCE THE REFERENCE OBJECT 'petObj' IS A CONST OBJECT
										petObj.speak();
									};

		void setName(string name) 	{ this->name = name; } // INLINE FUNCTION

		void setNumber(int n) 	{ this->number = n; } // INLINE FUNCTION

		// CONST METHOD(INLINE FUNCTION)
		void speak() const  		{ cout << this->number << " pet's name is : " << this->name << endl << endl;
									  // this->name = "Rocky"; // ERROR: CAN'T CHANGE VARIABLE INSIDE CONST FUNCTION!!!
									}
	private:
		string name;
		int number;
};

Pet* createPets()
{	cout << endl << "RETURNING OBJECT FROM FUNCTION : " << endl;
	Pet *ptrPet = new Pet();
	ptrPet->setName("Dummy");
	ptrPet->setNumber(0);
	return ptrPet;
}


int Animal::objCount = 0; // STATIC VARIABLE OF 'Animal' CLASS, SHARED BY ALL OBJECTS OF THE CLASS

int main()
{
	cout << "!!!Hello World!!!" << endl << endl; // prints !!!Hello World!!!

	cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl << endl;

	cout << " USAGE OF COPY CONSTRUCTOR: COPY DATA ARTTRIBUTES OF ONE OBJECT TO ANOTHER OBJECT  " << endl << endl;
	{
		Pet myPet;
		myPet.setName("Goldy");
		myPet.setNumber(1);
		myPet.speak();

		cout << endl << "---------------------------" << endl << endl;

		Pet Pet2 = myPet; // COPY CONSTRUCTOR CALLED
		//Pet2.speak();

		Pet2.setName("Jimmy");
		Pet2.setNumber(2);
		Pet2.speak();

		cout << endl << "---------------------------" << endl << endl;

		Pet pet3(Pet2); // COPY CONSTRUCTOR CALLED
		pet3.setNumber(3);
		pet3.speak();

		cout << endl << "---------------------------" << endl << endl;

		Pet *petPtr = new Pet(); // ALLOCATE MEMORY
		petPtr->setName("Bobby");
		petPtr->setNumber(4);
		petPtr->speak();
		delete petPtr; // DEALLOCATE/FREE MEMORY, PREVENT MEMORY LEAK

		cout << endl << "---------------------------" << endl << endl;

		Pet* PetPtr = createPets();
		PetPtr->speak();
		PetPtr->setName("Tuffy");
		PetPtr->setNumber(5);
		PetPtr->speak();
		delete PetPtr;

		cout << endl << "---------------------------" << endl << endl;

		//const unsigned int ELEMENTS = 5
		Pet* petPtrArr = new Pet[7]; // PTR TO ARRAY OF 7 OBJECTS

		petPtrArr[3].setName("Simmy");
		petPtrArr[3].speak();

		petPtrArr[1].speak();

		delete [] petPtrArr;

		cout << endl << "---------------------------" << endl << endl;

		Pet* nullPtr = NULL; // NULL POINTER
		// ERROR !!!  // delete nullPtr; // ERROR !!! CANNOT DE-ALLOCATE/DELETE A NULL POINTER

		cout << " Pet* nullPtr = NULL; // NULL POINTER" << endl;
		cout << " // ERROR !!!  // delete nullPtr; // ERROR !!! CANNOT DE-ALLOCATE/DELETE A NULL POINTER " << endl;

		cout << endl << "---------------------------" << endl << endl;

	}

	cout << endl << "---------------------------" << endl << endl;

	int* pInt = new int[10];
	*pInt = 205;
	cout << " *pInt = " << *pInt << " \t pInt = " << pInt << endl;
	delete [] pInt;

	cout << endl << "---------------------------" << endl << endl;

	char* charPtr = new char[100]; // ALLOCATE 100 BYTES, SINCE CHAR IS 1 BYTE EACH
	cout << "SIZEOF CHAR_PTR = " << sizeof(charPtr) << " bytes" << endl;
	delete [] charPtr;

	char ch = 'a';
	ch++;
	string str_name(5, ch);
	cout << " str_name = " << str_name << " \t SIZEOF name = " << sizeof(str_name) << " bytes" << endl;

	cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl << endl;

	cout << " POINTERS: CONST PTR, PTR TO CONST, FUCNTION PTR ... " << endl << endl;

	int value1 = 180, value2 = 360;
	const int constValue = 200;

	int* const constPtrToInt = &value1; // CONST PTR TO INT
	cout << " value1 : CONTENTS: " << value1 << " \t ADDRESS: " << &value1 << endl;
	cout << " *constPtrToInt = " << *constPtrToInt << " \t\t constPtrToInt = " << constPtrToInt << endl;
	*constPtrToInt = 90;
	cout << " value1 : " << value1 << endl;
	// constPtrToInt = &(value2); // ERROR !!! error: assignment of read-only variable 'ptrToConstInt'
	cout << "// ERROR !!!  constPtrToInt = &(value2); // error: assignment of read-only variable \'ptrToConstInt\'" << endl << endl;

	cout << endl << "---------------------------" << endl << endl;

	const int* ptrToConstInt = &constValue;
	cout << " *ptrToConstInt = " << *ptrToConstInt << " \t\t ptrToConstInt = " << ptrToConstInt << endl;
	//*ptrToConstInt = 45;  error: assignment of read-only location '* constPtr'
	cout << "// ERROR !!! *ptrToConstInt = 45; // error: assignment of read-only location \'* constPtr\'" << endl;
	ptrToConstInt = &value1;
	cout << " *ptrToConstInt = " << *ptrToConstInt << " \t\t ptrToConstInt = " << ptrToConstInt << endl;


	const int* const constPtrToConstInt = &constValue; // const ptr to a const int
	//constPtrToConst = &value;

	// RIGHT-TO-LEFT RULE = START WITH THE IDENTIFIER(VARIABLE NAME) & GO CLOCK-WISE
	void (*funcPtr[3])(); // funcPtr is an array of 3 pointers to functions that return void
	// static void (*funcPtr[])() = {ReadTemp, TurnUpTemp, TurnDownTemp};


//	bool flag = true;
//	char ch;
//	gets(&ch);
//	cout << " char " << ch << " = " << (int) ch << flush << endl << " flag " << flag << endl;


//	string name;
//	cout << " Name please : " << flush;
//	cin >> name;
//	cout << " Hi " << name << "!" << endl;

	cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl << endl;

	cout << "Size of char 		: " << sizeof(char) << " byte" << endl;
	cout << "Size of wchar_t 	: " << sizeof(wchar_t) << " bytes" << endl;
	cout << "Size of short	 	: " << sizeof(short int) << " bytes" << endl;
	cout << "Size of int 		: " << sizeof(int) << " bytes" << endl;
	cout << "Size of long	 	: " << sizeof(long int) << " bytes" << endl;
	//cout << "Size of signed long int : " << sizeof(signed long int) << " bytes" << endl;
	cout << "Size of unsigned long	: " << sizeof(unsigned long int) << " bytes"  << endl;
	cout << "Size of float 		: " << sizeof(float) << " bytes" << endl;
	cout << "Size of double		: " << sizeof(double) << " bytes" << endl;

	cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl << endl;

	float ff = 1.1;

	cout << "\n 1.1 stored in memory as : " << ff << endl;
	//cout << "\n 1.1 stored in memory as : " <<  fixed << setprecision(10) << ff << endl;

	if(ff < 1.2) cout <<"\n "<< ff << " is less than " << 1.2 << endl;

//	cout << "\n Enter a floating point number : " << flush;
//	cin >> ff;
//	cout << "\n number stored in memory as : " << ff << endl;
	//cout << "\n number stored in memory as : " <<  fixed << setprecision(10) << ff << endl;

	cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl << endl;

	float arrf [] = {10.25, 54.258, 845.02, 87.36};

	float* ptrArrFlt = arrf;

	for(unsigned int i=0; i < arrSize(arrf); i++)
	{	//cout << "\n " << arrf[i];
		cout << "\n " << ptrArrFlt[i];
	}

	cout << endl << "---------------------------" << endl;

	for(unsigned int i=0; i < arrSize(arrf); i++, ptrArrFlt++)
	{	//cout << "\n " << arrf[i];
		cout << "\n memory location : " << ptrArrFlt << " content : " << *(ptrArrFlt);
	}
	//cout << endl << endl;

	cout << endl << "---------------------------" << endl << endl;

	float* pStart = arrf;
	float* pEnd = &arrf[3];
	while(true)
	{	cout << " \t" << *pStart << endl;
		if(pStart == pEnd)
		{	break;
		}
		pStart++;
	}

	cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl << endl;

	string name = "Bob";
	int age = 20;

	stringstream ss;

	ss << "Name : ";
	ss << name;
	ss << ", Age : ";
	ss << age;

	string info = ss.str();

	cout << endl << "info :- " << info << endl;


	string text1 = "do", text2 = "cats", text3 = "a";
	cout << "\n text3 = " << text3 << "\n sizeof(text3) = " << sizeof(text3) << " bytes" << endl;
	text3 = text1;
	cout << "\n text3 = " << text3 << "\n sizeof(text3) = " << sizeof(text3) << " bytes" << endl;
	text3 = text2;
	cout << "\n text3 = " << text3 << "\n sizeof(text3) = " << sizeof(text3) << " bytes" << endl;
	text1 = "dogs, elephants, dinosaurs, hippopotamuses, giraffes, Hippopotomonstroses-quippedaliophobias";
	cout << "\n text1 = " << text1 << "\n sizeof(text1) = " << sizeof(text1) << " bytes" << endl;
	text3 = text2 + " & " + text1;
	cout << "\n text3 = " << text3 << "\n sizeof(text3) = " << sizeof(text3) << " bytes" << endl;
	cout << "\n It's raining " << text3 << "!" << endl << endl;


	cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl << endl;




	{ // char array manipulation using pointer
		char ch[] = "hE1L0"; // {'h', 'e', 'l', 'l', '0'};
		unsigned int i = 0;
		while(i < sizeof(ch)) // while(ch[i])
		{
			cout << " index : " << i << "\t ASCII char : " << ch[i] << "\t\t ASCII value (int) : " << int(ch[i]);
			if(!ch[i])
				cout << " (NULL) ";

			cout << endl;
			i++;
		}

		cout << endl <<  ch << " has a size of " << sizeof(ch) << " bytes " << endl;
	}

	cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl << endl;

	{	cout << " REVERSING CHAR ARRAY USING POINTERS" << endl << endl;

		char name[] = "Netaji Subhash Chandra Bose";

		char* pStart = name;
		char* pEnd = arrEndPtr(name); // name + arrSize(name) - 2;

		cout << " name \t\t: ";
		while(*pStart)
		{	cout << *pStart;
			pStart++;
		}

		pStart = name;

		while(pStart < pEnd)
		{
			char temp = *pStart;
			*pStart = *pEnd;
			*pEnd = temp;
			pStart++;
			pEnd--;
		}

		cout << endl << " Reversed name \t: " << name << endl;

	}

	cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl << endl;

	const int ROW = 3;

	string arrM[][ROW] = {
			{"ted", "rik", "sam"},
			{"alan", "jane", "alex"}
	};

	string* ptrStart = arrM[0]; //&arrM[0][0];
	string* ptrEnd = &arrM[1][2]; // last element

	while(ptrStart <= ptrEnd)
	{	cout << ptrStart << "  " << *ptrStart << " \t " << sizeof(arrM[0][0]) << " bytes" << endl;
		ptrStart++;
	}

	cout << endl << "---------------------------" << endl << endl;

	ptrStart = arrM[0];
	long elements = long(ptrEnd - ptrStart);
	cout << "elements : " << elements << endl;

	cout << endl << "---------------------------" << endl << endl;

	for(unsigned int i=0; i < arrSize(arrM); i++)
	{
		for(unsigned int j=0; j < arrSize(arrM[0]); j++)
		{
			cout << " \t" << arrM[i][j] ;
		}
		cout << endl;
	}

	cout << endl << "---------------------------" << endl << endl;

	cout << "\n sizeof(arrM[1][1]) " << sizeof(arrM[1][1]) << " bytes" << endl;
	cout << "\n sizeof(arrM) " << sizeof(arrM) << " bytes" << endl;

	cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl << endl;

	cout << " USAGE OF REFERENCE VARIABLES " << endl; // PASS BY REFERENCE:
	cout << " A REFERENCE VARIABLE IS JUST ANOTHER NAME FOR \n "
		 << " THE SAME MEMORY LOCATION ALLOCATED TO THE ORIGINAL VARIABLE" << endl << endl;

	int a = 5, b = 10;

	int &c = a; // REFERENCE VARIABLE : c is an ALIAS of a
	int& d = b; // REFERENCE VARIABLE : d is an ALIAS of b


	cout << " address of a : " << &a << " \t address of c : " << &c << endl;
	cout << " a = " << a << "\t\t\t\t c = " << c << endl << endl;

	cout << " address of b : " << &b << " \t address of d : " << &d << endl;
	cout << " b = " << b << "\t\t\t\t d = " << d << endl << endl;

	c = 20;
	d = 30;
	cout << " c = " << c << ", d = " << d << endl;
	cout << " a = " << a << ", b = " << b << endl;


	cout << endl << "---------------------------" << endl << endl;

	cout << "PASS BY REFERENCE: SWAPPING BY USING REFERENCE VARIABLES PASSED TO CALLED FUNCTION (WITHOUT USING 3RD VARIABLE) " << endl;

	cout << "\n before swapping : a = " << a << ", b = " << b << endl;
	swapByReference(a, b);
	cout << "\n after swapping  : a = " << a << ", b = " << b << endl;

	cout << endl << "---------------------------" << endl << endl;

	cout << " SWAPPING BY USING POINTERS PASSED TO CALLED FUNCTION (WITHOUT USING 3RD VARIABLE) " << endl; //

	cout << "\n before swapping : a = " << a << ", b = " << b << endl;
	swapByPtr(&a, &b);
	cout << "\n after swapping  : a = " << a << ", b = " << b << endl;


	cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl << endl;

	{	cout << " CLASSES & INHERITANCE ... CTORS ARE NOT INHERITED " << endl << endl;
		cout << " A CONSTRUCTOR CAN ONLY CALL ITS IMMEDIATE SUPER CLASS CTOR" << endl;
		cout << " IT CANNOT DIRECTLY CALL CONSTRUCTOR OF INDIRECT SUPER CLASS" << endl;
		cout << " SUB CLASS 'Pugs' CTOR CAN INDIRECTLY INITIALIZE PRIVATE MEMBER 'age' " << endl
			 << " OF INDIRECT SUPER CLASS 'Animal' ONLY VIA ITS OWN SUPER CLASS 'Dogs' CTOR " << endl;

		Animal myAnimal;
		myAnimal.speak();
		myAnimal.printInfo();

		cout << endl << "---------------------------" << endl << endl;

		Dogs myDog;
		myDog.speak();
		myDog.trick1();
		myDog.printInfo();

		Dogs myDog2(3);
		myDog2.printInfo();

		cout << endl << "---------------------------" << endl << endl;

		Pugs myPug;
		myPug.speak();
		myPug.trick1();
		myPug.trick2();
		myPug.printInfo();

		cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl << endl;

		cout << " USING NAMESPACE: 'myCatNSpace', CREATING OBJECT OF 'Cat' CLASS (Cat.h, Cat.cpp)" << endl << endl;
		Cat jerry;

		cout << endl << " Memory Location of \'jerry\' object : " << &jerry << endl;

		jerry.speak();
		jerry.whatColor();
		jerry.jump();
		jerry.mood(true);
		jerry.speak();

		cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

		Cat tom("brown", true);
		cout << endl << " Memory Location of \'tom\' object : " << &tom << endl;

		tom.speak();
		tom.whatColor();

		cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

		Cat bella("blue");
		cout << endl << " Memory Location of \'bella\' object : " << &bella << endl;

		bella.speak();
		bella.whatColor();


		cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl << endl;

		cout << " FROM A DIFFERENT NAMESPACE: 'myNamespace', CREATING OBJECT OF THE OTHER 'Cat' CLASS (Cat2.h, Cat2.cpp) USING :: OPERATOR" << endl << endl;

		myNamespace::Cat cat1_myNamespace;
		cat1_myNamespace.speak();
		cat1_myNamespace.getColor();


		myNamespace::Cat cat2_myNamespace(" Wheatish ");
		cat2_myNamespace.speak();
		cat2_myNamespace.getColor();

	}



	cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;


	cout << " Animal::MAX = " << Animal::MAX << endl;

	Animal::showInfo();

	Animal test1;
	cout << " Object ID: " << test1.getId() << endl;

	Animal::showInfo();

	Animal test2;
	cout << " Object ID: " << test2.getId() << endl;;

	Animal::showInfo();


	cout << endl << " Exiting program ... " << endl;

	return 0; // ALL OK
}


void swapByPtr(int *p, int *q)
{	//int temp = *p; 	*p = *q; 	*q = temp;
	*p = *p + *q;
	*q = *p - *q;
	*p = *p - *q;
}

void swapByReference(int &a, int &b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}
