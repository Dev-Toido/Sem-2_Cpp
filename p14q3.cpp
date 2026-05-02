// Q3. Employee Record System (Text File)
// Create class Employee:
// id, name, salary
// Store records in file
// Display all records
// Search by id number
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Employee {
public:
    int id;
    string name;
    double salary;

    // Function to get data from user
    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore(); // Clear buffer
        getline(cin, name);
        cout << "Enter Salary: ";
        cin >> salary;
    }

    // Function to display data in a table format
    void display() {
        cout << left << setw(10) << id 
             << setw(20) << name 
             << "Rs" << fixed << setprecision(2) << salary << endl;
    }
};

// Function to store record in file
void addRecord() {
    Employee e;
    e.input();

    ofstream outFile("employees.txt", ios::app); // Open in append mode
    if (outFile) {
        outFile << e.id << " " << e.name << " " << e.salary << endl;
        outFile.close();
        cout << "Record saved successfully!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}

// Function to display all records
void displayAll() {
    Employee e;
    ifstream inFile("employees.txt");
    
    if (!inFile) {
        cout << "No records found (file does not exist)." << endl;
        return;
    }

    cout << "\n--- Employee Records ---" << endl;
    cout << left << setw(10) << "ID" << setw(20) << "Name" << "Salary" << endl;
    cout << "------------------------------------------" << endl;

    // Read until end of file
    while (inFile >> e.id >> e.name >> e.salary) {
        e.display();
    }
    inFile.close();
}

// Function to search by ID
void searchById(int searchId) {
    Employee e;
    ifstream inFile("employees.txt");
    bool found = false;

    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (inFile >> e.id >> e.name >> e.salary) {
        if (e.id == searchId) {
            cout << "\nRecord Found:" << endl;
            e.display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nEmployee with ID " << searchId << " not found." << endl;
    }
    inFile.close();
}

int main() {
    int choice, id;

    do {
        cout << "\n1. Add Employee\n2. Display All\n3. Search by ID\n4. Exit\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addRecord(); break;
            case 2: displayAll(); break;
            case 3:
                cout << "Enter ID to search: ";
                cin >> id;
                searchById(id);
                break;
            case 4: cout << "Exiting..."; break;
            default: cout << "Invalid choice!";
        }
    } while (choice != 4);

    return 0;
}