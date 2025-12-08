#include <stdio.h>

int main()
{

    char dope;
    printf("Enter the character : ");
    scanf("%c", &dope);

    for (char i = 'a'; i < dope; i++)
    {
        printf("%c\n", i);
    }

    return 0;
}
