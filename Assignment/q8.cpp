// Q8. Ride Fare Calculation System
// A ride-sharing service calculates fares based on distance and base price. The final fare should not be directly editable.
// Requirements:
//     Create class Ride.
//         Private members:
//             driverName
//             distanceTravelled
//             fare
//         Public functions:
//             startRide()
//             endRide(distance)
//             calculateFare()
//             getFare()
//         Conditions:
//             Distance must be positive
//             Fare calculated internally
#include <iostream>
using namespace std;

class Ride
{
private:
    string driverName;
    int distanceTravelled;
    int fare;

public:
    void startRide()
    {
        cout << "Enter the name of the driver: ";
        cin >> driverName;
        cout << "Enter the Base Fare(fare/km) (in Rs):";
        cin >> fare;
        distanceTravelled = 0;
    }
    void endRide(int distance)
    {
        cout << "Thank you for riding!!" << endl;
        distanceTravelled = distance;
        calculateFare();
        getFare();
    }
    void calculateFare()
    {
        fare *= distanceTravelled;
    }
    void getFare()
    {
        cout << "The fare for the ride is Rs " << fare << endl;
    }
};

int main()
{
    Ride r1;
    int dist = 0;
    r1.startRide();
    do
    {
        cout << "Enter the distance(we know distance is positive number) (in km): ";
        cin >> dist;
    } while (dist < 0);
    r1.endRide(dist);

    return 0;
}