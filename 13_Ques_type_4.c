#include <stdio.h>
int main()
{
    int rows;
    printf("Enter the rows : ");
    scanf("%d", &rows);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("%c", 'A');
        }
        printf("\n");
    }
    return 0;
}