// Q10.  ICU Patient Oxygen Monitoring
// An ICU system monitors oxygen levels of patients. Incorrect modification may risk life.
// Requirements:
// Create class OxygenMonitor.
// Private:
// patientID
// oxygenLevel (0–100)
// Public:
// setOxygenLevel()
// increaseOxygen()
// decreaseOxygen()
// checkCriticalLevel()
// Conditions:

// Level must stay between 0–100
// Alert if below 40

#include <iostream>
using namespace std;

class OxygenMonitor
{
private:
    int patientID;
    int oxygenLevel; //(0–100)

public:
    OxygenMonitor(int pid)
    {
        patientID = pid;
        oxygenLevel = 0;
    }
    void setOxygenLevel(int n)
    {
        cout << "The Oxygen Level is : " << n << endl;
    }
    void increaseOxygen(int n, int m)
    {
        if (n < m)
        {
            cout << "The oxygen level is increase" << endl;
        }
    }
    void decreaseOxygen(int n, int m)
    {
        if (n > m)
        {
            cout << "The oxygen level is decrease" << endl;
        }
    }
    void checkCriticalLevel(int m)
    {
        if (m < 0)
        {
            cout << "The oxygen level is critical" << endl;
        }
    }
};

int main()
{
    int n;
    int m;
    OxygenMonitor user1(123);
    cout << "Enter The Oxygen Level : ";
    cin >> n;
    user1.setOxygenLevel(n);
    cout << "Enter The Oxygen Level After Sometime : ";
    cin >> m;
    user1.increaseOxygen(n, m);
    user1.decreaseOxygen(n, m);
    user1.checkCriticalLevel(m);

    return 0;
}