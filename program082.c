#include <stdio.h>
int main(){
    int n;
    if(scanf("%d",&n)==1){
        int sum=0;
        while(n){sum+=n%10;n/=10;}
        printf("%d\n",sum);
    }
    return 0;
}