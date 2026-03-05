// Course Enrollment Management (using malloc and realloc)
// Objective:
//  To apply multiple DMA functions for structure handling.
// Problem Definition:
//  An institute wants to manage course enrollment details such as Enrollment ID, Student Name, Course Name, and Duration.
// Requirements:
// Allocate memory using malloc() for initial records.
// Add new enrollment records using realloc().
// Display all enrollment records.
// Search records using Enrollment ID.

#include <stdio.h>
#include <stdlib.h>

struct cem
{
    long long int enrollno;
    char sname[100];
    char course[20];
    int duration;
};

void printstructcem(struct cem *students,int noofstu){
     printf("The details of all the students are\n");
    printf(":   Enrollment Number   :   :     Student Name     :   :      Course      : :  Duration  :\n");
    for(int i=0;i<noofstu;i++){
        
        printf(":%23lld:   :%22s:   :%18s: : %7d yrs:\n",students[i].enrollno,students[i].sname,students[i].course,students[i].duration);
    }
}
void searchstructcem(struct cem *students,int noofstu){
    long long int searchno;int f=0;
    printf("Enter the Enrollment number to search : ");
    scanf("%lld",&searchno);
    
    printf("The details of the students with the students number is\n");
    printf(":   Enrollment Number   :   :     Student Name     :   :      Course      : :  Duration :\n");
    for(int i=0;i<noofstu;i++){
        if(students[i].enrollno==searchno){
            f=1;
            printf(":%23lld:   :%22s:   :%18s: : %7d yrs:\n",students[i].enrollno,students[i].sname,students[i].course,students[i].duration);}
    }
    if(!f){printf("Sorry no data found!");}
}

void inputstructcem(struct cem *students,int noofstu,int extrastu){
    for(int i=(extrastu==0)?0:noofstu;i<noofstu+extrastu;i++){
        printf("Enter the details of the %d students\n",i+1);
        
        printf("Enrollment Number: ");
        scanf("%lld",&students[i].enrollno);
        printf("Student Name: ");
        scanf("%s",&students[i].sname);
        printf("Course: ");
        scanf("%s",&students[i].course);
        printf("Duration(in years): ");
        scanf("%d",&students[i].duration);
    }

}

int main(){
    int noofstu,extrastu;

    printf("Enter the number of students: ");
    scanf("%d",&noofstu);

    struct cem *students = (struct cem*)calloc(noofstu,sizeof(struct cem));    

    inputstructcem(students,noofstu,0);
    printstructcem(students,noofstu);
    
    printf("Enter the extra number of students: ");
    scanf("%d",&extrastu);

    
    students=(struct cem*)realloc(students,(noofstu)*sizeof(struct cem));
    inputstructcem(students,noofstu,extrastu);
    printstructcem(students,noofstu+extrastu);

    searchstructcem(students,noofstu+extrastu);
    
    free(students);
    return 0;
}