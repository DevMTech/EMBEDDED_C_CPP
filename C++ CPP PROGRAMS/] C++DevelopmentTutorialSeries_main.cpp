/*
            [] C++ Development Tutorial Series - The Complete Coding Guide
            // START -> 8. Classes

            vscode c++ setup
            https://www.youtube.com/results?search_query=vscode+c%2B%2B+setup
            https://github.com/Microsoft/vscode-cpptools/blob/master/Documentation/LanguageServer/MinGW.md


*/

/* << "bitwise left-shift" operator OVERLOADED as "insertion/put to" operator preceded by cout identifier - standard output stream
   >> "extraction/get from" operator (cin identifier - standard input stream)
   iostream.h - cin, cout, <<, >>
   all identifiers (variable names etc.) in the C++ standard library belong to the namespace called 'std'
   namespace::identifier operator "string"
   std::cin>>"Hello world!" OR using namespace std;
   cin/cout - no need to mention format specifier in formet string (unlike in case of printf(), scanf() - %d, %s etc.)
   cascading of insertion(<<)/extraction(>>) operators
*/

/*	
https://docs.oracle.com/cd/E19253-01/817-6223/chp-typeopexpr-2/index.html

Type Name 		32–bit Size 	64–bit Size 

char 			1 byte 			1 byte 
short			2 bytes 		2 bytes 
int				4 bytes 		4 bytes 
long			4 bytes			8 bytes 
long long 		8 bytes 		8 bytes
float			4 bytes 		4 bytes 
double			8 bytes 		8 bytes 
long double		16 bytes		16 bytes 

int8_t					1 byte signed integer 
int16_t					2 byte signed integer 
int32_t					4 byte signed integer 
int64_t					8 byte signed integer 
intptr_t				Signed integer of size equal to a pointer 
uint8_t					1 byte unsigned integer 
uint16_t				2 byte unsigned integer 
uint32_t				4 byte unsigned integer 
uint64_t				8 byte unsigned integer 
uintptr_t				Unsigned integer of size equal to a pointer 

*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define PI 3.14159
#define NEWLINE '\n'

//TYPE ALIASING
typedef float float_t;
float_t float_t_var = 96.678;

// using uflt = float; //  [Error] 'uflt' does not name a type
// uflt float_varu = 48.986;

const double pi = 3.14159;
const char newline = '\n';

//PASS BY REFERENCE
// int passByReference();
// int passByReference(int &a, int &b);
int passByReference(int &a, int &b, int c=5) // function parameter with default value01
{   a+=b;   b=a-b;   a-=b;
//	cout<<"a = "<<a<<endl;
//	cout<<"b = "<<b<<endl;	
    cout<<"c = "<<c<<endl;   
}

//FUNCTION OVERLOADING
float multiply(float a, float b)
{    cout<<"\nFLOAT FUNCTION \t";
    return a*b;
}
//FUNCTION OVERLOADING
int multiply(int a, int b)
{    cout<<"\nINT FUNCTION \t";
    return a*b;
}

//FUNCTION TEMPLATE
template <class Datatype>
Datatype Product(Datatype a, Datatype b)
{    return a*b;
}

template <class T>
T sum(T a, T b)
{	return (a+b);	
}

template <class I, class D>
D larger(I i, D d)
{	return(d > i ? d : i);
}


///////////////////////////////////////////////////////////
template <class T>
class Pair
{	private : T first, second;
	public : Pair(T a, T b) : first(a), second(b){}
			T bigger();
};

template <class T>
T Pair<T> :: bigger()
{	return (first > second ? first : second);
}

/////////////////////////////////////////////////////////////


//NAMESPACE
namespace numbers0
{
    int i = 3;
    float f = 5.647f;

    function()
    {   cout<<"\n NUMBERS0 : i = "<<i<<", f = "<<f<<endl;
        cout<<"\t\t i*(int)f = "<<i*(int)f<<endl; // FLOAT f  CASTED TO INT = INT RESULT
    }
}

namespace numbers1
{
    int i = 3;
    float f = 5.647f;

    function()
    {   cout<<"\n NUMBERS1 : i = "<<i<<", f = "<<f<<endl;
        cout<<"\t\t i*f = "<<i*f<<endl;  //AUTO-CAST OF i FROM INT OT FLOAT = FLOAT RESULT
    } 
}

namespace numbers2
{
    int i = 3;
    float f = 5.647f;

    function()
    {   cout<<"\n NUMBERS2 : i = "<<i<<", f = "<<f<<endl;
        cout<<"\t (float)i*f = "<<(float)i*f<<endl;  // INT i CASTED TO FLOAT = FLOAT RESULT
    }
}

using namespace numbers0;
using namespace numbers1;
using namespace numbers2;

//STRUCT
struct car
{
    int age;
    float speed;

    void PrintFunction()
    {
        cout<<"\nSTRUCT PRINT SPEED : "<<speed<<"\n\n";
    }
};

//UNION
union Number
{
    int i;
    double d;
    bool hello; 
};

//ACCESS SPECIFIERS : PUBLIC PRIVATE PROTECTED 

//CLASS
class Vehicle
{
    public:
    Vehicle();
    Vehicle(int speedTemp, int ageTemp);
        int speed;
        float age;

        void PrintFunction();

    private:
        int acceleration; 
};

void Vehicle::PrintFunction()
{
    acceleration = 9900;
    cout<<"PRINTED"<<endl;

    cout<<"acceleration : "<<acceleration<<endl;
}

//CONSTRUCTOR   - CALLED WHEN CLASS OBJECTS ARE CREATED
    //              - NO RETURN TYPE
    //              - SAME NAME AS CLASS
    //              - CAN BE OVERLOADED TO INITIALIZE MEMBERS OF OBJECT TO DIFFERENT VALUES
Vehicle::Vehicle()	//UNPARAMETERIZED CONSTRUCTOR
{
    speed = 600;
    age = 25.5;
}


Vehicle::Vehicle(int speedTemp, int ageTemp)	//PARAMETERIZED CONSTRUCTOR
{
    speed = speedTemp;
    age = ageTemp;
}

//ENUM
enum Colours {red, green, blue};

int main(int argc, const char * argv[])
{   
    int arr[]={461, 45, 367, 34, 920};
    int arr_2D[][3] = {1, 2, 3, 4, 5, 6};
    
//    cout << endl << " ASCII Table : " << endl << endl;	
//	for(int i = 32; i<128; i++)
//	{	cout << "\t"<< i << "\t->\t"<< (char) i << " \n";	
//	}
	
	cout << "\n\nThe size of an int is:\t\t";
	cout << sizeof(int) << " bytes.\n";
	cout << "The size of a short int is:\t";
	cout << sizeof(short) << " bytes.\n";
	cout << "The size of a long int is:\t";
	cout << sizeof(long) << " bytes.\n";
	cout << "The size of a char is:\t\t";
	cout << sizeof(char) << " bytes.\n";
	cout << "The size of a float is:\t\t";
	cout << sizeof(float) << " bytes.\n";
	cout << "The size of a double is:\t";
	cout << sizeof(double) << " bytes.\n";
	cout << "The size of a bool is:\t\t";
	cout << sizeof(bool) << " bytes.\n\n";
	
	
	
	unsigned short int smallNumber;
	smallNumber = 65535;
	cout << "\nWrapping Around an Unsigned Integer : \n\n";
	cout << "\nThe size of a short int is:\t";
	cout << sizeof(short) << " bytes.\n";
	cout << "unsigned short : small number:" << smallNumber << endl;
	smallNumber++;
	cout << "unsigned short : small number:" << smallNumber << " (65536 gets wrapped to 0) " << endl;
	smallNumber++;
	cout << "unsigned short : small number:" << smallNumber << endl;
	
	short int shortInt;
	shortInt = 32767;
	cout << "short int : small number:" << shortInt << endl;
	shortInt++;
	cout << "short int : small number:" << shortInt << endl;
	shortInt++;
	cout << "short int : small number:" << shortInt << endl;
 

//	char strC[]= "Hello";
//	strupr(strC);	// [Error] 'strupr' was not declared in this scope
//	cout<<strC<<endl;

    //CLASS
    Vehicle bmwC;  //OBJECTS OF THE CLASS VEHICLE

    cout<<"BMW Speed: "<<bmwC.speed<<endl;
    cout<<"BMW Age: "<<bmwC.age<<endl;

    Vehicle toyotaC (750, 22.4);
    cout<<"TOYOTA Speed: "<<toyotaC.speed<<endl;
    cout<<"TOYOTA Age: "<<toyotaC.age<<endl;

    bmwC.speed = 900;

    toyotaC.speed = 890;

    cout<<toyotaC.speed<<" ";

    bmwC.PrintFunction();

    //STRUCT
    car bmwS, toyotaS;
    bmwS.PrintFunction();
    bmwS.speed = 900;
    cout<<"BMW SPEED : "<<bmwS.speed<<endl; 
    bmwS.PrintFunction();

    //UNION
    Number number;
    cout<<"****************\n";
    cout<<"number.i\t"<<number.i<<"\n\n";           //GARBAGE VALUE 
    cout<<"number.d\t"<<number.d<<"\n\n";           //GARBAGE VALUE   
    cout<<"number.hello\t"<<number.hello<<"\n\n";   //GARBAGE VALUE 
    cout<<"****************\n";
    number.d=14.32;
    cout<<"number.i\t"<<number.i<<"\n\n";           //GARBAGE VALUE 
    cout<<"number.d\t"<<number.d<<"\n\n";
    cout<<"number.hello\t"<<number.hello<<"\n\n";   //GARBAGE VALUE 
    cout<<"****************\n";
    number.hello=true;
    cout<<"number.i\t"<<number.i<<"\n\n";           //GARBAGE VALUE 
    cout<<"number.d\t"<<number.d<<"\n\n";           //GARBAGE VALUE 
    cout<<"number.hello\t"<<number.hello<<"\n\n";
    cout<<"****************\n";
    number.i=10;
    cout<<"number.i\t"<<number.i<<"\n\n";
    cout<<"number.d\t"<<number.d<<"\n\n";           //GARBAGE VALUE 
    cout<<"number.hello\t"<<number.hello<<"\n\n";   //GARBAGE VALUE 
    cout<<"****************\n";

    //ENUM
    cout<<"ENUM: Red \t= "<<red<<"\n";
    cout<<"ENUM: Green = "<<green<<"\n";
    cout<<"ENUM: Blue \t= "<<blue<<"\n\n";
//    cout<<"ENUM: Red \t= "<<Colours::red<<"\n";
//    cout<<"ENUM: Green = "<<Colours::green<<"\n";
//    cout<<"ENUM: Blue \t= "<<Colours::blue<<"\n\n";
    
    //TYPE ALIASING
    cout<<"TYPEDEF float_t: "<<float_t_var<<endl;
    // cout<<"USING uflt: "<<float_varu<<"\n\n";

    //REFERENCE VARIABLE
    int int_i = 10;
    int &ref_v = int_i; //REFERENCE VARIABLE - ALIAS FOR AN EXISTING VARIABLE
    cout<<"int_i = "<<int_i<<", ref_v = "<<ref_v<<endl;
    ref_v = 90;
    cout<<"ref_v = "<<ref_v<<", int_i = "<<int_i<<endl;

    //POINTER
    int * ip = new int();
    *ip = 100;
    cout<<"Address of int pointer ip = "<<&ip<<endl;
    cout<<"Address pointed to by ip  = "<<ip<<endl;
    cout<<"Value stored at that addr.= "<<*ip<<endl;

    int u = 200;
    ip = &u;
    cout<<"u = "<<u<<"\n[after ip=&u] *ip = "<<*ip<<endl;
    *ip =500;
    cout<<"[after *ip=500] u = "<<*ip<<endl;

    
    delete ip; //FREE UP MEMORY - DELETE OPERATOR
    
    ip = NULL;
    // cout<<"[after delete ip] *ip = "<<*ip<<endl; //EXECUTING THIS WILL CRASH THE PROGRAM

   

    //NAMESPACE
    numbers0::function();
    numbers0::i=10;
    numbers0::function();

    numbers1::function();
    numbers1::i=10;
    numbers1::function();

    numbers2::function();
    numbers2::f=10.37;
    numbers2::function();
    
    //FUNCTION TEMPLATE
    cout<<"\nUSING FUNCTION TEMPLATE FOR FUNCTION OVERLOADING"<<endl;
    cout<<"a*b = "<<Product(3,9)<<endl;                    // INT
    cout<<"a*b = "<<Product(3.89f,9.99f)<<endl;            // FLOAT
    cout<<"a*b = "<<Product((int)3.89f,(int)9.99f)<<endl;  // INT-CASTED


	Pair < double > obj ( 24.54, 29.63 );
	cout << obj.bigger();

    //FUNCTION OVERLOADING
    cout<<"\nFUNCTION OVERLOADING"<<endl;
    cout<<"a*b = "<<multiply(3,9)<<endl;                    // INT
    cout<<"a*b = "<<multiply(3.89f,9.99f)<<endl;            // FLOAT
    cout<<"a*b = "<<multiply((int)3.89f,(int)9.99f)<<endl;  // INT-CASTED

    
    //PASS BY REFERENCE
    int x=5, y=7;
    cout<<"before pass by ref.: x = "<<x<<", y = "<<y<<endl;
    passByReference(x, y);  // value for 3rd argument not sent, default value will be sent
    cout<<" after pass by ref.: x = "<<x<<", y = "<<y<<endl;
    passByReference(x, y, 10); // value for 3rd argument sent
    cout<<"after pass2 by ref.: x = "<<x<<", y = "<<y<<endl;


    string s(" Deb ");
    // std::cout<< "Hello World!!"<<std::endl;
    cout<<"Hello"<< s <<"!"<<endl;
    cout<<"Length of s: " << s.length() << endl;
    cout<<"Size of s: " << s.size() << endl;

    cout<<"Hello"<< s.c_str() <<"!"<< newline;

//    string hw("Hello World");
//    for(char c : hw)  // RANGE BASED FOR LOOP	//	[Error] range-based 'for' loops are not allowed in C++98 mode
//    {   cout<<c<<endl;
//    }

    cout<<"PI (#def) = "<< PI << NEWLINE;
    cout<<"pi (const) = "<< pi << newline; 
    
    //TYPE CASTING
    cout<<"pi (int casted) = "<< (int) pi <<endl;

    string str("200");
    int str2int;
    stringstream(str) >> str2int;
    cout<<"str = "<<str<<", str2int * 10 = "<<str2int * 10<<endl;

    x=12, y=14;
    int i=x=y;
    cout<<"i = "<<i<<", x = "<<x<<", y = "<<y<<endl;

    i=4, x=5, y=6;

    cout<<x+y<<" "<<x-y<<" "<<x*y<<" "<<x/y<<" "<<x%y<<endl;

    // i=10; 
    // GOTOSTMT: i--;   // FIND ERROR - ALWAYS GOES INTO INFINITE LOOP
    // if(i>1)  cout<<i<<endl; goto GOTOSTMT; 

    // compound assignmnet operator += -= *= /=
    // increment decrement ++ --
    // relational & comparison operator 
    cout<<(x==y)<<" "<<(x!=y)<<" "<<(x<y)<<" "<<(x>y)<<" "<<(x<=y)<<" "<<(x>=y)<<endl;
    // logical operators
    cout<<((x==y) && (x!=y))<<" "<<((x<y) || (x>y))<<endl;
    cout<<(((x==y) && (x!=y)) && ((x<y) || (x>y)))<<endl;
    // ternary
    cout<<"result "<< ((x==y) ? 1 : 0) <<endl;

    //COMMA OPERATOR
    int a, b=7;
    a = (b=32, b+9);
    cout<<"a = "<<a<<", b = "<<b<<endl; 

    float c = sizeof(a);
    cout<<"sizeof(a) = c = "<<c<<" bytes, sizeof(c) = "<<sizeof(c)<<" bytes"<<endl;

    //BITWISE OPERATORS
    //XOR ^ => ODD NUMBER OF 1's = 1
    // 1001 0111
    // 0101 0100
    //-----------
    // 1100 0011 (RESULT OF XOR OPERATION)
    cout<<"5|3 = "<<(5|3)<<", 5&3 = "<<(5&3)<<", 5^3 = "<<(5^3)<<endl;

    //https://www.electronics-tutorials.ws/binary/signed-binary-numbers.html
    //http://sandbox.mc.edu/~bennet/cs110/tc/dtotc.html
    // ~ TWO's COMPLEMENT = 1 + ONE's COMPLEMENT 
    // ~5 = ~0000 0101 = 1111 1010 + 1 = 1111 1011
    // 5>>1 = 0101>>1 = 0010 = 2
    // 5<<1 = 0101<<1 = 1010 = 10
    cout<<"~5 = "<<(~5)<<", ~(-5) = "<<(~(-5))<<", 5>>1 = "<<(5>>1)<<", 5<<1 = "<<(5<<1)<<endl;
    
    string num("12345");
    int nums;
    // stringstream nums(num);
    // for(char ch : num)
    for(int i=0; i<6; i++)
    {   switch(i)
        {   case 0: cout<<"ZERO"<<endl; break;
            case 1: cout<<"ONE"<<endl; break;
            case 2: cout<<"TWO"<<endl; break;
            case 3: cout<<"THREE"<<endl; break;
            case 4: cout<<"FOUR"<<endl; break;
            case 5: cout<<"FIVE"<<endl; break;

            default: cout<<"DEFAULT"<<endl;
        }
        cout<<i<<endl;
    }


    return 0;
}

// START -> 7. advanced datatypes  6. Struct

// int passByReference(int &a, int &b)
// {    a+=b;   b=a-b;   a-=b;
// }

/*
mov rdx, i
mov rdi, i
mov rxi, msg
mov rdx, 14
syscall
mov rax, db
mov rdi, 0
syscall
msg: db "Hello, world!!"
*/
