/* calloc() and malloc() example 
	https://www.tenouk.com/ModuleZa.html
*/

#include <stdlib.h>
#include <stdio.h>
#define N 10

/* a struct */

typedef struct book_type
{   int id;
    char name[20];
    float price;
}book;
 

int main(void)
{   int *aPtr = NULL, *bPtr = NULL, m = 0;
    char *str = NULL;
    
    book *bookPtr = NULL;   

    aPtr = (int *)calloc(N, sizeof(int));  /* create an int array of size 10 */    

    if(aPtr == NULL) /* do some verification */
    {   printf("calloc for integer FAILED!\n");
        exit (0);
    }

    else
        printf("memory allocation for int through calloc() SUCCESSFUL\n");


    str = (char *)calloc(N, sizeof(char)); /* create a char array of size 10 */
    if(str == NULL)
    {   printf("calloc for char FAILED!\n");
        exit (0);
    }
    else
        printf("memory allocation for char through calloc() SUCCESSFUL\n");

    

    

    bookPtr = (book *)malloc(sizeof(book)); /* create a structure of book */
    if(bookPtr == NULL)
    {   printf("malloc for struct FAILED!\n");
        exit (0);
    }
    else
        printf("memory allocation for struct through malloc() SUCCESSFUL\n");

   
    /* clean up the memory allocated */
    free(aPtr);

    free(str);

    free(bookPtr);

   

    /* other way */

    /* get the number of elements from the user and then allocate */

    printf("\nEnter the size of integer array (bytes): ");
    scanf("%d", &m);

    bPtr = (int *)calloc(m, sizeof(int));
    if(bPtr == NULL)
    {   printf("calloc for int FAILED!\n");
        exit (0);
    }
    else
        printf("memory allocation for int through calloc() SUCCESSFUL\n");
        

    free(bPtr);

    return 0;

}
