#include<stdio.h>

typedef struct student student;
typedef struct student* sptr;


struct student
{
	int roll;
	char name[20];
	int total;
	int age;
	
};

int main()
{
	student stu1={10,"Atul",96,20};

	student stu2={
			.roll = 20,
			.age  = 19
			
			};

	student stu3={
			.name = "Roshni",
			.age  = 19,
			.roll = 30,
			.total= 88
			
			};
	
	sptr stptr=&stu2;	

	printf("\n\nEnter roll number : \t");
	scanf("%d",&stu2.roll);
	printf("\n\nEnter name : \t");
	scanf("%s",stptr->name);
	printf("\n\nEnter total : \t");
	scanf("%d",&stptr->total);
	printf("\n\nEnter age : \t");
	scanf("%d",&stptr->age);
	
	//offset=(unsigned int)&((struct student *)0->roll);
	//printf("\n\n offset of roll = \t %u", offset);
	
	printf("\n\n\n\n Roll \t: %d",stu1.roll);
	printf("\n\n Name \t: %s", stu1.name);
	printf("\n\n Total \t: %d", stu1.total);
	printf("\n\n Age \t: %d\n\n", stu1.age);
	
	printf("\n\n Roll \t: %d",stptr->roll);
	printf("\n\n Name \t: %s", stptr->name);
	printf("\n\n Total \t: %d", stu2.total);
	printf("\n\n Age \t: %d\n\n", stu2.age);
		
	printf("\n\n Roll \t: %d",stu3.roll);
	printf("\n\n Name \t: %s", stu3.name);
	printf("\n\n Total \t: %d", stu3.total);
	printf("\n\n Age \t: %d\n\n", stu3.age);
	
	return 0;
}

