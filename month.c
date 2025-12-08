#include <stdio.h>

int main()
{

    int num;
    do
    {
        printf("Enter any number between 1 and 12 : ");
        scanf("%d", &num);
    } while (num < 1 || num > 7);

    switch (num)
    {
    case 1:
        printf("You choose!! January");
        break;
    case 2:
        printf("You choose!! February");
        break;
    case 3:
        printf("You choose!! March");
        break;
    case 4:
        printf("You choose!! April");
        break;
    case 5:
        printf("You choose!! May");
        break;
    case 6:
        printf("You choose!! June");
        break;
    case 7:
        printf("You choose!! July");
        break;
    case 8:
        printf("You choose!! August");
        break;
    case 9:
        printf("You choose!! September");
        break;
    case 10:
        printf("You choose!! October");
        break;
    case 11:
        printf("You choose!! November");
        break;
    case 12:
        printf("You choose!! December");
        break;
    }

    return 0;
}
