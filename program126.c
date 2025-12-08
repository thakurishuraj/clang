#include <stdio.h>
int main(){
    int a,b;
    if(scanf("%d %d",&a,&b)==2){
        int g=a,bx=b;
        while(b){int t=g%b;g=b;b=t;}
        printf("%d\n",g);
    }
    return 0;
}