#include <stdio.h>
int main(){
    int n;
    if(scanf("%d",&n)==1){
        int a=0,b=1;
        while(b<=n){printf("%d ",b);int c=a+b;a=b;b=c;}
        printf("\n");
    }
    return 0;
}