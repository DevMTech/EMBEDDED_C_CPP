 // Program to measure the difference between volatile and not
 // written by Kevin P. Dankwardt k@kcomputing.com
 // 3 March 2005
 // compile with -O2 flag to see volatile make a difference
 // compile with -DVOLATILE=volatile to use volatile.
 // 3 March 2005
 
 #include <stdio.h>
 #include <signal.h>
 #include <sched.h>
 
 int total=0;
 #ifndef VOLATILE
 #define VOLATILE
 #endif
 void handle(int signo)
 {
    int t=total;
    char type[100];
    printf("%d\n", t);
    exit(0);
 }
 int main ()
 {
   VOLATILE int x=0;
   VOLATILE int i,j;
   struct sched_param param;
 
   param.sched_priority = 99;
   if (sched_setscheduler(0, SCHED_RR, &param) ==-1) {
       perror("setting priority");
       exit(1);
   }
   #define BIGNUM (1span>
   
   alarm(10);
   signal(SIGALRM,handle);
   for (i=0; i<BIGNUM; i++)
       {
       total++;
       for (j=0; j<BIGNUM; j++)
              x =  x+j ;
       }
   printf("x = %d\n",x); // so optimizers doesn't throw away the loop
 }