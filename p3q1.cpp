// Q 1. Student Result Display Using cout
// Develop a C++ program that:
// Accepts Roll No, and Marks using cin.
// Displays the result using cout.
// Display “Pass” if marks ≥ 40, otherwise “Fail” using a bool variable.
#include <iostream>
using namespace std;

int main() {
    int roll,marks;bool result;
    cout<<"Enter your Roll no:";
    cin>>roll;
    cout<<"Enter your Marks:";
    cin>>marks;
    
    result=(marks>=40);

    cout<<((result)?"Pass":"Fail");
    return 0;
}