// Q4. Smart Report Generator System
// 🧩 Story
// A system generates different types of reports.
// 🧬 Structure
// Report → PDFReport, ExcelReport, DashboardReport

// 📦 Class Design
// 🔹 Report
// Functions:
// virtual void generate()

// 🔹 Derived Classes
// Override generate()

// 🎯 Tasks
// Generate report dynamically
// Use base pointer
#include <iostream>
#include <string>

using namespace std;

// Base Class: Report
class Report {
public:
    // Virtual function to enable dynamic dispatch
    virtual void generate() {
        cout << "Generating standard report..." << endl;
    }

    // Virtual destructor for safe memory management
    virtual ~Report() {}
};

// Derived Class 1: PDF Report
class PDFReport : public Report {
public:
    void generate() override {
        cout << "[PDF REPORT] >>> Processing Document..." << endl;
        cout << "System: Setting page orientation and embedding fonts." << endl;
        cout << "Output: report_v1.pdf generated successfully." << endl;
        cout << "---------------------------------------------" << endl;
    }
};

// Derived Class 2: Excel Report
class ExcelReport : public Report {
public:
    void generate() override {
        cout << "[EXCEL REPORT] >>> Creating Workbook..." << endl;
        cout << "System: Formatting cells and applying data filters." << endl;
        cout << "Output: data_summary.xlsx exported successfully." << endl;
        cout << "---------------------------------------------" << endl;
    }
};

// Derived Class 3: Dashboard Report
class DashboardReport : public Report {
public:
    void generate() override {
        cout << "[DASHBOARD] >>> Initializing UI Widgets..." << endl;
        cout << "System: Connecting to live API for real-time charts." << endl;
        cout << "Output: Web Dashboard rendered on screen." << endl;
        cout << "---------------------------------------------" << endl;
    }
};

int main() {
    // Declaring the base class pointer
    Report* reportPtr = nullptr;
    int choice;

    cout << "--- Smart Report Generator ---" << endl;
    cout << "Select Report Type: \n1. PDF\n2. Excel\n3. Dashboard\nChoice: ";
    cin >> choice;

    // Dynamically assigning the derived object to the base pointer
    switch (choice) {
        case 1:
            reportPtr = new PDFReport();
            break;
        case 2:
            reportPtr = new ExcelReport();
            break;
        case 3:
            reportPtr = new DashboardReport();
            break;
        default:
            cout << "Invalid choice! Defaulting to generic report." << endl;
            reportPtr = new Report();
    }

    // Dynamic Binding: The correct 'generate' is called based on user choice
    cout << "\nAction Started:" << endl;
    reportPtr->generate();

    // Cleaning up the dynamically allocated memory
    delete reportPtr;

    return 0;
}