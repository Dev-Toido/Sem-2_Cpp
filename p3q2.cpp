// Q 2. ​​Boolean Type Demonstration
// Write a C++ program to:
// Accept a number from the user.
// Store  results whether the number is even or odd in a bool variable.
// Display the result using cout.
#include <iostream>
using namespace std;

int main() {
    int n;bool result;
    cout<<"Enter a number:";
    cin>>n;
       
    result=(n%2==0);

    cout<<((result)?"Even":"Odd");
    return 0;
}