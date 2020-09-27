#include <iostream>
#include <iomanip>

int main()
{	//clrscr();

    std::cout << "Y:" << std::setw(5) << 2020 << std::endl << std::flush;
    std::cout << "M:" << std::setw(5) <<    4 << std::endl;
    std::cout << "D:" << std::setw(5) <<    6 << std::endl;
    
    
    	//int c = a > b ? a : b;
	
	char name[20];
	int age = 0, aToA = 'a'-'A', Capital = 0;
		
	std::cout << "\n\tEnter your name & age: ";
	std::cin >> name >> age;
	if(name[0]>= 'a')
		{	if(name[0]<='z')
			name[0]-= aToA ; //name[0] = name[0] - aToA;
			//exit(0); // used in batch files for debugging purpose, 0 = success
		}
	else Capital = 1 ;	
	
   	std::cout << "\n\n\tHello, world! Hello " << name << " !!" <<std::endl;
   	std::cout << "\n\tYou are " << age << " yrs old.";

    
	
	// break; statement inside a loop takes control to the statement immediately after & outside the loop parenthesis
   	// continue; statement inside a loop redirects execution to the loop condition statement
   	
   	// goto last;
   	
	   /*
	switch(value)
	{case 1: 	break;
		default:	;
	}
	*/	
   	
   	last: return 0;
}
