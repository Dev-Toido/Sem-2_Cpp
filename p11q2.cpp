// Q2 . Constructor Overloading (Advanced)
// Scenario:
//  Initialize objects in different ways.
// Class: Employee
// Attributes:
// id
// name
// salary
// Constructors (Overloaded):
// Default constructor
// Constructor with id, name
// Constructor with id, name, salary
// 👉 Task:
// Create multiple objects using different constructors
#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int id;
    string name;
    double salary;

public:
    // 1. Default Constructor
    // Used when no information is provided
    Employee() {
        id = 0;
        name = "Guest/Trainee";
        salary = 0.0;
        cout << "[System] Default constructor triggered." << endl;
    }

    // 2. Overloaded Constructor (ID and Name)
    // Used for new hires where salary isn't fixed yet
    Employee(int i, string n) {
        id = i;
        name = n;
        salary = 0.0; 
        cout << "[System] 2-Parameter constructor triggered for: " << name << endl;
    }

    // 3. Overloaded Constructor (ID, Name, and Salary)
    // Used for full-time employees with all details
    Employee(int i, string n, double s) {
        id = i;
        name = n;
        salary = s;
        cout << "[System] 3-Parameter constructor triggered for: " << name << endl;
    }

    void display() {
        cout << "ID    : " << id << endl;
        cout << "Name  : " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    cout << "===== Initializing Employee Database =====" << endl;

    // Creating objects using different constructors
    Employee emp1;                          // Calls Default
    Employee emp2(101, "Aryan");            // Calls (int, string)
    Employee emp3(102, "Sneha", 55000.50);  // Calls (int, string, double)

    cout << "\n========== EMPLOYEE RECORDS ==========" << endl;
    emp1.display();
    emp2.display();
    emp3.display();

    return 0;
}