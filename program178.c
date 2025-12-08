#include <stdio.h>
int main(){
    int n;
    if(scanf("%d",&n)==1){
        int res=1;
        for(int i=2;i<=n;i++) res*=i;
        printf("%d\n",res);
    }
    return 0;
}