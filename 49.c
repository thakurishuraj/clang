// WAP using calloc function

//By this your memory allocation start from 0. If you don't want to start your memory allocation from 0 so don't use "calloc"


#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *ptr;
    ptr = (int *)calloc(3, sizeof(int));
    printf("Enter 3 elements\n");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", ptr[i]);
    }

    return 0;
}
