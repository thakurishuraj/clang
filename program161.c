#include <stdio.h>
int binsearch(int a[],int n,int x){
    int l=0,r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]==x) return m;
        if(a[m]<x) l=m+1; else r=m-1;
    }
    return -1;
}
int main(){
    int a[100],n,x;
    if(scanf("%d",&n)==1){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        if(scanf("%d",&x)==1) printf("%d\n",binsearch(a,n,x));
    }
    return 0;
}