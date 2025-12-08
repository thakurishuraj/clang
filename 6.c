#include <stdio.h>

int main()
{

    int rows;
    printf("Enter the rows : ");
    scanf("%d", &rows);

    char c = 'A';
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
            printf("%c", c++);
        printf("\n");
    }

    return 0;
}
