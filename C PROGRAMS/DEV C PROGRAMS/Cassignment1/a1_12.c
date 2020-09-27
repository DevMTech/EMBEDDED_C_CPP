#include<stdio.h>

int main()
{	char ch;
	int i;	
	//printf("\n\n enter a character:"); 
	//scanf("%c", &ch);
	for(i=0; i<=255; i++)
	{printf(" ASCII value of %c : %d \n", i, i);
			if(i%10==0) 
				{scanf("%c",&ch);//getch();
				}
	}
	return 0;
}
