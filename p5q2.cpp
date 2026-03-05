// Q.2 Mobile Phone Configuration Copy System
// Scenario:
// A mobile company creates a new phone model based on an existing model configuration.
// Task:
// Create a class Mobile with:
// Brand Name
// RAM
// Price

// Requirements:
// Parameterized constructor
// Copy constructor
// Display both objects

#include <iostream>
#include <iomanip>
using namespace std;

class Mobile
{
public:
    string brandName;
    int ram;
    float price;
    Mobile(string newbName, int newram, float newprice) : brandName(newbName), ram(newram), price(newprice)
    {
        cout << "The mobile object created!!" << endl;
    }
    Mobile(Mobile &m1)
    {
        brandName = m1.brandName;
        ram = m1.ram;
        price = m1.price;
        cout << "The mobile object copy created!!" << endl;
    }
    void showDetails()
    {
        cout << "Phone model details: " << endl;
        cout << left << setw(20) << "Brand Name:" << brandName << endl;
        cout << left << setw(20) << "RAM:" << ram << endl;
        cout << left << setw(20) << "Price:" << price << endl;
    }
};

int main()
{
    string bName;
    int ram;
    float price;
    cout << "Enter your existing phone model details: " << endl;
    cout << left << setw(20) << "Brand Name:";
    cin >> bName;
    cout << left << setw(20) << "RAM:";
    cin >> ram;
    cout << left << setw(20) << "Price:";
    cin >> price;
    Mobile m1(bName, ram, price);
    m1.showDetails();
    Mobile m2(m1);
    m2.showDetails();
    
    return 0;
}