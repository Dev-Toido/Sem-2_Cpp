// Q3. Cybersecurity Threat Analyzer
// 🧩 Story
// A cybersecurity firm is building a system to analyze network logs and detect threats. The system collects raw logs, processes login attempts, and classifies threats.
// 🧬 Hierarchy
// Log → NetworkLog → ThreatAnalyzer

// 📌 System Description
// Log:
// Stores IP address, timestamp
// NetworkLog:
// Stores loginAttempts
// Tracks repeated access
// ThreatAnalyzer:
// Detects:
// Attempts ≥ 5 → suspicious
// Attempts ≥ 10 → high threat
// Classifies:
// Low / Medium / High
// Blocks IP if high threat

// 🎯 Tasks
// Implement multilevel inheritance
// Accept multiple log entries
// Analyze threat level
// Display:
// IP address
// Attempts
// Threat level
// Block status

// ⚙️ Constraints
// Timestamp format can be simplified (integer)
// Must handle multiple logs
#include <iostream>
#include <string>

using namespace std;

// Base Class: Level 1
class Log {
protected:
    string ipAddress;
    int timestamp; // Simplified as an integer per constraints

public:
    void inputLog() {
        cout << "Enter IP Address: ";
        cin >> ipAddress;
        cout << "Enter Timestamp (HHMM): ";
        cin >> timestamp;
    }

    void displayLog() {
        cout << "IP Address : " << ipAddress << endl;
        cout << "Timestamp  : " << timestamp << endl;
    }
};

// Intermediate Class: Level 2 (Inherits from Log)
class NetworkLog : public Log {
protected:
    int loginAttempts;

public:
    void inputNetworkData() {
        inputLog(); // Get Base class info
        cout << "Enter Login Attempts: ";
        cin >> loginAttempts;
    }

    void displayNetworkData() {
        displayLog(); // Show Base class info
        cout << "Attempts   : " << loginAttempts << endl;
    }
};

// Derived Class: Level 3 (Inherits from NetworkLog)
class ThreatAnalyzer : public NetworkLog {
private:
    string threatLevel;
    bool isBlocked;

public:
    void analyzeThreat() {
        isBlocked = false;

        if (loginAttempts >= 10) {
            threatLevel = "HIGH";
            isBlocked = true; // Block IP if high threat
        } else if (loginAttempts >= 5) {
            threatLevel = "MEDIUM (Suspicious)";
        } else {
            threatLevel = "LOW";
        }
    }

    void displayThreatReport() {
        displayNetworkData(); // Show Intermediate class info
        cout << "Threat Level: " << threatLevel << endl;
        cout << "Block Status: " << (isBlocked ? "BLOCKED [X]" : "ACTIVE [OK]") << endl;
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    int numLogs;
    cout << "===== Cybersecurity Threat Analyzer =====" << endl;
    cout << "How many logs do you want to enter? ";
    cin >> numLogs;

    // Array of objects for multiple entries
    ThreatAnalyzer logs[100]; 

    for (int i = 0; i < numLogs; i++) {
        cout << "\n--- Log Entry #" << i + 1 << " ---" << endl;
        logs[i].inputNetworkData();
        logs[i].analyzeThreat();
    }

    cout << "\n========== THREAT ANALYSIS REPORT ==========" << endl;
    for (int i = 0; i < numLogs; i++) {
        logs[i].displayThreatReport();
    }

    return 0;
}