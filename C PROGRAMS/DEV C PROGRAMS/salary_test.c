main( )
{
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
