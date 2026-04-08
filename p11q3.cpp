// Q3. Smart Home Lighting System
// Story:
//  A smart home system allows users to control lights differently depending on how they give commands.
// Class: SmartLight
// Attributes:
// roomName
// lightStatus
// Member Functions (Overloaded):
// turnOn()
// turnOn(int brightness)
// turnOn(string color, int brightness)
// 👉 Task:
// Simulate different ways to turn on lights
// Display final configuration of the light
#include <iostream>
#include <string>

using namespace std;

class SmartLight {
private:
    string roomName;
    string lightStatus;
    int brightness;
    string color;

public:
    // Constructor to initialize the room name
    SmartLight(string name) {
        roomName = name;
        lightStatus = "OFF";
        brightness = 0;
        color = "None";
    }

    // 1. Basic turnOn: Default settings
    void turnOn() {
        lightStatus = "ON";
        brightness = 100; // Default full brightness
        color = "Warm White";
        cout << "[System] " << roomName << " light turned ON with default settings." << endl;
    }

    // 2. Overloaded turnOn: Specific brightness
    void turnOn(int b) {
        lightStatus = "ON";
        brightness = b;
        color = "Warm White"; // Default color
        cout << "[System] " << roomName << " light dimmed to " << brightness << "%." << endl;
    }

    // 3. Overloaded turnOn: Custom color and brightness
    void turnOn(string c, int b) {
        lightStatus = "ON";
        brightness = b;
        color = c;
        cout << "[System] " << roomName << " light set to " << color << " at " << brightness << "%." << endl;
    }

    void displayConfig() {
        cout << "\n--- Current Configuration: " << roomName << " ---" << endl;
        cout << "Status    : " << lightStatus << endl;
        cout << "Brightness: " << brightness << "%" << endl;
        cout << "Color     : " << color << endl;
        cout << "------------------------------------------" << endl;
    }
};

int main() {
    // Simulating lights in different rooms
    SmartLight livingRoom("Living Room");
    SmartLight kitchen("Kitchen");
    SmartLight bedroom("Bedroom");

    cout << "===== Smart Home Command Center =====" << endl;

    // Mode 1: Default command
    livingRoom.turnOn();
    livingRoom.displayConfig();

    // Mode 2: Dimmer command
    kitchen.turnOn(50);
    kitchen.displayConfig();

    // Mode 3: Party/Mood mode command
    bedroom.turnOn("Ocean Blue", 80);
    bedroom.displayConfig();

    return 0;
}