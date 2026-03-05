// Q 3. Mobile Phone Lock System
// Scenario:
//  A phone has a private PIN that should not be visible.
// Task:
// Class: Mobile
// Private: pin
// Public:
// setPin()
// unlock(enteredPin) → print “Unlocked” or “Wrong PIN”

#include <iostream>
using namespace std;

class Mobile
{
private:
    int pin;

public:
    bool setPin()
    {
        int newPin, rePin;
        cout << "Enter your new pin: ";
        cin >> newPin;
        cout << "Please re-enter your new pin: ";
        cin >> rePin;
        if (newPin == rePin)
        {
            cout << "Your Pin is set sucessfully!!" << endl;
            pin = newPin;
            return true;
        }
        else
        {
            cout << "Pin mis-matched! Please re-enter the pin properly!" << endl;
            return false;
        }
    }
    bool unlock(int enteredPin)
    {
        if (enteredPin == pin)
        {
            cout << "Unlocked!!" << endl;
            return true;
        }
        else
        {
            cout << "Wrong Pin!!" << endl;
            return false;
        }
    }
};

int main()
{
    Mobile m1;
    int pin;
    bool flag = false;
    while (!flag)
    {
        flag = m1.setPin();
    }
    flag = false;
    while (!flag)
    {
        cout << "Enter pin to unlock: ";
        cin >> pin;
        flag = m1.unlock(pin);
    }
    return 0;
}