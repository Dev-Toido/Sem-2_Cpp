// Q5. Create class Mobile:
// id, name, price
// Tasks:
// Store records in file
// Update quantity of a Mobile
// Display mobile with high price
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_MOBILES = 100; // Buffer limit for the array

class Mobile {
public:
    int id;
    string name;
    double price;
    int quantity;

    void display() {
        cout << left << setw(10) << id 
             << setw(20) << name 
             << setw(12) << fixed << setprecision(2) << price 
             << "Qty: " << quantity << endl;
    }
};

// Task 1: Store records in file
void addMobile() {
    Mobile m;
    cout << "Enter Mobile ID: "; cin >> m.id;
    cout << "Enter Name: "; cin.ignore(); getline(cin, m.name);
    cout << "Enter Price: "; cin >> m.price;
    cout << "Enter Quantity: "; cin >> m.quantity;

    ofstream outFile("mobiles.txt", ios::app);
    if (outFile) {
        outFile << m.id << " " << m.name << " " << m.price << " " << m.quantity << endl;
        outFile.close();
        cout << "Mobile record saved!\n";
    }
}

// Task 2: Update quantity of a Mobile
void updateQuantity(int targetId, int newQty) {
    Mobile inventory[MAX_MOBILES];
    int count = 0;
    bool found = false;

    ifstream inFile("mobiles.txt");
    if (!inFile) return;

    // Read everything into memory
    while (count < MAX_MOBILES && inFile >> inventory[count].id >> inventory[count].name >> inventory[count].price >> inventory[count].quantity) {
        if (inventory[count].id == targetId) {
            inventory[count].quantity = newQty;
            found = true;
        }
        count++;
    }
    inFile.close();

    if (found) {
        // Overwrite file with updated data
        ofstream outFile("mobiles.txt", ios::trunc);
        for (int i = 0; i < count; i++) {
            outFile << inventory[i].id << " " << inventory[i].name << " " << inventory[i].price << " " << inventory[i].quantity << endl;
        }
        outFile.close();
        cout << "Quantity updated successfully!\n";
    } else {
        cout << "Mobile ID not found.\n";
    }
}

// Task 3: Display mobile with high price (e.g., > 50,000)
void displayHighPrice(double threshold) {
    ifstream inFile("mobiles.txt");
    Mobile m;
    bool found = false;

    cout << "\n--- Premium Mobiles (Price > " << threshold << ") ---\n";
    while (inFile >> m.id >> m.name >> m.price >> m.quantity) {
        if (m.price > threshold) {
            m.display();
            found = true;
        }
    }
    if (!found) cout << "No mobiles found in this price range.\n";
    inFile.close();
}

int main() {
    int choice, id, qty;

    do {
        cout << "\n1. Add Mobile\n2. Update Quantity\n3. High Price Report\n4. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: addMobile(); break;
            case 2:
                cout << "Enter Mobile ID: "; cin >> id;
                cout << "Enter New Quantity: "; cin >> qty;
                updateQuantity(id, qty);
                break;
            case 3:
                displayHighPrice(50000.0); // Setting 50,000 as 'High Price'
                break;
        }
    } while (choice != 4);

    return 0;
}