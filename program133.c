#include <stdio.h>
int main(){
    int n;
    if(scanf("%d",&n)==1){
        int s=0;
        for(int i=1;i<=n;i++) s+=i;
        printf("%d\n",s);
    }
    return 0;
}