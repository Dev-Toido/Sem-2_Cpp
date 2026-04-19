// Q2 . Bank Account Transfer System
// Story:
//  Two bank accounts need to transfer money between each other. A special function (not a member of any class) should access private balances of both accounts.
// Class: BankAccount
// Attributes (Private):
// accountNumber
// balance
// Friend Function:
// transfer(BankAccount &a1, BankAccount &a2, double amount)
// 👉 Task:
// Deduct amount from one account and add to another
// Display updated balances
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string accNum, double bal) {
        accountNumber = accNum;
        balance = bal;
    }

    // Display function to show account status
    void display() const {
        cout << "Account: " << accountNumber << " | Balance: Rs" << fixed << setprecision(2) << balance << endl;
    }

    // Declaring the friend function
    friend void transfer(BankAccount &a1, BankAccount &a2, double amount);
};

// Definition of the non-member friend function
// We use references (&) to ensure we modify the actual account objects
void transfer(BankAccount &sender, BankAccount &receiver, double amount) {
    cout << "\nInitiating transfer of Rs" << amount << "..." << endl;
    cout << "From: " << sender.accountNumber << " To: " << receiver.accountNumber << endl;

    if (amount <= sender.balance) {
        sender.balance -= amount;    // Deducting from sender
        receiver.balance += amount;  // Adding to receiver
        cout << "Transfer Successful!" << endl;
    } else {
        cout << "Transfer Failed: Insufficient funds in account " << sender.accountNumber << endl;
    }
    cout << "--------------------------------------------" << endl;
}

int main() {
    // Creating two bank accounts
    BankAccount account1("ACC101", 1000.00);
    BankAccount account2("ACC202", 500.00);

    // Display initial state
    cout << "Initial Balances:" << endl;
    account1.display();
    account2.display();

    // Perform the transfer
    transfer(account1, account2, 250.50);

    // Display updated state
    cout << "Updated Balances:" << endl;
    account1.display();
    account2.display();

    return 0;
}