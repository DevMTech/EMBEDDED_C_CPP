int sum3 ( int a, int b, int c) 
{
 int sum = 0;
 sum = a + b + c;
 return sum;
}

static int ii=10;

int main ( int argc , char ** argv ) 
{
// int x = 1;
// x = sum3 (x, x, x);
// x = sum3 (x, x, x);
 rangeOfInt();
 int a, b, *x, *y, **z;
// a=b=0;	x=y=z=NULL;
 a=1;
 z=&y;
 *z=x;
 b=*y;
 
 int c, *u;
 c=0;
// u=NULL;
 *u=1;
 
 printf("Result");
 int arr[4];
// printf("%d", arr[3]);
// 

	
 return 0;
}

int rangeOfInt()
{
	int i=2^31, j=0;
	while(++i)
	{	j=i;
		printf("\n\ni=%d\n", j);
//		printf(".");
	}
	printf("\n\ni=%d\n", j);
	return 0;
}
