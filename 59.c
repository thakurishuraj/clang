//Union: First the union will check who accquire the largest bytes and then divide it into smaller parts with smallest datatype which union have in the programme and allocate the exact or some nearest integer memory.


#include<stdio.h>
#include<string.h>

union student
{
    int id;
    int marks;
    char fav_char;
    char name[40];
};


int main(){

    union student s1;
    strcpy(s1.name, "Jatin");
    s1.fav_char = 'u';
    s1.id = 56;
    s1.marks = 99; //The variable on this position only works.
    printf("%d", s1.marks);

return 0;

}
