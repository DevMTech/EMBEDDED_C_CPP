
// !!!!!!!!!!!!!!!!!! FAULTY - NEEDS TO BE DEBUGGED !!!!!!!!!!!!!!!!!!!	
#include <stdio.h>
#include <string.h>

	char* strrevv(char *str)//, int limit)
	{
		//char str[] = "abcdef";
		int size=0; // = sizeof(str);
		
		char* s = str;
		 
		while(!*s)
		{
			++s;
			++size;
		}
		
//		int size = ARRSIZE(str); 
		char* rev = NULL;

		for(int i=0; i<size; ++i)
		{	rev[size-1-i] = str[i];
		}
		
		return rev;
	}
	
	
	void main()
	{	
		char* rev = strrevv("abcdef");
		
		printf("%s", *rev);
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
