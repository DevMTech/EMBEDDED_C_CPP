main( )
{
	
	//	char q, g;
//	int y=0, s=0;
//	printf("Enter your qualification (u/p), gender (M/F) and years of service: \n");
//	scanf(" %c %c %d ", &q, &g, &y);
//	printf(" %c %c %d ", q, g, y);
//
//	
//	
//
//	if(y>=10)
//	{if (q=='p') 
//		{if(g=='M') s = 15000; 
//			else if ( g=='F') s = 12000;
//		}
//	 if (q=='g') 
//	 if(g=='M') s = 10000; 
//	 else if ( g=='F') s = 9000;
//	}
//	else 
//	{if (q=='p') 
//		if(g=='M') s = 15000; 
//		else if ( g=='F') s = 12000;
//	 if (q=='g') 
//	 	if(g=='M') s = 10000; 
//		else if ( g=='F') s = 9000;
//	}
//	
//	printf(" Salary = Rs. %d", s);

//int a=5,b=4,c=0;
//	printf("Enter two integer values:\n");
// 	scanf("%d%d", &a, &b);
//	a>b ? c = a : (c = b);
//	printf("\n c = %d", c);
char g, qualif = 'G' ;
int yos, qual, sal ;
printf("Enter Gender (m/f), Qualifications (G/P) and Years of Service: \n") ;
//printf("Enter Gender, Qualifications ( 0 = G, 1 = PG ) and Years of Service: \n") ;
//printf("Enter Gender and Years of Service: \n") ;

scanf ( "%c%c%d", &g, &qualif, &yos ) ;
//scanf ( "%c%d", &g, &yos ) ;

printf ("\n g = %c , qualif = %c , yos = %d", g, qualif, yos );

if(qualif=='G') qual = 0; 
else qual = 1;

printf ("\n qualif = %c , qual = %d", qualif, qual );

if ( g == 'm' && yos >= 10 && qual == 1 )
sal = 15000 ;
else if ( ( g == 'm' && yos >= 10 && qual == 0 ) || ( g == 'm' && yos < 10 && qual == 1 ) )
sal = 10000 ;
else if ( g == 'm' && yos < 10 && qual == 0 )
sal = 7000 ;
else if ( g == 'f' && yos >= 10 && qual == 1 )
sal = 12000 ;
else if ( g == 'f' && yos >= 10 && qual == 0 )
sal = 9000 ;
else if ( g == 'f' && yos < 10 && qual == 1 )
sal = 10000 ;
else if ( g == 'f' && yos < 10 && qual == 0 )
sal = 6000 ;
printf ( "\nSalary of Employee = %d", sal ) ;



}
