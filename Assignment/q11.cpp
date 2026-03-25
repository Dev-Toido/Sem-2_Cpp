// Q11. Blood Bank Inventory System
// A hospital manages blood units. Units must be tracked carefully.
// Requirements:
//     Create class BloodBank.
//         Private:
//             bloodGroup
//             unitsAvailable
//         Public:
//             addUnits()
//             useUnits()
//             getAvailableUnits()
//         Conditions:
//             Units cannot go below zero
//             Usage must be validated
#include <iostream>
using namespace std;

class BloodBank
{
private:
    string bloodGroup;
    int unitsAvailable;

public:
    BloodBank(string bg) : bloodGroup(bg), unitsAvailable(0) {}
    void addUnits()
    {
        int u;
        cout << "Enter the units to add: ";
        cin >> u;
        unitsAvailable += u;
        cout << "The units are updated!" << endl;
    }
    void useUnits()
    {
        int u;
        cout << "Enter the units to use: ";
        cin >> u;
        if (unitsAvailable - u < 0)
        {
            cout << "Sorry not enough units available!" << endl;
        }
        else
        {
            unitsAvailable -= u;
            cout << "The requried units are used!" << endl;
        }
    }
    void getAvailableUnits() {
        cout<<"The Available units are: "<<unitsAvailable<<endl;
    }
};
int main()
{
    BloodBank b1("A+");
    b1.addUnits();
    b1.getAvailableUnits();
    b1.useUnits();
    b1.useUnits();


    return 0;
}