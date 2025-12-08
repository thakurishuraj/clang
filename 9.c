#include <stdio.h>

int main()
{

    int rows;
    printf("Enter the rows : ");
    scanf("%d", &rows);

    char c = 'A';
    for (int i = rows - 1; i >= 0; i--)
    {
        for (char c = 'A' + i; c <= 'A' + rows - 1; c++)
            printf("%c", c);
        printf("\n");
    }

    return 0;
}
