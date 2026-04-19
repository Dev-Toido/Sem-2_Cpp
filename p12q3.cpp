// Q3. Digital Wallet System
// Story:
//  Different digital wallets apply cashback offers differently.
// Base Class: Wallet
//  Attributes:
// userName
// balance
// Member Function:
// virtual void processPayment(double amount)
// Derived Classes:
// PayTM
// PhonePe
// GooglePay
// 👉 Task:
// Override payment logic with different cashback rules
// Display final balance
#include <iostream>
#include <string>
#include <iomanip> // For formatting currency

using namespace std;

// Base Class
class Wallet {
protected:
    string userName;
    double balance;

public:
    Wallet(string name, double initialBalance) {
        userName = name;
        balance = initialBalance;
    }

    // Virtual function to be overridden
    virtual void processPayment(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Processing generic payment for " << userName << "..." << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void displayBalance() {
        cout << userName << "'s Final Balance: Rs" << fixed << setprecision(2) << balance << endl;
        cout << "------------------------------------" << endl;
    }

    virtual ~Wallet() {}
};

// Derived Class 1: PayTM (10% Cashback on all payments)
class PayTM : public Wallet {
public:
    PayTM(string name, double bal) : Wallet(name, bal) {}

    void processPayment(double amount) override {
        if (amount <= balance) {
            double cashback = amount * 0.10;
            balance = (balance - amount) + cashback;
            cout << "[PayTM] Payment of Rs" << amount << " successful!" << endl;
            cout << ">> Flat 10% Cashback Earned: Rs" << cashback << endl;
        } else {
            cout << "[PayTM] Transaction Failed: Insufficient funds." << endl;
        }
    }
};

// Derived Class 2: PhonePe (Flat Rs5 Cashback if amount > Rs100)
class PhonePe : public Wallet {
public:
    PhonePe(string name, double bal) : Wallet(name, bal) {}

    void processPayment(double amount) override {
        if (amount <= balance) {
            double cashback = (amount > 100) ? 5.0 : 0.0;
            balance = (balance - amount) + cashback;
            cout << "[PhonePe] Payment of Rs" << amount << " successful!" << endl;
            if (cashback > 0) cout << ">> Scratch Card Won! Cashback: Rs" << cashback << endl;
            else cout << ">> No cashback earned this time." << endl;
        } else {
            cout << "[PhonePe] Transaction Failed: Insufficient funds." << endl;
        }
    }
};

// Derived Class 3: GooglePay (Randomized 2% "Rewards")
class GooglePay : public Wallet {
public:
    GooglePay(string name, double bal) : Wallet(name, bal) {}

    void processPayment(double amount) override {
        if (amount <= balance) {
            double cashback = amount * 0.02; // Simple 2% reward
            balance = (balance - amount) + cashback;
            cout << "[GooglePay] Payment of Rs" << amount << " successful!" << endl;
            cout << ">> Google Reward added: Rs" << cashback << endl;
        } else {
            cout << "[GooglePay] Transaction Failed: Insufficient funds." << endl;
        }
    }
};

int main() {
    // Initializing different wallets with names and starting balances
    PayTM user1("Alice", 500.0);
    PhonePe user2("Bob", 500.0);
    GooglePay user3("Charlie", 500.0);

    // Processing a Rs200 payment for each to see different cashback results
    user1.processPayment(200.0);
    user1.displayBalance();

    user2.processPayment(200.0);
    user2.displayBalance();

    user3.processPayment(200.0);
    user3.displayBalance();

    return 0;
}