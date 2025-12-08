#include <stdio.h>
int main(){
    int n;
    if(scanf("%d",&n)==1){
        int cnt=0;
        while(n){cnt++;n/=10;}
        printf("%d\n",cnt);
    }
    return 0;
}