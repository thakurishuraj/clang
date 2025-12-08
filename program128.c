#include <stdio.h>
int main(){
    int n;
    if(scanf("%d",&n)==1){
        int rev=0,x=n;
        while(x){rev=rev*10+x%10;x/=10;}
        printf("%d\n",rev);
    }
    return 0;
}