// Q4. Smart Disaster Alert System
// 🧩 Story
// A government disaster management agency is building an AI-based system to monitor environmental conditions and predict floods in real time. The system collects raw sensor data, processes weather conditions, and finally predicts flood risk.
// 🧬 Inheritance Hierarchy
// Sensor → WeatherSensor → FloodSensor

// 📌 System Description
// Sensor (Base Class):
// Stores sensorID, location
// Handles basic input and display
// WeatherSensor (Derived Level 1):
// Stores rainfall (mm) and humidity (%)
// Processes environmental data
// FloodSensor (Derived Level 2):
// Analyzes flood risk using:
// Rainfall > 100 mm
// Humidity > 80%
// Generates alert level:
// Low → Normal conditions
// Medium → One condition true
// High → Both conditions true

// 🎯 Tasks
// Implement all three classes using multilevel inheritance
// Accept input for sensor and weather data
// Implement flood prediction logic
// Display a detailed disaster report including:
// Sensor details
// Weather data
// Flood alert level
// Add condition:
// If alert is High, print: "Immediate evacuation required"

// ⚙️ Constraints
// Rainfall range: 0 – 500 mm
// Humidity range: 0 – 100%
// Handle invalid input 
#include <iostream>
#include <string>

using namespace std;

// Base Class: Sensor
class Sensor {
protected:
    int sensorID;
    string location;

public:
    void inputSensor() {
        cout << "Enter Sensor ID: ";
        cin >> sensorID;
        cin.ignore();
        cout << "Enter Location: ";
        getline(cin, location);
    }

    void displaySensor() {
        cout << "Sensor ID      : " << sensorID << endl;
        cout << "Location       : " << location << endl;
    }
};

// Derived Level 1: WeatherSensor
class WeatherSensor : public Sensor {
protected:
    float rainfall; // 0 - 500 mm
    float humidity; // 0 - 100%

public:
    void inputWeather() {
        inputSensor();
        
        // Input validation for Rainfall
        do {
            cout << "Enter Rainfall (0-500 mm): ";
            cin >> rainfall;
            if (rainfall < 0 || rainfall > 500) 
                cout << "[Error] Please enter a value between 0 and 500." << endl;
        } while (rainfall < 0 || rainfall > 500);

        // Input validation for Humidity
        do {
            cout << "Enter Humidity (0-100%): ";
            cin >> humidity;
            if (humidity < 0 || humidity > 100)
                cout << "[Error] Please enter a percentage between 0 and 100." << endl;
        } while (humidity < 0 || humidity > 100);
    }

    void displayWeather() {
        displaySensor();
        cout << "Rainfall       : " << rainfall << " mm" << endl;
        cout << "Humidity       : " << humidity << "%" << endl;
    }
};

// Derived Level 2: FloodSensor
class FloodSensor : public WeatherSensor {
private:
    string alertLevel;

public:
    void analyzeFlood() {
        bool rainHigh = (rainfall > 100);
        bool humidityHigh = (humidity > 80);

        if (rainHigh && humidityHigh) {
            alertLevel = "HIGH";
        } else if (rainHigh || humidityHigh) {
            alertLevel = "MEDIUM";
        } else {
            alertLevel = "LOW";
        }
    }

    void displayReport() {
        cout << "\n========== DISASTER MONITORING REPORT ==========" << endl;
        displayWeather();
        cout << "Flood Alert    : " << alertLevel << endl;
        
        if (alertLevel == "HIGH") {
            cout << "\n!!! WARNING: Immediate evacuation required !!!" << endl;
        } else if (alertLevel == "MEDIUM") {
            cout << "Status: Stay alert and monitor updates." << endl;
        } else {
            cout << "Status: Normal environmental conditions." << endl;
        }
        cout << "================================================" << endl;
    }
};

int main() {
    FloodSensor fs;

    cout << "----- Weather Monitoring System Initialized -----" << endl;
    fs.inputWeather();
    fs.analyzeFlood();
    fs.displayReport();

    return 0;
}