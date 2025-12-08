#include <stdio.h>

int main()
{

    int rows;
    printf("Enter the rows : ");
    scanf("%d", &rows);

    char c = 'A';
    for (int i = 0; i < rows; i++)
    {
        for (int s = 0; s < rows - i - 1; s++)
            printf(" ");

        for (char c = 'A'; c <= 'A' + i; c++)
            printf("%c", c);
        for (char c = 'A' + i - 1; c >= 'A'; c--)
            printf("%c", c);

        printf("\n");
    }

    for (int i = rows - 2; i >= 0; i--)
    {
        for (int s = 0; s < rows - i - 1; s++)
            printf(" ");

        for (char c = 'A'; c <= 'A' + i; c++)
            printf("%c", c);
        for (char c = 'A' + i - 1; c >= 'A'; c--)
            printf("%c", c);

        printf("\n");
    }

    return 0;
}
