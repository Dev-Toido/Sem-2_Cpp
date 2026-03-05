// Simple Singly Linked List in C
// This program only:
// Creates nodes (at least 5)
// Links them
// Displays the list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *ptr;
};

struct node * makelinklist(struct node *head,int noofnodes){
    head = (struct node *)malloc(sizeof(struct node));
    struct node *newnode=head;
    for(int i=0;i<noofnodes;i++){
        printf("Enter the data of %d node: ",i+1);
        scanf("%d",&newnode->data);
        if(i<noofnodes-1){
            newnode->ptr=(struct node *)malloc(sizeof(struct node));
            newnode=newnode->ptr;
        }
    }
    newnode->ptr=NULL;
    return head;
}
void displaylinklist(struct node *head){
    struct node *p=head;
    while (p!=NULL){
        printf("%d ",p->data);
        p=p->ptr;
    } 
}

int main() {
    struct node *head;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    head = makelinklist(head,n);
    printf("The link list is as follows: \n");
    displaylinklist(head);
    return 0;
}