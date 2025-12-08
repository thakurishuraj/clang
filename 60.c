//In c programming typedef is used to alias the existing type

#include<stdio.h>

typedef struct student 
{
    int id;
    int marks;
    char fav_char;
    char name[100];
}std;


int main(){

    std S1, S2;
    S1.id = 86;
    S2.id = 89;
    printf("S1's id: %d\n", S1.id);
    printf("S2's id: %d\n", S2.id);

return 0;

}
