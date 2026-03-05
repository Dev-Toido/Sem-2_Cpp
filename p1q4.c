// Hospital Patient Management System (using malloc)
// Problem Definition:
//  A hospital wants to maintain patient details for OPD management. The system should store Patient ID, Name, Age, Disease, and Consultation Fee.
// Requirements:
// Accept the number of patients.
// Allocate memory dynamically using malloc().
// Display all patient records.
// Search patient details using Patient ID.
#include <stdio.h>
#include <stdlib.h>
struct hpms
{
    int pid;
    char pname[100];
    int age;
    char disease[20];
    int fee;
};

int main()
{
    int npat;
    printf("Enter the number of patient: ");
    scanf("%d", &npat);

    struct hpms *patients = (struct hpms *)malloc(npat * sizeof(struct hpms));
    if (patients == NULL)
    {
        printf("Sorry memory issue! Fail to Dyanamically Allocate memory!");
        return 1;
    }
    for (int i = 0; i < npat; i++)
    {
        printf("Enter the details of the %d patient\n", i + 1);

        printf("Patient ID: ");
        scanf("%d", &patients[i].pid);
        printf("Patient Name: ");
        scanf("%s", &patients[i].pname);
        printf("Age: ");
        scanf("%d", &patients[i].age);
        printf("Disease: ");
        scanf("%s", &patients[i].disease);
        printf("Consultation Fee: ");
        scanf("%d", &patients[i].fee);
    }

    printf("The details of all the patients are\n");
    printf(":  Patient ID  : :     Patient Name     : : Age : :   Disease   : : Fees  :\n");
    for (int i = 0; i < npat; i++)
    {

        printf(":%14d: :%22s: :%5d: :%13s: :Rs %5d:\n", patients[i].pid, patients[i].pname, patients[i].age, patients[i].disease, patients[i].fee);
    }
    int searchid, f = 0;
    printf("Enter the patient ID to search : ");
    scanf("%d", &searchid);

    for (int i = 0; i < npat; i++)
    {
        if (patients[i].pid == searchid)
        {
            printf("The details of the patients with the matching Id is\n");
            printf(":  Patient ID  : :     Patient Name     : : Age : :   Disease   : : Fees  :\n");
            printf(":%14d: :%22s: :%5d: :%13s: :Rs %5d:\n", patients[i].pid, patients[i].pname, patients[i].age, patients[i].disease, patients[i].fee);
            f = 1;
        }
    }
    if (!f)
    {
        printf("Sorry no data found!!");
    }
    free(patients);
    return 0;
}