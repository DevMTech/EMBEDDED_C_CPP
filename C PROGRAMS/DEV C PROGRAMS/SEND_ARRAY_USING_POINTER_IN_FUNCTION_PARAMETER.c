#include <stdio.h>
#include<conio.h>


/*************************************************************************************/

// use any of the four function declarations, 
//each works equivalently

myfuncn(int *, int);
//myfuncn(int [], int);

//myfuncn(int *var1, int var2);
//myfuncn(int var1[], int var2);


/*************************************************************************************/

// use any of the two function definations, 
// both work equivalently

//myfuncn( int *var1, int var2)
myfuncn( int var1[], int var2)
{ 	int x;
    for( x=0; x<var2; x++)
    {
        printf("Value \t of \t var_arr[%02d] \t is: \t %3d \n\n", x, *var1);
        var1++; /*increment pointer for next element fetch*/
    }
}

/*************************************************************************************/

int main()
{
     int var_arr[] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 121, 132, 143, 154, 165, 176, 187, 198};
     
     int size = sizeof(var_arr)/ sizeof(*var_arr); 
	 // total memory allocation to array / size of array data type, i.e. size of each array element
	 
	 printf("size of array = %d \n\n", size);
	 
     // use any of the two statements, both work same 
     //myfuncn(&var_arr, size);
     myfuncn(var_arr, size); // doesn't matter if '&' is not written, result is same
     
     return 0;
}

