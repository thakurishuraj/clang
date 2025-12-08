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
        for (int k = 0; k < i ; k++)
        {
            printf("%c", 'A' + k);
        }
        for (int k = i - 2; k >= 0; k--)
        {
            printf("%C", 'A' + k);
        }

        printf("\n");
    }
    return 0;
}