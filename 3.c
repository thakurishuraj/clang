#include <stdio.h>

int main()
{

    int rows;
    printf("Enter the rows : ");
    scanf("%d", &rows);

    for (int i = rows; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
            printf("%d", j);
        printf("\n");
    }

    return 0;
}
