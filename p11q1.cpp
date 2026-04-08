// Q1. Area Calculation System
// Scenario:
//  Design a system to calculate area of different shapes using the same function name.
// Class: Area
//  Attributes: None
// Member Functions (Overloaded):
// calculate(int side) → Square
// calculate(int length, int breadth) → Rectangle
// calculate(float radius) → Circle
// 👉 Task:
// Take input for shape type
// Call correct overloaded function
// Display area
#include <iostream>

using namespace std;

class Area {
public:
    // Overloaded function for Square (int)
    void calculate(int side) {
        int area = side * side;
        cout << "--- Square ---" << endl;
        cout << "Side: " << side << endl;
        cout << "Area: " << area << " sq. units" << endl;
    }

    // Overloaded function for Rectangle (int, int)
    void calculate(int length, int breadth) {
        int area = length * breadth;
        cout << "--- Rectangle ---" << endl;
        cout << "Length: " << length << ", Breadth: " << breadth << endl;
        cout << "Area  : " << area << " sq. units" << endl;
    }

    // Overloaded function for Circle (float)
    void calculate(float radius) {
        float area = 3.14159f * radius * radius;
        cout << "--- Circle ---" << endl;
        cout << "Radius: " << radius << endl;
        cout << "Area  : " << area << " sq. units" << endl;
    }
};

int main() {
    Area obj;
    int choice;

    cout << "===== Area Calculation System =====" << endl;
    cout << "1. Square\n2. Rectangle\n3. Circle\n";
    cout << "Select Shape: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int s;
            cout << "Enter side of Square: ";
            cin >> s;
            obj.calculate(s);
            break;
        }
        case 2: {
            int l, b;
            cout << "Enter length and breadth of Rectangle: ";
            cin >> l >> b;
            obj.calculate(l, b);
            break;
        }
        case 3: {
            float r;
            cout << "Enter radius of Circle: ";
            cin >> r;
            // Passing a float variable to call the float version of calculate
            obj.calculate(r);
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}