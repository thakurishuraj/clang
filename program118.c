#include <stdio.h>
#include <string.h>
int main(){
    char s[200]; 
    if(scanf("%199s",s)==1){
        int i=0,j=strlen(s)-1,ok=1;
        while(i<j) if(s[i++]!=s[j--]){ok=0;break;}
        printf("%s\n",ok?"palindrome":"not palindrome");
    }
    return 0;
}