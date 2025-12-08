#include <stdio.h>
int main()
{
    int rows;
    printf("Enter the rows : ");
    scanf("%d", &rows);
    char temp = 'A';
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("%c", temp++);
        }
        printf("\n");
    }
    return 0;
}