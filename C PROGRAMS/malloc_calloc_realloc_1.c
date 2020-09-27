/* playing with malloc(), memory on the heap */

#include <stdio.h>
#include <stdlib.h> 

#define MALLOC(blocks, datatype) 			(datatype *)malloc(blocks*sizeof(datatype))
#define CALLOC(blocks, datatype) 			(datatype *)calloc(blocks, sizeof(datatype))
#define REALLOC(ptr, blocks, datatype)  	(datatype *)realloc(ptr, blocks*sizeof(datatype))

#define BLOCKS 10
#define NEWBLOCKS 20

typedef struct book_type
{	int id;
	char *book_name; // 1D char array //char name[20];
	//char *(*author); 
	float price;
}book;

void main()
{
	int x, i, m;
	int *y=NULL;
	int *p=NULL;
	int *buffer=NULL;
	
	printf("\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n"); 
	
	book *bookptr = NULL;
	
	bookptr = MALLOC(1, book);
	
	if(bookptr == NULL)
	{	printf("\n\n MALLOC for bookptr FAILED! \n\n");
	}
	else
	{	printf("\n\n MALLOC for struct book SUCCESSFUL! Address of allocated memory : %u \n\n", bookptr);
	}
	
	bookptr->id = 100;
	
	bookptr->book_name = "C PROGRAMS";
	
	//char **auth = {"A", "B"};
	
	bookptr->author = auth;
	
	//bookptr->*(author[0])="A";
	//bookptr->(*author)[1]="B";
	//printf("\n Enter book name : ");
	//gets(bookptr->name);
	
	bookptr->price = 510.25;
	
	printf("\n\n ID = %d \t NAME = %s \t PRICE = Rs. %f ", bookptr->id, bookptr->book_name, bookptr->price);
	//printf("\n\n ID = %d \t NAME = %s \t AUTHOR = %s \t PRICE = Rs. %f ", bookptr->id, bookptr->book_name, bookptr->author[0], bookptr->price);
			
	printf("\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n"); 
		
	/* do 100 times iteration, 100 blocks */
	//for(x=0; x<100; x++)
	{
		/* For every iteration/block, allocate 16K,
		system will truncate to the nearest value */
		//y = (int *)malloc(16384); /* n*sizeof(int) */
		
	//printf(" sizeof(char) : %u \n\n", sizeof(char));
		
		p=MALLOC(BLOCKS, int);		
		
		if(p == NULL)
		{   puts("No memory allocated!"); /* if no more memory */		   
		    exit(0);  /* exit peacefully */
		}
		else
		{	printf("\n MALLOC for int ptr SUCCESSFUL !! address of allocated memory %u ", p);
		}
		
		printf("\n\n \t MALLOC : CONTENTS OF ALLOCATED MEMORY BLOCKS : \n\n");
		for(i=0; i<BLOCKS; i++)
		{
			printf("\n %d) \t address = %u \t content = %d", i, (p+i), *(p+i));
		}
		
		printf("\n\n Allocating-->block: %d \t address: %u\n", BLOCKS, p);		
		printf("\n ---->Freeing %d memory blocks from : \t address: %u\n\n", BLOCKS, p);
		free((void *)p);
		
		
		
		printf("\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n"); 
		
		printf("\nEnter the size of integer array (bytes): ");
    	scanf("%d", &m);
		
		if(m<1)
		{	m = (int)BLOCKS;
		}

		p=CALLOC(m, int);		
		
		if(p == NULL)
		{   puts("No memory allocated!");  /* if no more memory */		   
		    exit(0);  /* exit peacefully */
		}
		else
		{	printf("\n address of allocated memory %u ", p);
		}
		
		printf("\n\n \t CALLOC : CONTENTS OF ALLOCATED MEMORY BLOCKS : \n\n");
		for(i=0; i<m; i++)
		{
			printf("\n %d) \t address = %u \t content = %d", i, (p+i), *(p+i));
		}
				
		printf("\n\n \t NEW CONTENTS OF ALLOCATED MEMORY BLOCKS : \n\n");
		for(i=0; i<m; i++)
		{	*(p+i) = i*25;
			printf("\n %d) \t address = %u \t content = %d", i, (p+i), *(p+i));
		}
//		printf("\n\n Allocating-->block: %d \t address: %u\n", BLOCKS, p);		
//		printf("\n ---->Freeing %d memory blocks from : \t address: %u\n", BLOCKS, p);
//		free((void *)p);

		
		printf("\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n"); 
		
		
		p=REALLOC(p, NEWBLOCKS, int);		
		
		if(p == NULL)
		{   puts("No memory allocated!");  /* if no more memory */		   
		    exit(0);  /* exit peacefully */
		}
		else
		{	printf("\n address of allocated memory %u ", p);
		}
		
		printf("\n\n \t REALLOC : CONTENTS OF ALLOCATED MEMORY BLOCKS : \n\n");
		for(i=0; i<NEWBLOCKS; i++)
		{
			printf("\n %d) \t address = %u \t content = %d", i, (p+i), *(p+i));
		}
		
		
		printf("\n\n \t NEW CONTENTS OF ALLOCATED MEMORY BLOCKS : \n\n");
		for(i=0; i<NEWBLOCKS; i++)
		{	*(p+i) = i*20;
			printf("\n %d) \t address = %u \t content = %d", i, (p+i), *(p+i));
		}
		
		printf("\n\n Allocating-->block: %d \t address: %u\n", NEWBLOCKS, p);		
		printf("\n ---->Freeing %d memory blocks from : \t address: %u\n", NEWBLOCKS, p);
		free((void *)p);
				
				
		printf("\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n"); 		
		
		
		/* allocate the memory block, print the block and the address */
//		printf("Allocating-->block: %i address: %p\n", x, y);		
//		printf("---->Freeing the memory block: %i address: %p\n", x, y);
//		free((void *)buffer);

	}

/* here, we do not free up the allocation */

}
