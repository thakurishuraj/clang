// WAP to print your name

#include <stdio.h>

int main()
{

    char arr[100];
    printf("Enter your name : ");
    fgets(arr, sizeof(arr), stdin);
    puts(arr);

    return 0;
}
