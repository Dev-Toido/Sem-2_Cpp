// Q6. Write a C++ program to create a class Product with data members such as product ID, product name, quantity, and price.
// Create an array of objects to store details of at least 5 products. The program should:
// Accept the product details from the user.
// Display the details of all products.
// Calculate and display the total inventory value (quantity × price) of each product.

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Product
{
public:
    int productID;
    string productName;
    int quantity;
    int price;


    void display()
    {
        cout << left << "|" << setw(15) << productID << "|" << setw(15) << productName << "|" << setw(15) << quantity << "|" << setw(15) << price << "|" << endl;
        cout << "+" << string(15, '-') << "+" << string(15, '-') << "+" << string(15, '-') << "+" << string(15, '-') << "+" << endl;
    }
};
void inputProducts(Product *p,int n){
    cout<<"Enter the Details of the products: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter the details for "<<i+1<<" item: "<<endl;
        cout<<"Product ID: ";
        cin>>p[i].productID;
        cout<<"Product Name: ";
        cin>>p[i].productName;
        cout<<"Quantity: ";
        cin>>p[i].quantity;
        cout<<"Price: ";
        cin>>p[i].price;
        cout<<string(60,'-')<<endl;
    }
}
void displayTable(Product *p,int n)
{
    cout << "+" << string(15, '-') << "+" << string(15, '-') << "+" << string(15, '-') << "+" << string(15, '-') << "+" << endl;
    cout << left << "|" << setw(15) << " Product ID" << "|" << setw(15) << " Product Name" << "|" << setw(15) << " Quantity" << "|" << setw(15) << " Price" << "|" << endl;
    cout << "+" << string(15, '-') << "+" << string(15, '-') << "+" << string(15, '-') << "+" << string(15, '-') << "+" << endl;
    for(int i=0;i<n;i++){
        p[i].display();
    }
}
void totalInventory(Product *p,int n){
    int amt=0;
    for(int i=0;i<n;i++){
        cout<<"The Total Amount of the product with ID "<<p[i].productID<<" is Rs"<<p[i].quantity*p[i].price<<endl;
        amt+=p[i].quantity*p[i].price;
    }
    cout<<"Total Amount of Inventory = Rs"<<amt<<endl;
}
int main()
{
    int noofpro;
    cout<<"Enter the no. of products: ";
    cin>>noofpro;
    Product p[noofpro];
    inputProducts(p,noofpro);
    displayTable(p,noofpro);
    totalInventory(p,noofpro);
    return 0;
}