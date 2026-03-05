// Develop a program using malloc() to:
// Dynamically allocate memory for a string.
// Accept a string from the user.
// Display the string.
// Display the length of the string.


#include <stdio.h>
#include <stdlib.h>

int main() {
    char *arr;
    int n;
    printf("Enter the length of string: ");
    scanf("%d", &n);
    n++;

    arr = (char*)malloc((n)*sizeof(char));
    if(arr==NULL){printf("Sorry memory issue! Fail to Dyanamically Allocate memory!");return 1;}
    printf("Enter the string: ");
    for(int i = 0; i < n; i++) {
        scanf(" %c", arr+i);
    }
    *(arr+n) = '\0';
    
    printf("The string is: %s\n", arr);
    printf("Length of string: %d\n", n);

    free(arr);
    return 0;
}