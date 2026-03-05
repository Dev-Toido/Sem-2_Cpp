// Vehicle Registration System (using calloc)
// Problem Definition:
//  An RTO office wants to maintain vehicle registration details such as Vehicle Number, Owner Name, Vehicle Type, and Registration Year.
// Requirements:
// Accept number of vehicles.
// Allocate memory using calloc().
// Display all vehicle records.
// Search vehicle details using Vehicle Number.

#include <stdio.h>
#include <stdlib.h>
struct vrs
{
    long long int vno;
    char oname[100];
    char vtype[20];
    int regisyear;
};

int main(){
    int noofv;
    printf("Enter the number of vehicles: ");
    scanf("%d",&noofv);

    struct vrs *vehicles = (struct vrs*)calloc(noofv,sizeof(struct vrs));    

    for(int i=0;i<noofv;i++){
        printf("Enter the details of the %d vehicles\n",i+1);
        
        printf("Vehicle Number: ");
        scanf("%lld",&vehicles[i].vno);
        printf("Onwer Name: ");
        scanf("%s",&vehicles[i].oname);
        printf("Vehicle Type: ");
        scanf("%s",&vehicles[i].vtype);
        printf("Registration Year: ");
        scanf("%d",&vehicles[i].regisyear);
    }

    printf("The details of all the vehicles are\n");
    printf(":   Vehicle Number   :   :     Onwer Name     :   :   Vehicle Type  : :  Registration Year :\n");
    for(int i=0;i<noofv;i++){
        
        printf(":%20lld:   :%20s:   :%17s: : %20d:\n",vehicles[i].vno,vehicles[i].oname,vehicles[i].vtype,vehicles[i].regisyear);
    }
    long long int searchno;int f=0;
    printf("Enter the vehicle number to search : ");
    scanf("%lld",&searchno);
    
    printf("The details of the vehicles with the Vehicle number is\n");
    printf(":   Vehicle Number   :   :     Onwer Name     :   :   Vehicle Type  : :  Registration Year :\n");
    for(int i=0;i<noofv;i++){
        if(vehicles[i].vno==searchno){
            f=1;
            printf(":%20lld:   :%20s:   :%17s: : %20d:\n",vehicles[i].vno,vehicles[i].oname,vehicles[i].vtype,vehicles[i].regisyear);}
    }
    if(!f){printf("Sorry no data found!");}
    free(vehicles);
    return 0;
}