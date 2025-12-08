#include <stdio.h>
#include <string.h>
int main(){
    char s[200];
    if(scanf("%199s",s)==1){
        for(int i=0;s[i];i++) if(s[i]>='a'&&s[i]<='z') s[i]=s[i]-'a'+'A';
        printf("%s\n",s);
    }
    return 0;
}