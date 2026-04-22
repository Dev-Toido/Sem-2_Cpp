// Q1. Smart Loan Approval System
// 🧩 Story
// A bank evaluates loan eligibility using both credit score analysis and income verification.
// 🧬 Structure
// CreditAnalyzer + IncomeAnalyzer → LoanApproval

// 📦 Class Design
// 🔹 CreditAnalyzer
// Attributes:
// int creditScore
// Functions:
// void inputCredit()
// bool isCreditEligible()

// 🔹 IncomeAnalyzer
// Attributes:
// float monthlyIncome
// Functions:
// void inputIncome()
// bool isIncomeEligible()

// 🔹 LoanApproval
// Attributes:
// string status
// Functions:
// void evaluateLoan()
// void displayResult()

// 🎯 Tasks
// Approve loan only if both conditions are satisfied
// Display approval status
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Base Class 1: Credit Analysis Logic
class CreditAnalyzer {
protected:
    int creditScore;

public:
    void inputCredit() {
        cout << "Enter Credit Score (300-850): ";
        cin >> creditScore;
    } 

    bool isCreditEligible() {
        // Banks usually look for a score of 700 or higher
        return (creditScore >= 700);
    }
};

// Base Class 2: Income Verification Logic
class IncomeAnalyzer {
protected:
    float monthlyIncome;

public:
    void inputIncome() {
        cout << "Enter Monthly Income: Rs";
        cin >> monthlyIncome;
    }

    bool isIncomeEligible() {
        // Minimum requirement: Rs3000 per month
        return (monthlyIncome >= 3000.0);
    }
};

// Derived Class: Inherits from BOTH classes
class LoanApproval : public CreditAnalyzer, public IncomeAnalyzer {
private:
    string status;

public:
    void evaluateLoan() {
        // Logic: Both conditions MUST be true
        if (isCreditEligible() && isIncomeEligible()) {
            status = "APPROVED";
        } else {
            status = "REJECTED";
        }
    }

    void displayResult() {
        cout << "\n================================" << endl;
        cout << "       LOAN DECISION REPORT      " << endl;
        cout << "================================" << endl;
        cout << "Credit Score   : " << creditScore 
             << (isCreditEligible() ? " [PASS]" : " [FAIL]") << endl;
        
        cout << "Monthly Income : Rs" << fixed << setprecision(2) << monthlyIncome 
             << (isIncomeEligible() ? " [PASS]" : " [FAIL]") << endl;
        
        cout << "--------------------------------" << endl;
        cout << "FINAL STATUS   : " << status << endl;
        cout << "================================" << endl;

        if (status == "REJECTED") {
            cout << "Reason: Does not meet minimum credit or income criteria." << endl;
        } else {
            cout << "Congratulations! Your loan is being processed." << endl;
        }
    }
};

int main() {
    LoanApproval myLoan;

    // Gathering data from the inherited functions
    myLoan.inputCredit();
    myLoan.inputIncome();

    // Processing the combined logic
    myLoan.evaluateLoan();

    // Showing final output
    myLoan.displayResult();

    return 0;
}