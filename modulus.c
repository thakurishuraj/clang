#include<stdio.h>

int main(){

int a, b;
printf("Enter the value of a and b : ");
scanf("%d %d", &a, &b);
printf("The remainder of %d divided by %d is %d.", a, b, a%b);

return 0;

}
