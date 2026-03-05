// Q 2. ​​Online Shopping Cart
// Scenario:
//  An e-commerce website needs to manage a user's cart.
// Task:
// Class name: Cart
// Private: itemPrice, quantity
// Public:
// setItemDetails(price, qty)
// calculateTotal()
// displayBill()

#include <iostream>
using namespace std;

class Cart
{
private:
    int itemPrice, quantity, total;

public:
    void setItemDetails(int price, int qty)
    {
        itemPrice = price;
        quantity = qty;
        cout << "Details updated sucessfully" << endl;
    }
    void calculateTotal()
    {
        total = itemPrice * quantity;
        cout << "Total Calculated!" << endl;
    }
    void displayBill()
    {
        cout << "Your total bill is " << total << endl;
    }
};

int main()
{
    Cart c1;
    int price, qty;
    cout << "You have your cart, please enter the price and quantity: " << endl;
    cout << "Price: ";
    cin >> price;
    cout << "Quantity: ";
    cin >> qty;
    c1.setItemDetails(price, qty);
    c1.calculateTotal();
    c1.displayBill();
    

    return 0;
}