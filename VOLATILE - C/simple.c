 #ifndef VOLATILE
 #define VOLATILE
 #endif
 #include <stdio.h>
 int main(int argc, char *argv[])
 {
     VOLATILE int i;
     int x=0;
     for (i=0;i<77; i++)
        {x=i+x;}
     printf("x=%d\n",x);
     return 0;
 }