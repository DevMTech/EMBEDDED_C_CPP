#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

long long solve (int l, int r) {
   // Your code goes here
   
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t_i = 0; t_i < T; t_i++)
    {
        int l;
        scanf("%d", &l);
        int r;
        scanf("%d", &r);

        long long out_ = solve(l, r);
        printf("%lld", out_);
        printf("\n");
    }
}