// Q1. Distance Addition System
// Story:
//  A system stores distances in two different objects and needs to calculate total distance.
// Class: Distance
// Attributes (Private):
// meters
// centimeters
// Friend Function:
// addDistance(Distance d1, Distance d2)
// 👉 Task:
// Add two distances
// Convert extra centimeters into meters
// Display result 
#include <iostream>

using namespace std;

class Distance {
private:
    int meters;
    int centimeters;

public:
    // Constructor to initialize distance
    Distance(int m = 0, int cm = 0) {
        meters = m;
        centimeters = cm;
    }

    // Declaration of friend function
    friend void addDistance(Distance d1, Distance d2);
};

// Definition of the friend function
void addDistance(Distance d1, Distance d2) {
    int totalMeters = d1.meters + d2.meters;
    int totalCentimeters = d1.centimeters + d2.centimeters;

    // Convert extra centimeters into meters (100 cm = 1 meter)
    if (totalCentimeters >= 100) {
        totalMeters += (totalCentimeters / 100);
        totalCentimeters = totalCentimeters % 100;
    }

    cout << "Total Distance: " << totalMeters << " m, " << totalCentimeters << " cm" << endl;
    cout << "------------------------------------" << endl;
}

int main() {
    // Creating two distance objects
    // Example: 5 meters 80 cm and 3 meters 50 cm
    Distance d1(5, 80);
    Distance d2(3, 50);

    cout << "Adding Distances..." << endl;
    
    // Calling the friend function
    addDistance(d1, d2);

    return 0;
}