// Q1. Rocket Launch Authorization System
// Story:
// A space research center is developing a rocket launch control system.
//  Critical launch parameters must be protected from direct modification.
// Requirements:
// Create class Rocket.
// Private data members:
// rocketID
// fuelLevel (0–100)
// launchCode
// isLaunched (bool)

// Public functions:
// Constructor to initialize rocket
// refuel(int amount)
// setLaunchCode(string code)
// launch(string enteredCode)
// getStatus()

// Conditions:
// Launch allowed only if fuelLevel ≥ 80
// Launch code must match
// Rocket cannot launch twice
// Fuel cannot exceed 100

// 👉 Focus: Protect launchCode & fuelLevel

#include <iostream>
#include <iomanip>
using namespace std;

class Rocket
{
private:
    int rocketID;
    int fuelCapacity;
    int fuelFilled;
    int fuelLevel;
    string launchCode;
    bool isLaunched;

public:
    Rocket(int rID, int fCapacity)
    {
        rocketID = rID;
        fuelCapacity = fCapacity;
        fuelFilled = 0;
        isLaunched = false;
        fuelLevel = 0;
        launchCode = "";
    }

    void refuel(int amount)
    {
        cout << "The Fuel Level is " << fuelLevel << endl;
        if (amount + fuelFilled > fuelCapacity)
        {

            cout << "The Fuel Tank is fully filled and " << (amount + fuelFilled) - fuelCapacity << " L is extra" << endl;
            fuelFilled = fuelCapacity;
        }
        else
        {
            fuelFilled += amount;
            cout << "The Fuel Tank is filled " << endl;
        }
        fuelLevel = (float(fuelFilled) / fuelCapacity) * 100;
        cout << "Fuel Level after refueling: " << fuelLevel << " %" << endl;
    }
    void setLaunchCode(string code)
    {
        launchCode = code;
        cout << "The launch code is updated!!" << endl;
    }
    bool isLaunchCodeSet()
    {
        return launchCode != "";
    }
    bool launch(string enteredCode)
    {
        if (!isLaunched)
        {
            if (enteredCode == launchCode)
            {
                isLaunched = true;
                cout << "Rocket Launch in 3... 2... 1... , Sucessfully launched!!" << endl;
                return true;
            }
            else
            {
                cout << "The entered Launch Code is wrong, please check it and try again!!" << endl;
            }
        }
        else
        {
            cout << "Rocket Already launched!!" << endl;
        }
        return false;
    }
    void getStatus()
    {
        if (isLaunched)
        {
            cout << "The rocket is launched!" << endl;
        }
        else
        {
            cout << "The rocket's fuel level is " << fuelLevel << " %" << endl;
            if (fuelLevel >= 80)
            {
                cout << "The rocket is ready to launch" << endl;
            }
            else
            {
                cout << "The rocket is not ready to launch as the fuel level is less than 80%" << endl;
            }
        }
        cout << "The Rocket Launch Code is " << ((isLaunchCodeSet()) ? "" : "not") << " setted." << endl;
    }
};

int main()
{
    int rid;
    int fuelCap;
    string lcode;
    cout << string(20, ' ') << "Welcome to The Rocket Mangement System!!" << endl;
    cout << "Enter the Rocket ID: ";
    cin >> rid;
    cout << "Enter the Rocket fuel capacity (in Liters) : ";
    cin >> fuelCap;

    Rocket robj(rid, fuelCap);

    int ch;
    do
    {
        cout << "Enter your choice to continue: \n1. Get Rocket Details\n2. Refuel the rocket\n3. Set/Reset the Launch Code\n4. Launch The rocket\n0. Exit" << endl;
        cout << "Enter: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            robj.getStatus();
            break;
        case 2:
            int famt;
            cout << "Enter the Amount of fuel to be filled (in Liters): ";
            cin >> famt;
            robj.refuel(famt);
            break;
        case 3:
            cout << "Be carefully you are going to " << ((!robj.isLaunchCodeSet()) ? "" : "re") << "set the launch code!! " << endl;
            cout << "Enter the launch Code: ";
            cin >> lcode;
            robj.setLaunchCode(lcode);
            break;
        case 4:
            if (!robj.isLaunchCodeSet())
            {
                cout << "Before launch please set the launch code!!" << endl;
                break;
            }
            cout << "Be carefully you are going to set the rocket to launch by entering code!! " << endl;
            cout << "Enter the launch Code: ";
            cin >> lcode;
            robj.launch(lcode);
            break;
        case 0:
            break;
        default:
            cout << "Wrong input!! Please enter the right input" << endl;
            break;
        }
    } while (ch);

    cout << "Thanks You for using the Rocket Management System!" << endl;
    return 0;
}