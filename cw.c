//#include <stdio.h>

//void toUppercase(char str[]) {
  //  int i = 0;
    //while (str[i] != '\0') {
        // Check if character is lowercase
      //  if (str[i] >= 'a' && str[i] <= 'z') {
        //    str[i] = str[i] - 32;  // Convert to uppercase
        /}
        i++;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);   // safe input method

    toUppercase(str);

    printf("Uppercase String: %s", str);

    return 0;
}