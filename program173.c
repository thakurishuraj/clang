#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    if(scanf("%d",&n)==1){
        int *a=malloc(n*sizeof(int));
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int s=0;
        for(int i=0;i<n;i++) s+=a[i];
        printf("%d\n",s);
        free(a);
    }
    return 0;
}