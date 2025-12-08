#include <stdio.h>
int main(){
    int a,b;
    if(scanf("%d %d",&a,&b)==2){
        int t=a;
        a=b;
        b=t;
        printf("%d %d\n",a,b);
    }
    return 0;
}