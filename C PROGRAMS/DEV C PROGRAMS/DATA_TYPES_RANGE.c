main()
{	unsigned char uc = 255; 
	char name[20];
	short s = 127;
	unsigned short us = 255;
	long L = 2147483647;
	unsigned long ut, uL = 2147483647;
	//unsigned long ut, uL = 4294967290;
	unsigned ui = 65535; //unsigned = unsigned int
	int i = 32767, num;
	printf("enter a number: ");
	scanf("%d", &num);
	printf("Number = %d", num);
//	printf("ENTER YOUR NAME PLEASE: ");
//	gets("%c",&name);
//	puts(name);
//	printf("NAME: ");
//	for (i=0;i<20;i++)printf("  %c", name[i]);
	
	
	printf(" \n\n\nTHIS CODE SHOWS THE RANGE OF DIFFERENT DATA TYPES IN C\n\n\n");
    printf(" %d %f %c", 23451, 124.658, 'd');
    printf(" \n \n unsigned int %d (U) \t long int %d (L)", 45678U, -45689L); 
	// to change an int value to long int or unsigned int use L,U or for both UL
    printf(" \n \n unsigned long int %d (UL)", 456789UL);
    printf(" \n \n %c %ld", uc, 78948L);
    printf(" \n \n short(127) %d \n \n ushort(255) %d \n \n int(32767) %d \n \n uint(65535) %d", s, us, i, ui);
    printf(" \n \n long(2147483647) %d \n \n \n \n ulong(2147483647) %d", L, uL); 
    
	// ulong(2147483647) =   2147483647
	// ulong(2147483648) = - 2147483648
	// ulong(4294967296) = 0 
	
    printf(" \n \n ulong(2147483648) %d \n \n ulong(4294967296) %d", uL+1, 4294967296); 
    
    printf(" \n\n\n\n\n\n ***********************************************************  \n\n\n");

    uL = 2147483647;
	
    for (i = -4 ; i<5; i++)
    {     printf(" \n \n \n ulong  2147483647 + %d  = %d", i, uL+i);
	}
	
	printf(" \n\n\n\n\n\n ***********************************************************  \n\n\n");
	
    
	uL =4294967296;
    for (i = -4 ; i<5; i++)
    {     printf(" \n \n \n ulong  4294967296 + %d  = %d", i, uL+i);
	}
	
   
}

