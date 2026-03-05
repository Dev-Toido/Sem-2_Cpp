#include <stdio.h>

int main() {
    // Your code goes here
    size_t a=sizeof(int);
    printf("Enter a number: ");
    scanf("%zu",&a);
    printf("%zu",a);
    return 0;
}