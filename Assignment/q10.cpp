// Q10.  ICU Patient Oxygen Monitoring
// An ICU system monitors oxygen levels of patients. Incorrect modification may risk life.
// Requirements:
//     Create class OxygenMonitor.
//         Private:
//             patientID
//             oxygenLevel (0–100)
//         Public:
//             setOxygenLevel()
//             increaseOxygen()
//             decreaseOxygen()
//             checkCriticalLevel()
//         Conditions:
//             Level must stay between 0–100
//             Alert if below 40
#include <iostream>
using namespace std;

class OxygenMonitor
{
private:
    int patientID;
    int oxygenLevel;

public:
    OxygenMonitor(int pid) : patientID(pid), oxygenLevel(0) {}
    void setOxygenLevel()
    {
        do
        {
            cout << "Enter the oxygen level(0-100): ";
            cin >> oxygenLevel;
        } while (oxygenLevel > 100 || oxygenLevel < 0);
        cout << "The oxygen levels are updated!!" << endl;
    }
    void increaseOxygen()
    {
        int ox = 0;
        cout << "Enter the amount of oxygen level to increase:";
        cin >> ox;
        if (ox + oxygenLevel > 100)
        {
            oxygenLevel = 100;
            cout << "The oxygen level is set to full!" << endl;
        }
        else
        {
            oxygenLevel += ox;
            cout << "The oxygen level is updated!" << endl;
        }
        if (checkCriticalLevel())
        {
            cout << "The oxygen levels are below 40!!!" << endl;
        }
    }
    void decreaseOxygen()
    {
        int ox = 0;
        cout << "Enter the amount of oxygen level to decrease:";
        cin >> ox;
        if (oxygenLevel - ox < 0)
        {
            oxygenLevel = 0;
            cout << "The oxygen level is zero!" << endl;
        }
        else
        {
            oxygenLevel -= ox;
            cout << "The oxygen level is updated!" << endl;
        }
        if (checkCriticalLevel())
        {
            cout << "The oxygen levels are below 40!!!" << endl;
        }
    }
    bool checkCriticalLevel()
    {
        return oxygenLevel < 40;
    }
};
int main()
{
    OxygenMonitor m1(123);
    m1.setOxygenLevel();
    m1.increaseOxygen();
    m1.decreaseOxygen();
    return 0;
}