#include <stdio.h>
int main(){
    int a,b,c;
    if(scanf("%d %d %d",&a,&b,&c)==3){
        int max=a;
        if(b>max) max=b;
        if(c>max) max=c;
        printf("%d\n",max);
    }
    return 0;
}