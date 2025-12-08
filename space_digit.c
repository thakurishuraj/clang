#include <stdio.h>

int main()
{

    int num;
    int rev = 0;
    printf("Enter any num : ");
    scanf("%d", &num);

    int temp = num;
    while (temp > 0)
    {
        rev = rev * 10 + (temp % 10);
        temp = temp / 10;
    }
    printf("Digits are : ");

    while (rev > 0)
    {
        printf("%d ", rev % 10);
        rev = rev / 10;
    }

    return 0;
}