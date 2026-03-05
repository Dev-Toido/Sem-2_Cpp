// ATM Machine System
// Scenario:
//  You are designing software for an ATM machine. A user should not directly change their balance.
// Task:
// Create a class ATM
// Private data: balance
// Public functions:
// deposit(amount)
// withdraw(amount)
// showBalance()

#include <iostream>
#include <string>
using namespace std;

class ATM
{
private:
    int balance;

public:
    ATM()
    {
        balance = 0;
    }
    string username;
    int accno;
    void initializeUser()
    {
        cout << "Enter the user name: ";
        cin >> username;
        cout << "Enter the Account Number: ";
        cin >> accno;
    }
    void deposit(int amount)
    {
        balance += amount;
        cout << "Deposit is sucessfull!" << endl;
    }
    void withdraw(int amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawal Complete!!" << endl;
        }
        else
        {
            cout << "Insufficient Balence!!" << endl;
        }
    }
    void showBalance()
    {
        cout << string(40, '-') << endl;
        cout << "Username: " << username << '\n'
             << "Account no.: " << accno << endl;
        cout << string(40, '-') << endl;
        cout << "The Balance is Rs " << balance << endl;
        cout << string(40, '-') << endl;
    }
};

int main()
{
    ATM user101;

    int ch, amount;
    bool isexit = false;

    cout << "Welcome to ATM!!" << endl;
    user101.initializeUser();
    while (!isexit)
    {
        cout << "Enter the choice \n1. To deposit\n2. To withdraw\n3. To view balance\n0. To exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the amount to be deposit: Rs";
            cin >> amount;
            user101.deposit(amount);
            break;
        case 2:
            cout << "Enter the amount to be withdraw: Rs";
            cin >> amount;
            user101.withdraw(amount);
            break;
        case 3:
            user101.showBalance();
            break;
        case 0:
            isexit = true;
            break;
        default:
            cout << "Wrong input!!" << endl;
            break;
        }
    }

    return 0;
}