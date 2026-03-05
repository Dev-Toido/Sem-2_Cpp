// Q2 . Scholarship Eligibility System
// Story: A university wants to determine scholarship eligibility among 10 students.
// Requirements:
// Create class Student.
// Name
// CGPA
// Create array of objects.
// Display:
// Students eligible (CGPA ≥ 8.0)
// Highest CGPA student
// Total eligible students

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student
{
private:
    string stuName;
    float cgpa;

public:
    Student()
    {
        stuName = "";
        cgpa = 0;
    }
    void copy(Student &s)
    {
        stuName = s.getName();
        cgpa = s.getCgpa();
    }
    float getCgpa()
    {
        return cgpa;
    }
    void setName()
    {
        cout << "Enter Student name: ";
        cin >> stuName;
    }
    string getName()
    {
        return stuName;
    }
    void setCgpa()
    {
        cout << "Enter the CGPA of the student: ";
        cin >> cgpa;
    }
};

void stuObjectInit(Student &s)
{
    s.setName();
    s.setCgpa();
}

bool isEligible(Student &s)
{
    
    if (s.getCgpa() >= 8.0){
    cout << "The Student is " << s.getName() << "eligible for scholarship" << endl;
        return 1;}
    else
        return 0;
}

int main()
{
    int noOfStudents, noOfEligibleStu = 0;
    cout << "Enter the number of students: ";
    cin >> noOfStudents;
    Student s[noOfStudents];

    for (int i = 0; i < noOfStudents; i++)
    {
        stuObjectInit(s[i]);
    }

    for (int i = 0; i < noOfStudents; i++)
    {
        if (isEligible(s[i]))
            noOfEligibleStu++;
    }

    Student topper;
    for (int i = 0; i < noOfStudents; i++)
    {
        if (s[i].getCgpa() > topper.getCgpa())
        {
            topper.copy(s[i]);
        }
    }

    cout << "The student with highest CGPA is\nName: " << topper.getName() << endl
         << "CGPA: " << topper.getCgpa() << endl;

    cout << "Total eligible student for scholarship: " << noOfEligibleStu << endl;

    return 0;
}