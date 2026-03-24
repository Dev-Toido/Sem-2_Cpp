// Q2. Dynamic String Handling
// Accept length of string from user.
// Allocate memory using malloc().
// Accept string input.
// Display:
// Length of string
// Free memory.
// Print message if pointer becomes NULL.
#include <stdio.h>
#include <stdlib.h>
int main() {
    int sizeStr;
    printf("Enter the size of the string: ");
    scanf("%d",&sizeStr);
    sizeStr++;
    char* str=(char*)malloc(sizeof(char)*sizeStr);

    if(str!=NULL){
        printf("Enter the string: ");
        scanf("%s",str);
        str[sizeStr-1]='\0';

        printf("The Lenght of the String \"%s\" is %d",str,sizeStr-1);

        free(str);
    }
    else
    {
        printf("Error in creating the dynamicaly allocated array!!");
    }
    return 0;
}