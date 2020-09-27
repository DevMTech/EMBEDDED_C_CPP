#include<stdio.h>

main()
{	int x=10, y=30;

	const int * pc1 = &x; 		// pointer to constant integer
	int const * pc2 = &x; 		// pointer to constant integer
	
	int * const cp = &x; 		// constant pointer
	
	const int * const cpc = &x; // constant pointer to constant integer


// pointer to constant integer

	*pc1=20; 	//	[Error] assignment of read-only location '*pc1'
	pc1++; 		// Valid as pointer is not constant itself, so the address it points to can be incremented
	(*pc1)++; 	// [Error] increment of read-only location '*pc1'
	pc1=&y;		// Valid as pointer is not constant itself, so the address it points to can be changed
	
	
// pointer to constant integer	
	
	*pc2=20; 	// [Error] assignment of read-only location '*pc2'
	pc2++; 		// Valid as pointer is not constant itself, so the address it points to can be incremented
	(*pc2)++; 	// [Error] increment of read-only location '*pc2'
	pc2=&y;		// Valid as pointer is not constant itself, so the address it points to can be changed
	
// constant pointer	
	
	*cp=20; 	// Valid as pointer is itself constant, i.e. it points to a fixed location, but the value stored in that location can be changed
	cp++; 		// [Error] increment of read-only variable 'cp'
	(*cp)++; 	// Valid as pointer points to a fixed location, but the value stored in that location can be incremented
	cp=&y; 		// [Error] assignment of read-only variable 'cp'
	
	
// constant pointer to constant integer	
	
	*cpc=20; 	// [Error] assignment of read-only location '*cpc'
	cpc++; 		// [Error] increment of read-only variable 'cpc'
	(*cpc)++; 	// [Error] increment of read-only location '*cpc'
	cpc=&y; 	//[Error] assignment of read-only variable 'cpc'

	return 0;
}
