#include <stdio.h>
int factorial(int n){
    int f=1;
    for(int i=2;i<=n;i++) f*=i;
    return f;
}
int main(){
    int n;
    if(scanf("%d",&n)==1) printf("%d\n",factorial(n));
    return 0;
}