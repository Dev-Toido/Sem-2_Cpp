// Q3. Smart City Pollution Monitoring System
// 🧩 Story
// A city monitors pollution using air quality sensors and traffic density sensors, combining both to determine pollution severity.
// 🧬 Structure
// Sensor → AirSensor, TrafficSensor → PollutionAnalyzer

// 📦 Class Design
// 🔹 Sensor
// Attributes:
// int sensorID
// Functions:
// void inputSensor()

// 🔹 AirSensor
// Attributes:
// int AQI
// Functions:
// void inputAir()
// bool isAirPolluted()

// 🔹 TrafficSensor
// Attributes:
// int vehicleCount
// Functions:
// void inputTraffic()
// bool isTrafficHigh()

// 🔹 PollutionAnalyzer
// Attributes:
// string pollutionLevel
// Functions:
// void analyzePollution()
// void displayStatus()

// 🎯 Tasks
// Classify pollution:
// Low / Moderate / High
// Suggest preventive measures
#include <iostream>
#include <string>

using namespace std;

// Base Class
class Sensor {
protected:
    int sensorID;

public:
    void inputSensor() {
        cout << "Enter Sensor ID: ";
        cin >> sensorID;
    }
};

// Derived Class 1 (Virtual Inheritance to prevent Diamond Problem)
class AirSensor : virtual public Sensor {
protected:
    int AQI;

public:
    void inputAir() {
        cout << "Enter Air Quality Index (AQI): ";
        cin >> AQI;
    }

    bool isAirPolluted() {
        return (AQI > 100);
    }
};

// Derived Class 2 (Virtual Inheritance)
class TrafficSensor : virtual public Sensor {
protected:
    int vehicleCount;

public:
    void inputTraffic() {
        cout << "Enter Vehicle Count (per hour): ";
        cin >> vehicleCount;
    }

    bool isTrafficHigh() {
        return (vehicleCount > 100);
    }
};

// Combined Derived Class: Hybrid Inheritance
class PollutionAnalyzer : public AirSensor, public TrafficSensor {
private:
    string pollutionLevel;
    string suggestion;

public:
    void analyzePollution() {
        bool air = isAirPolluted();
        bool traffic = isTrafficHigh();

        if (air && traffic) {
            pollutionLevel = "HIGH";
            suggestion = "Action: Implement odd-even rule and issue health advisory.";
        } else if (air || traffic) {
            pollutionLevel = "MODERATE";
            suggestion = "Action: Increase public transport frequency and monitor air filters.";
        } else {
            pollutionLevel = "LOW";
            suggestion = "Action: No immediate action required. Maintain green belts.";
        }
    }

    void displayStatus() {
        cout << "\n========== CITY POLLUTION REPORT ==========" << endl;
        cout << "Sensor ID      : " << sensorID << endl;
        cout << "AQI Level      : " << AQI << endl;
        cout << "Traffic Density: " << vehicleCount << " vehicles/hr" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "POLLUTION LEVEL: " << pollutionLevel << endl;
        cout << "SUGGESTION     : " << suggestion << endl;
        cout << "===========================================" << endl;
    }
};

int main() {
    PollutionAnalyzer cityA;

    cout << "--- Smart City Sensor Input ---" << endl;
    // Note: Since we used virtual inheritance, we can call inputSensor once
    cityA.inputSensor(); 
    cityA.inputAir();
    cityA.inputTraffic();

    cityA.analyzePollution();
    cityA.displayStatus();

    return 0;
}