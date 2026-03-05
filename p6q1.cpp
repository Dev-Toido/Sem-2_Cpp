// Student Attendance Eligibility System
// Scenario:
// A college maintains attendance records of all students to ensure academic discipline. According to college rules, a student must have at least 75% attendance to be eligible to appear in the final examination.
// The college administration wants to develop a simple software system using C++ and Object-Oriented Programming concepts to store student attendance details, calculate attendance percentage, and determine exam eligibility.
// You are assigned the task of designing and implementing this system using classes, constructors, and object-based function calls.

// Requirements:
// Step 1: Class Creation
// Create a class named Attendance with the following private data members:
// Student Name (string)
// Total Number of Classes Conducted (integer)
// Number of Classes Attended (integer)
// Attendance Percentage (float)

// Step 2: Constructor Implementation
// Implement a parameterized constructor that initializes the student name, total classes, and attended classes when an object is created.

// Step 3: Member Functions
// Create the following public member functions:
// A function to calculate attendance percentage using the formula:
// Attendance Percentage = ( Attended Classes / Total Classes ) × 100
// A function to display student attendance details, including:
// Student Name
// Total Classes
// Attended Classes
// Attendance Percentage

// Getter function(s) if required to access the attendance percentage safely.

// Step 4: Object as Function Argument
// Create a separate function outside the class named checkEligibility that:
// Accepts an Attendance object as an argument
// Checks whether the student is eligible for examination
// Displays one of the following messages:
// "Student is eligible for the exam"
// "Student is NOT eligible for exam"
// Eligibility condition:
// Attendance Percentage ≥ 75%

// Step 5: Main Function Implementation
// In the main() function:
// Create at least two student objects using the constructor
// Display attendance details of both students
// Pass each object to the eligibility checking function
// Display the eligibility result for each student
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Attendance
{
private:
    string stuName;
    int totalClasses;
    int classesAttended;
    float attendancePercent;

public:
    Attendance()
    {
        string stuName = "";
        int totalClasses = 0;
        int classesAttended = 0;
        float attendancePercent = 0.0;
    }
    Attendance(string stuName, int totalClasses, int classesAttended) : stuName(stuName), totalClasses(totalClasses), classesAttended(classesAttended)
    {
        attendancePercent = (float(classesAttended) / totalClasses) * 100.0;
        cout << "The Student details are updated!!" << endl;
    }

    void displayDetails()
    {
        cout << left << setw(30) << "Student Name: " << stuName << endl;
        cout << left << setw(30) << "Total Number of classes: " << totalClasses << endl;
        cout << left << setw(30) << "Class Attended: " << classesAttended << endl;
        cout << left << setw(30) << "Attendance Percentage: " << attendancePercent << endl;
        cout << string(40, '-') << endl;
    }

    string getName()
    {
        return stuName;
    }
    float getAttendancePercent()
    {
        return attendancePercent;
    }
};

void checkEligibility(Attendance &s1)
{
    cout << s1.getName()<<" is " << ((s1.getAttendancePercent() >= 75) ? "" : "NOT") << " eligible for the exam." << endl;
}

Attendance attendanceObjectCreation()
{
    string stuName;
    int totalClasses;
    int classesAttended;
    float attendancePercent;

    cout << "Enter the student details: " << endl;
    cout << left << setw(30) << "Student Name: ";
    cin >> stuName;
    cout << left << setw(30) << "Total Number of classes: ";
    cin >> totalClasses;
    cout << left << setw(30) << "Class Attended: ";
    cin >> classesAttended;
    Attendance s(stuName, totalClasses, classesAttended);
   
    return s;
}

int main()
{
    int nStudents;
    cout << "Enter the number of students: ";
    cin >> nStudents;
    Attendance s[nStudents];
    cout << "You are going to enter the details of the students: " << endl;
    for (int i = 0; i < nStudents; i++)
    {
        s[i] = attendanceObjectCreation();
    }

    for (int i = 0; i < nStudents; i++)
    {
        checkEligibility(s[i]);
    }

    return 0;
}