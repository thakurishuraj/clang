#include <stdio.h>
int main(){
    int n,i,prime=1;
    if(scanf("%d",&n)==1){
        if(n<2) prime=0;
        for(i=2;i*i<=n && prime;i++) if(n%i==0) prime=0;
        printf("%s\n",prime?"prime":"not prime");
    }
    return 0;
}