// WAP using realloc function

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *ptr;
    int n;
    printf("Enter size : ");
    scanf("%d", &n);

    ptr = (int *)calloc(n, sizeof(int));
    printf("Enter %d values : \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }

    printf("Enter new size : ");
    scanf("%d", &n);
    printf("\n");

    ptr = (int *)realloc(ptr, n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }

    return 0;
}
