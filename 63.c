#include <stdio.h>

int myfunc(int a, int b)
{
    static int myvar;//Initially value of myvar is 0 because of static variable default value.
    myvar++;
    printf("The myvar is %d\n", myvar);
    return myvar;
}

int main()
{

    register int myvar = myfunc(3, 5);
    myvar = myfunc(3, 5);
    myvar = myfunc(3, 5);
    myvar = myfunc(3, 5);

    return 0;
}
