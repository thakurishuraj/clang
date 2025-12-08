#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *ptr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory not allocated!\n");
        return 1;
    }
    printf("Enter %d integers:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    printf("\nYou entered:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }

    free(ptr);
    printf("\n\nMemory freed successfully.\n");
    printf("\n");

    return 0;
}
