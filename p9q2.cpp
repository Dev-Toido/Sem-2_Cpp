// Q2 . Online Food Delivery Tracking
// A base class Order contains order ID and customer name. Derived class FoodOrder includes delivery time and food category.
// 👉 Task:
// Implement inheritance
// Add method to check if delivery is delayed
// Display order summary 
#include <iostream>
#include <string>

using namespace std;

// Base class for general order information
class Order {
protected:
    int orderID;
    string customerName;

public:
    void inputOrder() {
        cout << "Enter Order ID: ";
        cin >> orderID;
        cin.ignore(); // To clear the buffer before getline
        cout << "Enter Customer Name: ";
        getline(cin, customerName);
    }

    void displayOrder() {
        cout << "Order ID      : " << orderID << endl;
        cout << "Customer Name : " << customerName << endl;
    }
};

// Derived class for specific food delivery details
class FoodOrder : public Order {
private:
    int deliveryTime; // in minutes
    string foodCategory;
    const int standardTime = 45; // Threshold for delay

public:
    void inputFoodOrder() {
        // First, get base class details
        inputOrder();
        
        cout << "Enter Food Category (e.g., Italian, Fast Food): ";
        getline(cin, foodCategory);
        cout << "Enter Actual Delivery Time (in minutes): ";
        cin >> deliveryTime;
    }

    // Method to check if the delivery is delayed
    bool checkDelay() {
        if (deliveryTime > standardTime) {
            return true;
        }
        return false;
    }

    void displaySummary() {
        cout << "\n========== ORDER SUMMARY ==========" << endl;
        displayOrder(); // Call base class display
        cout << "Food Category : " << foodCategory << endl;
        cout << "Delivery Time : " << deliveryTime << " mins" << endl;
        
        cout << "Status        : ";
        if (checkDelay()) {
            cout << "DELAYED (Exceeded " << standardTime << " mins)" << endl;
        } else {
            cout << "ON TIME" << endl;
        }
        cout << "==================================\n" << endl;
    }
};

int main() {
    FoodOrder myOrder;

    cout << "--- Enter Delivery Details ---" << endl;
    myOrder.inputFoodOrder();
    
    // Display the final report
    myOrder.displaySummary();

    return 0;
}