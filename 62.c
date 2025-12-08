#include<stdio.h>

int myfunc(int a, int b){
    extern int sum;
    return sum;
}
int sum = 789;

int main(){

    int sum = myfunc(3, 5);
    printf("The sum is %d", sum);

return 0;

}
