#include<stdio.h>

void getDate(int *, int *, int *);
//int getDate(int , int , int);

int main()
{	char ch;
	int i, d,m,y;
//	printf("\n enter value of i : ");
//	scanf("%d",&i);
//	printf("\n value of i : %d", i);
	getDate(&d,&m,&y);	
	//printf("\n\n enter a character:"); 
	//scanf("%c", &ch);
	printf(" Date : %d  %d  %d \n",d,m,y);
	
		
	return 0;
}

void getDate(int *d, int *y, int *m)
{ 	int dd, mm, yy;
	printf(" Enter day, month, year : ");
	scanf("%d %d %d", d,m,y);
//	scanf("%d %d %d", dd, mm, yy);
//	scanf("%d",&dd);
//	scanf("%d",&mm);
//	scanf("%d",&yy);
//	*d=dd;
//	*m=mm;
//	*y=yy;
	return;
}
