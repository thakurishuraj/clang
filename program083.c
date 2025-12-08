#include <stdio.h>
int main(){
    int a[100],n;
    if(scanf("%d",&n)==1){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int s=0;
        for(int i=0;i<n;i++) s+=a[i];
        printf("%d\n",s);
    }
    return 0;
}