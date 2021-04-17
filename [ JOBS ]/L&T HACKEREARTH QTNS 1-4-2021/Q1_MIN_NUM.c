

// https://www.tutorialspoint.com/c_standard_library/c_function_strcat.htm
// https://fresh2refresh.com/c-programming/c-type-casting/c-itoa-function/
// https://www.tutorialspoint.com/c_standard_library/c_function_sprintf.htm
// https://www.educative.io/edpresso/what-is-the-snprintf-function-in-c
// https://en.cppreference.com/w/c/io/fprintf
// https://www.delftstack.com/howto/c/convert-int-to-char/

//TODO: add necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* fixDateString(char* str){
  int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int d, m, y;		
  char s1 = *(str+2);
  char s2 = *(str+5);	
  if(s1 == '/' && s2 == '/')
  {
	  d = atoi(*str+1)+(10*atoi(*str));
	  m = atoi(*(str+4))+(10*atoi(*(str+3)));
	  y = atoi(*(str+9))+(10*atoi(*(str+8)))+(100*atoi(*(str+7)))+(1000*atoi(*(str+6)));

	if(d>days[m])
	{	d-=days[m];
		m++;
	}

	  if(m>12)
	  {	  m=1; y++;
	  }

	if((y%4==0 && y%100!=0) || (y%400==0))
	{	if(m>2)
		{	d-=1;
		}
	}

	char* ds;
	char* ms;
	char* ys;
	char* r;

	if(d<10)
		r=strcat(r, '0');

	sprintf(ds, '%i', d);
	r=strcat(r, ds);

	r=strcat(r, '/');

	if(m<10)
		r=strcat(r, '0');
	
	sprintf(ms, '%i', m);
	r=strcat(r, ms);	

	r=strcat(r, '/');

	sprintf(ys, '%i', y);
	r=strcat(r, ys);
	
	printf("%s\n", r); 	

	return r;
  }

  return NULL;
}

int main(void){
	int n;
	//printf("Enter number :"); 
	scanf("%d",&n); 
	char dstr[n][12], *fixedstr;
	for(int i = 0; i < n; i++)
		scanf("%s",dstr[i]);
	
	for(int i = 0; i < n; i++){
		fixedstr = fixDateString(dstr[i]);
		printf("%s\n",fixedstr);
	}
	return 0;
}

/*

//TODO: add necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* fixDateString(char* str){
  int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int d, m, y;		
  char s1 = *(str+2);
  char s2 = *(str+5);	
  if(s1 == '/' && s2 == '/')
  {
	  d = atoi(*str+1)+(10*atoi(*str));
	  m = atoi(*(str+4))+(10*atoi(*(str+3)));
	  y = atoi(*(str+9))+(10*atoi(*(str+8)))+(100*atoi(*(str+7)))+(1000*atoi(*(str+6)));

	if(d>days[m])
	{	d-=days[m];
		m++;
	}

	  if(m>12)
	  {	  m=1; y++;
	  }

	if((y%4==0 && y%100!=0) || (y%400==0))
	{	if(m>2)
		{	d-=1;
		}
	}

	char* ds;
	char* ms;
	char* ys;
	char* r;

	if(d<10)
		r=strcat(r, '0');

	r=strcat(r, itoa(d));

	r=strcat(r, '/');

	if(y<10)
		r=strcat(r, '0');

	r=strcat(r, itoa(m));	

	r=strcat(r, '/');

	r=strcat(r, itoa(y)); 	
  }

  return;
}

int main(void){
	int n;
	scanf("%d",&n); 
	char dstr[n][12], *fixedstr;
	for(int i = 0; i < n; i++)
		scanf("%s",dstr[i]);
	
	for(int i = 0; i < n; i++){
		fixedstr = fixDateString(dstr[i]);
		printf("%s\n",fixedstr);
	}
	return 0;
}

*/
