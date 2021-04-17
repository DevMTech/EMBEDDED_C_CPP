#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
 
int getNumber (char* house ) {
   // Write your code here
}
 
int main() {
    int T;
    scanf("%d", &T);
    for(int t_i=0; t_i<T; t_i++)
    {
        char* house = (char*)malloc(51200 * sizeof(char));
        scanf("\n%[^\n]s", house);
 
        int out_ = getNumber(house);
        printf("%d", out_);
        printf("\n");
    }
}