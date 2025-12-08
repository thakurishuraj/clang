#include <stdio.h>
int main(){
    int a[100],n;
    if(scanf("%d",&n)==1){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int max=a[0];
        for(int i=1;i<n;i++) if(a[i]>max) max=a[i];
        printf("%d\n",max);
    }
    return 0;
}