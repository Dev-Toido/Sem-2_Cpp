// Q1. Write a program to:
// Allocate memory for 5 integers.
// Accept and display the elements.
// Resize the array to 10 integers using realloc().
// Accept additional values and display the final array.
#include <stdio.h>
#include <stdlib.h>

void inputdata(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element: ", i + 1);
        scanf("%d", a + i);
    }
    printf("Data entry done!!\n");
}
void displaydata(int *a, int n)
{
    printf("The element of the array are: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(a + i));
    }
    printf("\n");
}

int main()
{
    int noofele = 5;
    int *arr = (int *)calloc(noofele, sizeof(int));

    if (arr != NULL)
    {
        inputdata(arr, noofele);
        displaydata(arr, noofele);
        int newnoofele = 10;
        arr = (int *)realloc(arr, 10 * sizeof(int));
        inputdata(arr + noofele, newnoofele - noofele);
        displaydata(arr, newnoofele);
    }
    else
    {
        printf("Error in creating the dynamicaly allocated array!!");
    }

    free(arr);
    return 0;
}