// 1. Notification System
// Story:
//  A system sends notifications using different methods.
// Base Class: Notification
// Member Function:
// virtual void send(string message)
// Derived Classes:
// Email
// SMS
// PushNotification
// 👉 Task:
// Override sending method
// Display message delivery format
#include <iostream>
#include <string>

using namespace std;

// Base Class
class Notification
{
public:
    // Virtual function to enable polymorphism
    virtual void send(string message)
    {
        cout << "General Notification: " << message << endl;
    }

    virtual ~Notification() {} // Virtual destructor
};

// Derived Class 1: Email
class Email : public Notification
{
public:
    void send(string message) override
    {
        cout << "[EMAIL] >>> To: user@example.com" << endl;
        cout << "Body: " << message << endl;
        cout << "Status: Sent via SMTP Server" << endl;
        cout << "------------------------------------" << endl;
    }
};

// Derived Class 2: SMS
class SMS : public Notification
{
public:
    void send(string message) override
    {
        cout << "[SMS] >>> To: +91-9898989898" << endl;
        cout << "Text: " << message << endl;
        cout << "Status: Delivered via Cellular Network" << endl;
        cout << "------------------------------------" << endl;
    }
};

// Derived Class 3: Push Notification
class PushNotification : public Notification
{
public:
    void send(string message) override
    {
        cout << "[PUSH] >>> To: DeviceID_AF99" << endl;
        cout << "Alert: " << message << endl;
        cout << "Status: Displayed on Notification Tray" << endl;
        cout << "------------------------------------" << endl;
    }
};

int main()
{
    // Creating individual objects
    Email myEmail;
    SMS mySMS;
    PushNotification myPush;

    // Using the overridden methods directly
    myEmail.send("Welcome to our platform!");
    mySMS.send("Your verification code is 8821.");
    myPush.send("New comment on your post.");

    return 0;
}