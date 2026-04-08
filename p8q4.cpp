// Q4. Factory Machine Temperature Control
//     Story:
//         Industrial machines must maintain safe temperature levels.
//     Requirements:
//         Create class Machine.
//             Private:
//                 machineID
//                 temperature
//                 maxTemperature
//             Public:
//                 setMaxTemperature()
//                 increaseTemperature()
//                 decreaseTemperature()
//                 getTemperature()
//             Conditions:
//                 Temperature must not exceed maxTemperature
//                 Temperature cannot go below 0
//                 Display warning when unsafe

#include <iostream>
using namespace std;
class Machine
{
private:
    int machineID;
    float temperature;
    float maxTemperature;

public:
    Machine(int mid) : machineID(mid), temperature(0), maxTemperature(0) {}
    void setMaxTemperature()
    {
        cout << "Enter the max temperature to set(in C): ";
        cin >> maxTemperature;
        cout << "The max temperature is sucessfully set!!" << endl;
    }
    void increaseTemperature()
    {
        float temp;
        cout << "Enter the temperature to increase(in C): ";
        cin >> temp;
        if (temp + temperature > maxTemperature)
        {
            cout << "The Temperature will be more than the max temperature which machine can handle! Cann't increase temperature!" << endl;
        }
        else
        {
            temperature += temp;
            cout << "The temperature is sucessfully increased!!" << endl;
        }
    }
    void decreaseTemperature()
    {
        float temp;
        cout << "Enter the temperature to decrease(in C): ";
        cin >> temp;
        if (temperature-temp <0)
        {
            cout << "The Temperature will be zero! Cann't decrease temperature!" << endl;
        }
        else
        {
            temperature -= temp;
            cout << "The temperature is sucessfully decreased!!" << endl;
        }
    }
    void getTemperature() {
        cout<<"The temperature is "<<temperature<<endl;
    }
};
int main()
{
    Machine m1(123);
    m1.getTemperature();
    m1.setMaxTemperature();
    m1.decreaseTemperature();
    m1.increaseTemperature();
    m1.increaseTemperature();
    m1.decreaseTemperature();
    m1.getTemperature();

    return 0;
}