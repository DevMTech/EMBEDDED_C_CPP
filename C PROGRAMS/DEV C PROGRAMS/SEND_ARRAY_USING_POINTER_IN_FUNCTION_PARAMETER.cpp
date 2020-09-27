#include <stdio.h>

// use any of the three function declarations, 
//each works equivalently

//myfuncn(int *, int);
myfuncn(int [], int);
//myfuncn(int var1[], int var2);


int main()
{
     int var_arr[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
     // use any of the two statements, both work same 
     //myfuncn(&var_arr, 7);
     myfuncn(var_arr, 7); // doesn't matter if '&' is not written, result is same

     return 0;
}

// use any of the two function definations, 
// both work equivalently

myfuncn( int *var1, int var2)
//myfuncn( int var1[], int var2)
{ int x;
    for( x=0; x<var2; x++)
    {
        printf("Value of var_arr[%d] is: %d \n\n", x, *var1);
        var1++; /*increment pointer for next element fetch*/
    }
}
