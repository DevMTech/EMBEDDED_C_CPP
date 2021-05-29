#include <stdio.h>
#include <string.h>

int main()
{
	char* str = "TEST STRING dummy Words GeeKs for GEEKs Let's Try!";
	char* t = "dum";
	char* p;
	
	int i;
	
	//int& j = i;
	
	p = strstr(str, t);
	
	if(p)
	{	printf(" First occurance of %s in %s is %s", t, str, p);
	}
	else
	{ 	printf(" %s not found in %s ", t, str);
	}
	 
	 return 0;
}
