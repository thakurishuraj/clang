#include <stdio.h>
int main(){
    int n;
    if(scanf("%d",&n)==1){
        int rev=0,temp=n;
        int base=1;
        while(temp){rev=rev*10 + (temp%2); temp/=2;}
        printf("%d\n",rev);
    }
    return 0;
}