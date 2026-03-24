// Q3. Dynamic Allocation for Multiple Structures
// Using the Student structure:
// Ask the user for the number of students.
// Allocate memory dynamically using malloc().
// Store student information.
// Display all records.
#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[50];
    int roll;
    float marks;
};

int main()
{
    int noofstu;
    printf("Enter the no. of Students: ");
    scanf("%d", &noofstu);

    struct Student *students = (struct Student *)malloc(noofstu * sizeof(struct Student));
    printf("Enter the details of the students: \n");
    for (int i = 0; i < noofstu; i++)
    {
        printf("Enter the details of the %d student: \n",i+1);
        printf("Name: ");
        scanf("%s",students[i].name);
        printf("Roll: ");
        scanf("%d",&students[i].roll);
        printf("Marks: ");
        scanf("%f",&students[i].marks);
        
    }

    printf("The details of the students are: \n");
    for (int i = 0; i < noofstu; i++)
    {
        printf("The details of the %d student: \n",i+1);
        printf("Name: %s\n",students[i].name);
        printf("Roll: %d\n",students[i].roll);
        printf("Marks: %f\n",students[i].marks);
        
    }
    free(students);
    return 0;
}