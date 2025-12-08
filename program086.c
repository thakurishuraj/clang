#include <stdio.h>
int linear_search(int a[],int n,int x){
    for(int i=0;i<n;i++) if(a[i]==x) return i;
    return -1;
}
int main(){
    int a[100],n,x;
    if(scanf("%d",&n)==1){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        if(scanf("%d",&x)==1) printf("%d\n",linear_search(a,n,x));
    }
    return 0;
}