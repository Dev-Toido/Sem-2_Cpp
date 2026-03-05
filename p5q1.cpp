// Q1. Library Book Comparison System
// Scenario:
// A large college library maintains thousands of books for students and faculty. The librarian wants to develop a small software system to manage book information and help in price analysis.
// The librarian's main goal is to identify which book is more expensive so that proper security measures can be applied to costly books.
// To implement this system using Object-Oriented Programming in C++, you are required to design a class that stores book details and compares book prices.
// Requirements:
// Step 1: Class Creation
// Create a class named Book that contains the following private data members:
// Book ID (integer) — unique identification number of the book
// Book Name (string) — name of the book
// Book Price (float) — cost of the book

// Step 2: Constructor Implementation
// Implement a parameterized constructor that initializes all book details when an object is created.

// Step 3: Member Functions
// Create the following public member functions:
// Getter functions to access the book price and the book name safely.

// Step 4: Object as Function Argument
// Create a separate function outside the class named compareBookPrice that:
// Accepts two Book objects as arguments
// Compares the prices of both books
// Displays the name and price of the costlier book

// Step 5: Main Function Implementation
// In the main() function:
// Create two Book objects using the constructor
// Display details of both books
// Call the comparison function by passing both objects
// Display which book is more expensive
#include <iostream>
#include <iomanip>

using namespace std;

class Book
{
private:
    int id;
    string name;
    float price;

public:
    Book(int newid, string newname, float newprice)
    {
        id = newid;
        name = newname;
        price = newprice;
    }
    void showDetails()
    {
        // cout<<"The details of the Book are"<<endl;
        cout << left << setw(20) << "ID: " << id;
        cout << left << setw(20) << "Name: " << name;
        cout << left << setw(20) << "Price: " << price;
    }

    string getName() { return name; }
    float getPrice() { return price; }
};

void compareBookPrice(Book b1, Book b2)
{
    string bname;
    float bprice;
    (b1.getPrice() > b2.getPrice()) ? (bname = b1.getName(), bprice = b1.getPrice()) : (bname = b2.getName(), bprice = b2.getPrice());
    cout << "The costlier book :" << endl;
    cout << setw(10) << "Book Name: " << bname << endl;
    cout << setw(10) << "Book Price: " << bprice << endl;
}

int main()
{
    int id;
    float price;
    string name;
    cout << "Enter the Name of the 1st book: ";
    getline(cin, name);
    cout << "Enter the ID of the 1st book: ";
    cin >> id;
    cout << "Enter the price of the 1st book: ";
    cin >> price;
    cout << "The details are updated!!" << endl;
    Book b1(id, name, price);

    cin.ignore();
    cout << "Enter the Name of the 2nd book: ";
    getline(cin, name);
    cout << "Enter the ID of the 2nd book: ";
    cin >> id;
    cout << "Enter the price of the 2nd book: ";
    cin >> price;
    cout << "The details are updated!!" << endl;
    Book b2(id, name, price);

    compareBookPrice(b1, b2);

    return 0;
}