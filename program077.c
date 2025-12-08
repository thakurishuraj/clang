#include <stdio.h>
int main(){
    int a,b;
    if(scanf("%d %d",&a,&b)==2){
        int tmp=a;a=b;b=tmp;
        printf("%d %d\n",a,b);
    }
    return 0;
}