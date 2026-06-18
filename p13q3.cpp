// Q3. Car Engine Access System
// Story:
//  A car engine’s details are private, but a mechanic class should access it for servicing.
// Class 1: Engine
//  Attributes (Private):
// engineNumber
// horsepower
// Class 2: Mechanic
// Friend Class:
// Mechanic is friend of Engine
// 👉 Task:
// Mechanic accesses and displays engine details
#include <iostream>
#include <string>

using namespace std;


class Mechanic;

class Engine {
private:
    string engineNumber;
    int horsepower;

public:
    // Constructor
    Engine(string num, int hp) {
        engineNumber = num;
        horsepower = hp;
    }

    // Declaring the entire Mechanic class as a friend
    friend class Mechanic;
};

class Mechanic {
public:
    // This function can access private members of Engine because Mechanic is a friend
    void displayEngineDetails(Engine &e) {
        cout << "--- Mechanic's Service Report ---" << endl;
        cout << "Accessing Engine Data..." << endl;
        cout << "Engine Number : " << e.engineNumber << endl;
        cout << "Horsepower    : " << e.horsepower << " HP" << endl;
        cout << "Service Status: Diagnostics Complete" << endl;
        cout << "---------------------------------" << endl;
    }
};

int main() {
    // Creating an Engine object with private details
    Engine myCarEngine("V8-7721-XYZ", 450);

    // Creating a Mechanic object
    Mechanic masterMechanic;

    // The mechanic accesses the engine details
    masterMechanic.displayEngineDetails(myCarEngine);

    return 0;
}