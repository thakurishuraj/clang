// voting_eligibility.c
#include <stdio.h>

int main(void) {
    int age;
    printf("Enter your age: ");
    if (scanf("%d", &age) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (age >= 18)
        printf("You are eligible to vote.\n");
    else if (age >= 0)
        printf("You are not eligible to vote yet. Need %d more year(s).\n", 18 - age);
    else
        printf("Age cannot be negative.\n");

    return 0;
}
