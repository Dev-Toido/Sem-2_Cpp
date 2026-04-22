// Q12. . Building Lift Load Control System
// An elevator must restrict weight for safety.
// Requirements:
//     Create class Lift.
//         Private:
//             maxLoad
//             currentLoad
//         Public:
//             addPassenger(weight)
//             removePassenger(weight)
//             checkOverload()
//         Conditions:
//             Load must not exceed max
//             Load cannot be negative
#include <iostream>
using namespace std;

class Lift
{
private:
    int maxLoad;
    int currentLoad;

public:
    Lift(int max) : maxLoad(max), currentLoad(0) {}
    void addPassenger(int weight)
    {
        int w;
        cout << "Enter the weight to add: ";
        cin >> w;

        if (w + currentLoad > maxLoad)
        {
            cout << "Sorry, the weight to be added is too much to add as it exceeds the max limit!" << endl;
        }
        else
        {
            currentLoad += w;
            cout << "The weight is increased!" << endl;
        }
    }
    void removePassenger(int weight)
    {
        int w;
        cout << "Enter the weight to remove: ";
        cin >> w;

        if (currentLoad - w < 0)
        {
            currentLoad = 0;
            cout << "All weight has been removed!" << endl;
        }
        else
        {
            currentLoad -= w;
            cout << "The weight is reduced!" << endl;
        }
    }
    void checkOverload()
    {
        if (currentLoad > maxLoad)
        {
            cout << "The lift is currently going on overload!!" << endl;
        }
        else
        {
            cout << "No overload!" << endl;
        }
    }
};

int main()
{
    Lift l1(15);
    l1.checkOverload();
    l1.addPassenger(12);
    l1.removePassenger(15);
    l1.removePassenger(10);

    return 0;
}