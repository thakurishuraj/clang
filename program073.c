#include <stdio.h>
int main(){
    int n;
    if(scanf("%d",&n)==1){
        int sum=0;
        for(int i=1;i<=n;i++) if(n%i==0) sum+=i;
        printf("%d\n",sum);
    }
    return 0;
}