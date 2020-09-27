
// BIG-ENDIAN to LITTLE-ENDIAN & vice-versa
#define ENDIAN_CHANGE_U16(x) ((((x)&0xFF00)>>8) + (((x)&0xFF)<<8))  // uint16_t x = 0xABCD;

#define DONE 0
 
// Example 105: Using static variables to track function depth 
void myRecurseFunc(void) 
{	static int depthCount=1;
	
	if ( (depthCount < 10) && (!DONE) ) 
	{	printf("\n depthCount = %d", depthCount);
		depthCount++;
		myRecurseFunc();
	}	
} 

main()
{
    printf("n\\t %d %f %c", 23451, 124.658, 'd');
    printf("\n %ld", 78948L);
    
    int A, B, C, H, L, i;
	A = B = C = i = 0; 
    
    printf("\n  A = %d ", A );
    
//    for(; i < 34;)
//    {  	A |= (1<<i); // | (1<<4) | (1<<3) | (1<<2) | (1<<1) | (1<<0); // 0111 // SET BIT 0, 1, 2
//       	printf("\n  %d  A = %d ", ++i, A );
//    	A = 0;
//	}
//	
	A = B = i = 0;
	B |= (1<<30); // 2^30 = 1073741824
	printf("\n  B  = %d ", B ); // 1073741824
	
	printf("\n  A&B  = %d ", A&B ); // 0 
	A |= (1<<30)|(1<<29); 
	printf("\n  A&B  = %d \n\n", A&B ); // 1073741824
	
	A = 0;
	while(!(A & (1<<30))) 	//while(!(A&B))
	{	// A |= (1<<30);
		//A = 0;
		A |= (1<<i);
		printf("\n  %d  A = %d ", ++i, A );        	
	}
	
	printf("\n\n");
	
//    for(i=0; i < 31; i++)
//    {  	A |= (1<<i);     
//    	printf("\n  %d  A = %d ", i, A ); // A = 0
//	}
	
	//printf("\n\n");
	
	H = (A & 0xFFFF0000) >> 16;
	L = A & 0xFFFF;
	B = (H << 16) | L;
	
	printf("\n\n  A  = %d ", A );
	printf("\n  AH = %d ", H );
	printf("\n  AL = %d ", L );	
	printf("\n  B  = %d ", B );
	
	printf("\n\n\n");
	
//	i = 30;
//	while(A & (1<<0)) 	//while(!(A&B))
//	{	// A |= (1<<30);
//		//A = 0;
//		A |=(1<<i);
//		printf("\n  %d  A = %d ", --i, A );        	
//	}
//	
	
	
	printf("\n\n");
	
	A = 0;
    
    A |= (1<<30) | (1<<15); //  SET BIT 31    
    L = (A & 0xFFFF);
    H = (A & 0xFFFF0000) >> 16;
    B = (H << 16) | L;
    
    printf("\n  A = %d ", A );
    printf("\n  H = %d ", H );
    printf("\n  L = %d ", L );	
	printf("\n  B = %d ", B );
	
	printf("\n\n");
	printf("\n\n");
	
    
    A |= (1<<2) | (1<<1) | (1<<0); // 0111 // SET BIT 0, 1, 2
    
    printf("\n\n  A = %d ", A );
    
    A = (A | (1<<3)) & ~(1<<2); // 1011 // SET BIT 3 & CLR BIT 2
    
    printf("\n  A = %d ", A );
    
    A = A & ~(1<<3) | (1<<2);  // 0111 // CLR BIT 3 & SET BIT 2
    // A &= (1<<2) | (~(1<<3));
	// A = A & ~(1<<2);    
    	
	printf("\n  A = %d ", A );
	
	 A &= ~((1<<2) | (1<<1) | (1<<0)); // 0111 // SET BIT 0, 1, 2
    
    printf("\n  A = %d \n", A );
    
    myRecurseFunc();
}


/*

int constants:
int n;
n=45;   		// decimal
n=0b101101;		// binary 
n=0x2d; 		// hex 0010 1101 = 2 D
n=0X2D; 		// HEX
n=055;  		// octal 101 101 = 5 5

100d = 0b01100100 = 0144 = 0x64

char ch = 0x61; // 'a'

String constant:
char name[] = "D M"; // char name[] = {'D', ' ', 'M', '\0'};

uint8_t A, B, C;
A = 0xFF; // 255d
B = 0x64; // 100d

C = A & B;
C = A | B;
B = ~ A; // negation/compliment
C = A ^ B; -> odd number of 1's = 1
C = A >> B;
C = A << B;
vacated bits are filled with 0s
C = A >> 3; // RIGHT SHIFT BY 3 = DIVISION BY 8 (2 raised to 3)
C = A << 4; // LEFT SHIFT BY 4 = MULTIPLICATION BY 16 (2 raised to 4)

Bit Masking : LEFT SHIFT
PORTA |= (1<<4) | (1<<5);  // SET BITS 4 & 5
PORTA &= ~((1<<6) | (1<< 7)); // CLR BIT 6 & 7   
PORTA = (PORTA | (1<<3)) & (~(1<<5)); // SET BIT 3 & CLR BIT 6

*/
