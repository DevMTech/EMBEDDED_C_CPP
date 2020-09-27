main()
{
int n=5;
switch (n) 
{
default : printf("default"); n=5;
case 1: printf("1");
//default : printf("default"); n=1;
case 2: printf("2");
case 3: printf("3"); break;
} 
//return 0;

printf("\n\n\n\n");

n=5;
switch (n) 
{
default : printf("default"); n=2;
case 1: printf("1");
//default : printf("default"); n=1;
case 2: printf("2");
case 3: printf("3"); break;
} 
//return 0;

printf("\n\n\n\n");

n=5;
switch (n) 
{
//default : printf("default"); n=2;
case 1: printf("1");
default : printf("default"); n=1;
case 2: printf("2");
case 3: printf("3"); break;
} 
//return 0;

printf("\n\n\n\n");

n=5;
switch (n) 
{
//default : printf("default"); n=5;
case 1: printf("1");
default : printf("default"); n=1;
case 2: printf("2"); n=8;
case 3: printf("3"); break;
case 4: printf("4");
} //return 0;
printf("\n\n n = %d", n);
}
