#include <stdio.h>
int power(int a,int b){
    int p=1;
    for(int i=0;i<b;i++) p*=a;
    return p;
}
int main(){
    int a,b;
    if(scanf("%d %d",&a,&b)==2) printf("%d\n",power(a,b));
    return 0;
}