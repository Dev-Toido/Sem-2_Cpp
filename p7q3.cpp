// Q3. Corporate Employee Evaluation System
// Story:
// A company evaluates employee performance based on yearly ratings.
// Requirements:
// Create class Employee.
// Employee ID
// Name
// Performance Score (0–100)

// Create array of objects.
// Display:

// Best performing employee
// Employees scoring below 50
// Average company performance score

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee
{
private:
    int eid;
    string ename;
    int perScore;

public:
    void copy(Employee &s)
    {
        eid = s.geteid();
        ename = s.getname();
        perScore = s.getpscore();
    }
    void seteid()
    {
        cout << left << setw(30) << "Employee ID: ";
        cin >> eid;
    }
    void setename()
    {
        cout << left << setw(30) << "Employee Name: ";
        cin.ignore();
        getline(cin, ename);
    }
    void setperscore()
    {
        cout << left << setw(30) << "Employee performance score: ";
        cin >> perScore;
        while (true)
        {
            if (0 <= perScore && perScore <= 100)
            {
                break;
            }
            else
            {
                cout << "Enter in a valid range 0-100!!" << endl;
                cin >> perScore;
            }
        }
    }

    int geteid()
    {
        return eid;
    }
    string getname()
    {
        return ename;
    }
    int getpscore()
    {
        return perScore;
    }
};

void initObj(Employee &ob)
{
    ob.seteid();
    ob.setename();
    ob.setperscore();
}

int main()
{
    int noOfEmployee;
    cout << "Enter the number of employees: ";
    cin >> noOfEmployee;
    Employee e[noOfEmployee];

    for (int i = 0; i < noOfEmployee; i++)
    {
        cout << "Enter the Details of " << i + 1 << " employee:-> " << endl;
        initObj(e[i]);
    }
    cout << string(60, '-') << endl;

    Employee bestE;
    bestE.copy(e[0]);

    for (int i = 1; i < noOfEmployee; i++)
    {
        if (e[i].getpscore() > bestE.getpscore())
        {
            bestE.copy(e[i]);
        }
    }
    cout << "Best performing employee is " << bestE.getname() << " with employee ID " << bestE.geteid() << endl;
    cout << string(60, '-') << endl;

    long int avgCompanyScore = 0;
    cout << "The Employees with performance score less than 50 are: " << endl;
    cout << left << setw(20) << ": Employee ID" << ":" << setw(30) << ": Name" << ":" << endl;
    for (int i = 0; i < noOfEmployee; i++)
    {
        avgCompanyScore += e[i].getpscore();
        if (e[i].getpscore() < 50)
        {
            cout << left << setw(20) << ": " + to_string(e[i].geteid()) << ":" << setw(30) << ": " + e[i].getname() << ":" << endl;
        }
    }
    cout << string(60, '-') << endl;

    avgCompanyScore /= noOfEmployee;
    cout << "Average Company Performance Score: " << avgCompanyScore << endl;
    return 0;
}