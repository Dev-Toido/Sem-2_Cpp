// Bank Customer Management System (using malloc)
// Problem Definition:
//  A bank wants to store customer account details such as Account Number, Customer Name, Account Type, and Balance.
// Requirements:
// Accept the number of customers.
// Allocate memory dynamically using malloc().
// Display all customer records.
// Display customers with a balance below ₹5,000.
#include <stdio.h>
#include <stdlib.h>
struct bcms
{
    long long int accno;
    char cname[100];
    char acctype[20];
    int bal;
};

int main(){
    int ncust;
    printf("Enter the number of customer: ");
    scanf("%d",&ncust);

    struct bcms *customers = (struct bcms*)malloc(ncust*sizeof(struct bcms));    
    if(customers==NULL){printf("Sorry memory issue! Fail to Dyanamically Allocate memory!");return 1;}
    for(int i=0;i<ncust;i++){
        printf("Enter the details of the %d customer\n",i+1);
        
        printf("Account Number: ");
        scanf("%lld",&customers[i].accno);
        printf("Customer Name: ");
        scanf("%s",&customers[i].cname);
        printf("Account Type: ");
        scanf("%s",&customers[i].acctype);
        printf("Balance: ");
        scanf("%d",&customers[i].bal);
    }

    printf("The details of all the customers are\n");
    printf(":   Account Number   :   :     Customer Name     :   :   Account Type  : :  Balance :\n");
    for(int i=0;i<ncust;i++){
        
        printf(":%20lld:   :%23s:   :%17s: :Rs %7d:\n",customers[i].accno,customers[i].cname,customers[i].acctype,customers[i].bal);
    }

    int f=0;
    printf("The details of the customers having balance below Rs 5000 are\n");
    printf(":   Account Number   :   :     Customer Name     :   :   Account Type  : :  Balance :\n");
    for(int i=0;i<ncust;i++){
        if(customers[i].bal<5000){
            f=1;
            
            printf(":%20lld:   :%23s:   :%17s: :Rs %7d:\n",customers[i].accno,customers[i].cname,customers[i].acctype,customers[i].bal);}
    }
    if(!f){printf("Sorry no data found!");}
    free(customers);
    return 0;
}