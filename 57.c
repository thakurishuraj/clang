// WAP to reverse the string

#include <stdio.h>

int main()
{
    char str[100];
    int start = 0, end = 0;
    char temp;

    printf("Enter a string: ");
    gets(str);

    while (str[end] != '\0')
    {
        end++;
    }
    end--;

    while (start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

    printf("Reversed string = %s", str);

    return 0;
}
