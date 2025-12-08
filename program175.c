#include <stdio.h>
int main(){
    FILE *f=fopen("out.txt","w");
    if(!f) return 0;
    fprintf(f,"example output\n");
    fclose(f);
    printf("written\n");
    return 0;
}