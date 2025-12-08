#include <stdio.h>
int main(){
    int n;
    if(scanf("%d",&n)==1){
        int a=0,b=1;
        for(int i=0;i<n;i++){printf("%d ",a);int c=a+b;a=b;b=c;}
        printf("\n");
    }
    return 0;
}