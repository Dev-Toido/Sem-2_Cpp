// Q4. Smart Classroom System
// Story:
//  A smart classroom system behaves differently based on teaching mode.
// Base Class: Classroom
// Member Function:
// virtual void conductClass()
// Derived Classes:
// OnlineClass
// OfflineClass
// HybridClass
// 👉 Task:
// Override class conducting methods
// Show differences in attendance and interaction

#include <iostream>
#include <string>

using namespace std;

// Base Class
class Classroom {
public:
    // Virtual function for polymorphic behavior
    virtual void conductClass() {
        cout << "Starting a standard teaching session..." << endl;
    }

    virtual ~Classroom() {} // Virtual destructor
};

// Derived Class 1: Online Class
class OnlineClass : public Classroom {
public:
    void conductClass() override {
        cout << "[ONLINE MODE] >>> Platform: Zoom/Google Meet" << endl;
        cout << "Attendance: Logged automatically via user login timestamps." << endl;
        cout << "Interaction: Hand-raise icons, Chatbox, and Screen Sharing." << endl;
        cout << "--------------------------------------------------------" << endl;
    }
};

// Derived Class 2: Offline Class
class OfflineClass : public Classroom {
public:
    void conductClass() override {
        cout << "[OFFLINE MODE] >>> Location: Physical Campus" << endl;
        cout << "Attendance: Manual roll call or biometric scanner at the door." << endl;
        cout << "Interaction: Face-to-face discussion and physical whiteboard work." << endl;
        cout << "--------------------------------------------------------" << endl;
    }
};

// Derived Class 3: Hybrid Class
class HybridClass : public Classroom {
public:
    void conductClass() override {
        cout << "[HYBRID MODE] >>> Setup: Classroom with Live Streaming" << endl;
        cout << "Attendance: Combined physical sign-in and digital login tracking." << endl;
        cout << "Interaction: Dual-mode Q&A (In-person and Remote via Audio Link)." << endl;
        cout << "--------------------------------------------------------" << endl;
    }
};

int main() {
    // Instantiate specific class types
    OnlineClass mathOnline;
    OfflineClass historyLab;
    HybridClass physicsLecture;

    // Execute the overridden conductClass methods
    mathOnline.conductClass();
    historyLab.conductClass();
    physicsLecture.conductClass();

    return 0;
}

