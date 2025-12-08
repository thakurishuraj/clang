#include <stdio.h>
int main(){
    int n;
    if(scanf("%d",&n)==1){
        int x=n,arm=0;
        while(x){int d=x%10;int p=1;for(int i=0;i<3;i++) p*=d;arm+=p;x/=10;}
        printf("%s\n",arm==n?"armstrong":"not armstrong");
    }
    return 0;
}