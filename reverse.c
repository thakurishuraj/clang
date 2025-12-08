#include <stdio.h>

int reverse (int num){
    int remainder;
    int reversed;
     while (num != 0) {
        remainder = num % 10;       
        reversed = reversed * 10 + remainder; 
        num = num / 10;            
    }
    printf("\nThe reversed number is %d", reversed);
    return reversed;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

   
    reverse(num);

    return 0;
}
