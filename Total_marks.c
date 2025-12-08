#include <stdio.h>

int main()
{

    int maths, physics, chemistry, PE, english;
    printf("Enter the marks of maths : ");
    scanf("%d", &maths);
    printf("Enter the marks of physics : ");
    scanf("%d", &physics);
    printf("Enter the marks of chemistry : ");
    scanf("%d", &chemistry);
    printf("Enter the marks of PE : ");
    scanf("%d", &PE);
    printf("Enter the marks of english : ");
    scanf("%d", &english);

    int sum = maths + physics + chemistry + PE + english;

    printf("The total percentage you got in final is %d.", sum/5);

    return 0;
}
