// Q4. Hotel Room Booking System
// Story:
//  A hotel calculates room charges based on different booking details.
// Class: HotelBooking
// Attributes:
// guestName
// roomType
// Member Functions (Overloaded):
// calculate(int days)
// calculate(int days, string roomType)
// calculate(int days, string roomType, bool includeFood)
// 👉 Task:
// Compute total stay cost
// Add food charges if applicable 

#include <iostream>
#include <string>

using namespace std;

class HotelBooking {
private:
    string guestName;
    string roomType;
    const int standardRate = 1500;
    const int luxuryRate = 3500;
    const int foodChargePerDay = 500;

public:
    // Constructor to initialize guest name
    HotelBooking(string name) {
        guestName = name;
    }

    // 1. Basic calculation: Standard room, no extra details
    void calculate(int days) {
        int total = days * standardRate;
        cout << "\n--- Booking for: " << guestName << " ---" << endl;
        cout << "Room Type  : Standard (Default)" << endl;
        cout << "Stay Duration: " << days << " days" << endl;
        cout << "Total Cost : " << total << endl;
    }

    // 2. Overloaded calculation: Specific room type
    void calculate(int days, string type) {
        roomType = type;
        int rate = (roomType == "Luxury") ? luxuryRate : standardRate;
        int total = days * rate;

        cout << "\n--- Booking for: " << guestName << " ---" << endl;
        cout << "Room Type  : " << roomType << endl;
        cout << "Stay Duration: " << days << " days" << endl;
        cout << "Total Cost : " << total << endl;
    }

    // 3. Overloaded calculation: Specific room type + Food inclusion
    void calculate(int days, string type, bool includeFood) {
        roomType = type;
        int rate = (roomType == "Luxury") ? luxuryRate : standardRate;
        int roomCost = days * rate;
        int foodCost = includeFood ? (days * foodChargePerDay) : 0;
        int total = roomCost + foodCost;

        cout << "\n--- Booking for: " << guestName << " ---" << endl;
        cout << "Room Type  : " << roomType << endl;
        cout << "Stay Duration: " << days << " days" << endl;
        cout << "Food Include: " << (includeFood ? "Yes" : "No") << endl;
        cout << "Total Cost : " << total << " (Room: " << roomCost << " + Food: " << foodCost << ")" << endl;
    }
};

int main() {
    cout << "===== Grand Heritage Hotel Booking System =====" << endl;

    // Guest 1: Quick basic booking
    HotelBooking guest1("Rahul");
    guest1.calculate(2);

    // Guest 2: Specific room type
    HotelBooking guest2("Priya");
    guest2.calculate(3, "Luxury");

    // Guest 3: All-inclusive booking
    HotelBooking guest3("Vivek");
    guest3.calculate(2, "Luxury", true);

    cout << "\n===============================================" << endl;

    return 0;
}