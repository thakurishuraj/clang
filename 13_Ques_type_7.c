#include <stdio.h>

int main()
{
    int rows;
    printf("Enter the rows : ");
    scanf("%d", &rows);

    // Upper part
    for (int i = 0; i < rows; i++)
    {
        for (int s = 0; s < rows - i - 1; s++)
            printf(" ");
        for (int j = 0; j < 2 * i + 1; j++)
            printf("*");
        printf("\n");
    }

    // Lower part
    for (int i = rows - 2; i >= 0; i--)
    {
        for (int s = 0; s < rows - i - 1; s++)
            printf(" ");
        for (int j = 0; j < 2 * i + 1; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}
