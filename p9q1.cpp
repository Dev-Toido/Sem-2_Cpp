// Q1. Smart Farming Monitoring System
// A company builds a smart farming system. The base class Sensor stores sensor ID and location. A derived class SoilSensor measures moisture level and fertility index.
// 👉 Task:
//     Implement the Sensor class with:
//         Input method
//         Display method
//     Derive a class SoilSensor from Sensor
//     Add a method checkSoilSuitability() that:
//     Determines if soil is suitable based on:
//         Moisture Level between 40%–70%
//         Fertility Index ≥ 50
//     If not suitable, suggest improvements such as:
//         Irrigation
//         Drainage
//         Fertilizer usage
//     Create a method displayReport() that shows:
//         Sensor details
//         Soil readings
//         Suitability result
//         Suggestions (if any)
//         moistureLevel → Percentage of water in soil (0–100%)
//         fertilityIndex → Soil fertility score (0–100)
#include <iostream>
#include <string>

using namespace std;

// Base class
class Sensor {
protected:
    int sensorID;
    string location;

public:
    void input() {
        cout << "Enter Sensor ID: ";
        cin >> sensorID;
        cin.ignore(); 
        cout << "Enter Location: ";
        getline(cin, location);
    }

    void display() {
        cout << "\n--- Sensor Details ---" << endl;
        cout << "Sensor ID: " << sensorID << endl;
        cout << "Location : " << location << endl;
    }
};

// Derived class
class SoilSensor : public Sensor {
private:
    float moistureLevel;
    float fertilityIndex;
    string suggestions; 
    bool isSuitable;

public:
    void inputSoilData() {
        input(); // Call base class method
        cout << "Enter Moisture Level (0-100%): ";
        cin >> moistureLevel;
        cout << "Enter Fertility Index (0-100): ";
        cin >> fertilityIndex;
    }

    void checkSoilSuitability() {
        isSuitable = true;
        suggestions = ""; // Clear suggestions before checking

        // Moisture Level Check
        if (moistureLevel < 40) {
            suggestions += "- Suggestion: Start Irrigation (Soil too dry)\n";
            isSuitable = false;
        } else if (moistureLevel > 70) {
            suggestions += "- Suggestion: Improve Drainage (Waterlogged)\n";
            isSuitable = false;
        }

        // Fertility Index Check
        if (fertilityIndex < 50) {
            suggestions += "- Suggestion: Use Fertilizer (Nutrient deficiency)\n";
            isSuitable = false;
        }
    }

    void displayReport() {
        display(); // Display base sensor details

        cout << "\n--- Soil Readings ---" << endl;
        cout << "Moisture Level : " << moistureLevel << "%" << endl;
        cout << "Fertility Index: " << fertilityIndex << endl;

        cout << "\n--- Suitability Result ---" << endl;
        if (isSuitable) {
            cout << "Result: Soil is SUITABLE for farming." << endl;
        } else {
            cout << "Result: Soil is NOT SUITABLE." << endl;
            cout << "Improvements needed:\n" << suggestions;
        }
        cout << "---------------------------\n" << endl;
    }
};

int main() {
    SoilSensor mySensor;

    cout << "===== Smart Farm Input =====" << endl;
    mySensor.inputSoilData();
    mySensor.checkSoilSuitability();
    mySensor.displayReport();

    return 0;
}