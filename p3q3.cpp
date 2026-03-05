// Q 3. Marks Average with Type Conversion
// Develop a program that:
// Accepts marks of 3 subjects (int).
// Calculates average using float.
// Demonstrates int → float conversion.
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int s1,s2,s3;float avg;
    cout<<"Enter the marks of three subjects:";
    cin >> s1>> s2>> s3;
    
    avg = (s1 + s2 + s3) / 3.0;
    
    cout<<"Average is "<<fixed<<setprecision(2)<<avg<<" which is a float literal!"<<endl;

    
    return 0;
}