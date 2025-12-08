#include <stdio.h>

int main()
{

    int rows;
    printf("Enter the rows : ");
    scanf("%d", &rows);

    char c = 'A';
    for (int i = 0; i < rows; i++)
    {
        for (char ch = 'A' + i; ch >= 'A'; ch--)
            printf("%c", ch);
        printf("\n");
    }

    return 0;
}
