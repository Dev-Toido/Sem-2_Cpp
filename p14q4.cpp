// Q4. Bank Account System
// Create class Account:
// accNo, name, balance
// Tasks:
// Deposit/Withdraw
// Update file records
// Display accounts with low balance

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_ACCOUNTS = 100; // Maximum accounts the system can handle in one update

class Account {
public:
    int accNo;
    string name;
    double balance;

    void display() {
        cout << left << setw(10) << accNo 
             << setw(20) << name 
             << "$" << fixed << setprecision(2) << balance << endl;
    }
};

// Function to add a new account (Append mode)
void createAccount() {
    Account acc;
    cout << "Enter Account Number: "; cin >> acc.accNo;
    cout << "Enter Name: "; cin.ignore(); getline(cin, acc.name);
    cout << "Enter Initial Balance: "; cin >> acc.balance;

    ofstream outFile("bank.txt", ios::app);
    if (outFile) {
        outFile << acc.accNo << " " << acc.name << " " << acc.balance << endl;
        outFile.close();
        cout << "Account created successfully!\n";
    }
}

// Function to update records without using remove/rename
void processTransaction(int targetAcc, double amount, bool isDeposit) {
    Account accounts[MAX_ACCOUNTS];
    int count = 0;
    bool found = false;

    // 1. Read everything from the file into an array
    ifstream inFile("bank.txt");
    if (!inFile) {
        cout << "Error: Could not open file.\n";
        return;
    }

    while (count < MAX_ACCOUNTS && inFile >> accounts[count].accNo >> accounts[count].name >> accounts[count].balance) {
        if (accounts[count].accNo == targetAcc) {
            found = true;
            if (isDeposit) {
                accounts[count].balance += amount;
            } else {
                if (amount <= accounts[count].balance) {
                    accounts[count].balance -= amount;
                } else {
                    cout << "Insufficient funds!\n";
                }
            }
        }
        count++;
    }
    inFile.close();

    if (!found) {
        cout << "Account not found.\n";
        return;
    }

    // 2. Overwrite the file with the updated array data
    ofstream outFile("bank.txt", ios::out | ios::trunc); // trunc clears the file
    for (int i = 0; i < count; i++) {
        outFile << accounts[i].accNo << " " << accounts[i].name << " " << accounts[i].balance << endl;
    }
    outFile.close();
    cout << "Transaction processed and file updated.\n";
}

// Function to display accounts with balance less than 500
void showLowBalance() {
    ifstream inFile("bank.txt");
    Account acc;
    bool found = false;

    cout << "\n--- Low Balance Report (Below $500) ---\n";
    while (inFile >> acc.accNo >> acc.name >> acc.balance) {
        if (acc.balance < 500.0) {
            acc.display();
            found = true;
        }
    }
    if (!found) cout << "No low balance accounts found.\n";
    inFile.close();
}

int main() {
    int choice, accNum;
    double amt;

    do {
        cout << "\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Low Balance Report\n5. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2:
                cout << "Enter Acc No: "; cin >> accNum;
                cout << "Enter Amount: "; cin >> amt;
                processTransaction(accNum, amt, true);
                break;
            case 3:
                cout << "Enter Acc No: "; cin >> accNum;
                cout << "Enter Amount: "; cin >> amt;
                processTransaction(accNum, amt, false);
                break;
            case 4: showLowBalance(); break;
        }
    } while (choice != 5);

    return 0;
}

