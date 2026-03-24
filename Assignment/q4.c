// Q4. Dynamic Memory Deallocation Demonstration
// Write a program to:
// Allocate memory for an integer array using malloc().
// Store and display values.
// Free the allocated memory using free().
// Try accessing the memory after free() and observe the behavior.
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
    int *arr = (int *)malloc(noofele* sizeof(int));

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
    printf("%d",arr[0]);
    return 0;
}