// Q4. Bank Customer Record System
// Story:
// A bank stores customer details and account history.
// Requirements:
// Class Customer
// Name (string)
// Account Number
// Last 5 transaction amounts (array)

// Calculate:
// Total transaction value
// Highest transaction
// Flag suspicious transaction (> 50000)

#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

class Transaction
{
public:
    int amount = 0;
    bool iswithdraw = false; // 1 for withdraw and 0 for deposit
};

class Customer
{
private:
    string name;
    long int accno;
    int transactions[5];
    bool is_sus = 0;

public:
    void setName()
    {
        cout << "Name: ";
        cin >> name;
    }
    void setAccno()
    {
        cout << "Account No.: ";
        cin >> accno;
    }
    void setTrans()
    {
        cout << "Enter the last five transactions of the customer[Add - for withdraw and  + for deposit before the amount]: ";
        for (int i = 0; i < 5; i++)
        {
            cin >> transactions[i];
        }
    }
    string getname() { return name; }
    long int getAccno() { return accno; }
    bool getSusRepo() { return is_sus; }

    int totalAmount()
    {
        int sum=0;
        for (int i = 0; i < 5; i++)
        {
            sum += transactions[i];
        }
        return sum;
    }
    Transaction highTrans()
    {
        Transaction t;
        for (int i = 0; i < 5; i++)
        {
            int temp = (transactions[i] > 0) ? transactions[i] : -transactions[i];
            if (t.amount < temp)
            {
                t.amount = temp;
                t.iswithdraw = transactions[i] < 0;
            }
            if (temp > 50000)
            {
                is_sus = true;
            }
        }
        return t;
    }
};

void objInit(Customer &c)
{
    c.setName();
    c.setAccno();
    c.setTrans();
}

int main()
{
    int noOfCust;
    cout << "Enter the Number of customer: ";
    cin >> noOfCust;
    Customer c[noOfCust];
    for (int i = 0; i < noOfCust; i++)
    {
        cout << "Enter the details of the " << i + 1 << " customer: " << endl;
        objInit(c[i]);
    }
    cout << string(60, '-') << endl;

    cout << left << setw(20) << "Name" << setw(20) << "Account Number" << setw(10) << "Total Transaction Value(According to last five transactions)" << endl;
    for (int i = 0; i < noOfCust; i++)
    {
        cout << left << setw(20) << c[i].getname() << setw(20) << c[i].getAccno() << setw(10) << c[i].totalAmount() << endl;
    }
    cout << string(60, '-') << endl;

    Transaction highT;
    cout << "The Highest Transactions of Customers are: " << endl;
    cout << left << setw(20) << "Name" << setw(20) << "Account Number" << setw(30) << "Highest Transaction Value" << setw(20) << "Transaction Type" << endl;
    for (int i = 0; i < noOfCust; i++)
    {
        highT = c[i].highTrans();
        cout << left << setw(20) << c[i].getname() << setw(20) << c[i].getAccno() << setw(30) << highT.amount << setw(20) << ((highT.iswithdraw) ? "Withdrawed" : "Deposited") << endl;
    }
    cout << string(60, '-') << endl;

    int noOfSus = 0;
    cout << "The Account details of flaged suspicious Transactions are: " << endl;
    cout << left << setw(20) << "Name" << setw(20) << "Account Number" << endl;
    for (int i = 0; i < noOfCust; i++)
    {
        if (c[i].getSusRepo())
        {
            noOfSus++;
            cout << left << setw(20) << c[i].getname() << setw(20) << c[i].getAccno() << endl;
        }
    }
    if (noOfSus == 0)
    {
        cout << "No details found!!" << endl;
    }
    else
    {
        cout << noOfSus << " number of suspicious account holders are found." << endl;
    }
    cout << string(60, '-') << endl;

    return 0;
}