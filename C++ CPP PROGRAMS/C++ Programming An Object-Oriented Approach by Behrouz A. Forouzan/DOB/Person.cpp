#include<iostream>
#include "Person.h"

int main()
{
	Birthday bd(15, 8, 2020);
	
	Person p("Dev", bd);
	
	p.printInfo();
	
	return 0;
}
