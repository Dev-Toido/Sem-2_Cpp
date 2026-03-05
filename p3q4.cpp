// Q 4. Product Bill Format
// Create a program that:
// Accepts product name, price, and quantity.
// Calculates total bill.
// Display a proper bill using setw formatting.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string pname;int price,quantity,tbill;  
    cout<<"Enter Product Name:";
    cin>>pname;
    cout<<"Enter price:";
    cin>>price;
    cout<<"Enter quantity:";
    cin>>quantity;

    tbill=quantity*price;

    cout<<left;
    cout<<"+"<<string(60,'-')<<"+"<<endl;
    cout<<"|"<<string(20,' ')<<string(8,' ')<<setw(12)<<"Bill"<<string(20,' ')<<"|"<<endl;
    cout<<"+"<<string(60,'-')<<"+"<<endl;
    cout<<"|"<<setw(20)<<"Product Name "<<setw(20)<<"Price "<<setw(20)<<"Quantity "<<"|"<<endl;
    cout<<"|"<<setw(20)<<pname<<setw(20)<<"Rs "+to_string(price)<<setw(20)<<quantity<<"|"<<endl;        
    cout<<"+"<<string(60,'-')<<"+"<<endl;
    cout<<"|"<<string(20,' ')<<setw(20)<<"Total Amount - "<<setw(20)<<"Rs "+to_string(tbill)<<"|"<<endl;
    cout<<"+"<<string(60,'-')<<"+"<<endl;
    return 0;
}