// Q2 . Smart Healthcare Monitoring System
// 🧩 Story
// A hospital system monitors different types of patients based on their conditions.
// 🧬 Structure
// Patient → CriticalPatient, RegularPatient, RemotePatient

// 📦 Class Design
// 🔹 Patient
// Attributes:
// int patientID
// string name
// Functions:
// void inputPatient()
// void displayPatient()

// 🔹 CriticalPatient
// Attributes:
// int oxygenLevel
// Functions:
// void inputCritical()
// void checkEmergency()

// 🔹 RegularPatient
// Attributes:
// int heartRate
// Functions:
// void inputRegular()
// void checkHealth()

// 🔹 RemotePatient
// Attributes:
// int stepCount
// Functions:
// void inputRemote()
// void analyzeActivity()

// 🎯 Tasks
// Perform patient-specific checks
// Display health status
// Conditions Used
// 🔴 Critical Patient
// Oxygen < 90 → Emergency
// ❤️ Regular Patient
// Heart rate < 60 or > 100 → Abnormal
// 🏃 Remote Patient
// < 3000 → Low activity
// 3000–10000 → Moderate
// 10000 → Active
#include <iostream>
#include <string>

using namespace std;

// Base Class: Hierarchical Parent
class Patient {
protected:
    int patientID;
    string name;

public:
    void inputPatient() {
        cout << "Enter Patient ID: ";
        cin >> patientID;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
    }

    void displayPatient() {
        cout << "Patient ID : " << patientID << endl;
        cout << "Name       : " << name << endl;
    }
};

// Derived Class 1: Critical Patient
class CriticalPatient : public Patient {
private:
    int oxygenLevel;

public:
    void inputCritical() {
        inputPatient();
        cout << "Enter Oxygen Level (%): ";
        cin >> oxygenLevel;
    }

    void checkEmergency() {
        displayPatient();
        cout << "Oxygen Level: " << oxygenLevel << "%" << endl;
        if (oxygenLevel < 90) {
            cout << "STATUS     : !!! EMERGENCY ALERT !!! (Low Oxygen)" << endl;
        } else {
            cout << "STATUS     : Stable" << endl;
        }
    }
};

// Derived Class 2: Regular Patient
class RegularPatient : public Patient {
private:
    int heartRate;

public:
    void inputRegular() {
        inputPatient();
        cout << "Enter Heart Rate (BPM): ";
        cin >> heartRate;
    }

    void checkHealth() {
        displayPatient();
        cout << "Heart Rate : " << heartRate << " BPM" << endl;
        if (heartRate < 60 || heartRate > 100) {
            cout << "STATUS     : Abnormal Heart Rate detected" << endl;
        } else {
            cout << "STATUS     : Normal" << endl;
        }
    }
};

// Derived Class 3: Remote Patient
class RemotePatient : public Patient {
private:
    int stepCount;

public:
    void inputRemote() {
        inputPatient();
        cout << "Enter Daily Step Count: ";
        cin >> stepCount;
    }

    void analyzeActivity() {
        displayPatient();
        cout << "Step Count : " << stepCount << endl;
        cout << "Activity   : ";
        if (stepCount < 3000) {
            cout << "Low Activity" << endl;
        } else if (stepCount >= 3000 && stepCount < 10000) {
            cout << "Moderate Activity" << endl;
        } else {
            cout << "Active" << endl;
        }
    }
};

int main() {
    int choice;
    cout << "===== Hospital Healthcare Monitor =====" << endl;
    cout << "1. Critical Patient\n2. Regular Patient\n3. Remote Patient\n";
    cout << "Select Patient Type: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            CriticalPatient cp;
            cp.inputCritical();
            cout << "\n--- Healthcare Report ---" << endl;
            cp.checkEmergency();
            break;
        }
        case 2: {
            RegularPatient rp;
            rp.inputRegular();
            cout << "\n--- Healthcare Report ---" << endl;
            rp.checkHealth();
            break;
        }
        case 3: {
            RemotePatient rmp;
            rmp.inputRemote();
            cout << "\n--- Healthcare Report ---" << endl;
            rmp.analyzeActivity();
            break;
        }
        default:
            cout << "Invalid Selection!" << endl;
    }

    return 0;
}