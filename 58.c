#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[40];
    int age;
    unsigned long mobile;
};

int main()
{

    struct student st1;

    struct student *st2;
    st2 = (struct student *)malloc(sizeof(struct student));
    printf("Enter student name : ");
    fgets(st1.name, 40, stdin);
    printf("Enter the age : ");
    scanf("%d", &st1.age);
    printf("Enter mobile number : ");
    scanf("%lu", &st1.mobile);
    printf("Using simple structure variable\n");
    printf("student name : %s\n", st1.name);
    printf("student name : %d\n", st1.age);
    printf("student name : %lu\n", st1.mobile);

    // Input using 2nd option
    //  printf("Enter student name : ");
    // fgets(st2->name, 40, stdin);
    // printf("Enter the age : ");
    // scanf("%d", &st2->age);
    // printf("Enter mobile number : ");
    // scanf("%lu", &st2->mobile);

    // printf("Using simple structure variable\n");
    // printf("student name : %s\n",st2->name );
    // printf("student name : %d\n",st2->age );
    // printf("student name : %lu\n",st2->mobile );

    free(st2);
    printf("The memory freed successfully.");

    return 0;
}
