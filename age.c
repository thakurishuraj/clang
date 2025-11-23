#include <stdio.h>

int main() {
    char citizen;
    int age;

    printf("Are you an Indian citizen? (y/n): ");
    scanf(" %c", &citizen); // space before %c to avoid newline issues

    if (citizen == 'y' || citizen == 'Y') {
        printf("Enter your age: ");
        scanf("%d", &age);

        if (age >= 18) {
            printf("✅ You are eligible to vote.\n");
        } else {
            printf("❌ You are NOT eligible to vote (under 18).\n");
        }
    } else {
        printf("❌ You are not an Indian citizen, so you cannot vote.\n");
    }

    return 0;
}
