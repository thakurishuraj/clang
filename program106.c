#include <stdio.h>
#include <string.h>
int main(){
    char s[200];
    if(scanf("%199s",s)==1){
        int n=strlen(s);
        for(int i=n-1;i>=0;i--) putchar(s[i]);
        putchar('\n');
    }
    return 0;
}