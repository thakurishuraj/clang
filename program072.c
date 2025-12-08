#include <stdio.h>
int main(){
    int n;
    if(scanf("%d",&n)==1){
        for(int i=2;i<=n;i++) if(n%i==0){printf("%d\n",i);break;}
    }
    return 0;
}