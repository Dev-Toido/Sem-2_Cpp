// Write a C program using malloc() to dynamically allocate memory for an array of integers.
//  The program should:
// Read n numbers from the user
// Display all elements
// Find and display the largest number in the array

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr,n,max=0;
    printf("Enter the Number of elements: ");
    scanf("%d",&n);

    arr=(int*)malloc(n*sizeof(int));
    if(arr==NULL){printf("Sorry memory issue! Fail to Dyanamically Allocate memory!");return 1;}
    for(int i=0;i<n;i++){
        printf("Enter the %d element: ",i+1);
        scanf("%d ",arr+i);
    }

    printf("The elements are : \n");
    for(int i=0;i<n;i++){printf("%d\n",*(arr+i));}

    for(int i=0;i<n;i++){
        if(max<*(arr+i))max=*(arr+i);
        }

    printf("The largest number is %d",max);
    free(arr);
    return 0;
}