#include <stdio.h>
int gcd(int a,int b){while(b){int t=a%b;a=b;b=t;}return a;}
int main(){
    int a,b;
    if(scanf("%d %d",&a,&b)==2) printf("%d\n",a/gcd(a,b)*(b));
    return 0;
}