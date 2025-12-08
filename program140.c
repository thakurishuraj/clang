#include <stdio.h>
int is_even(int x){return x%2==0;}
int main(){
    int x;
    if(scanf("%d",&x)==1) printf("%s\n",is_even(x)?"even":"odd");
    return 0;
}