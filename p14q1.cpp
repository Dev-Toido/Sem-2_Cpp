// Q1. Write & Read Data
// Write a program to:
// Create a file
// Write 5 numbers into it
// Read and display them
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    //Writing in the file
    ofstream writeinf("fivenums.txt");
    int n; 
    for(int i=0;i<5;i++){
        cout<<"Enter "<<i+1<<"th number:";
        cin>>n;
        writeinf<<n<<"\n";
    }
    writeinf.close();

    //Reading the file
    ifstream readinf("fivenums.txt");
    cout<<"The elements in the file are: "<<endl;
    string buff;
    while(getline(readinf,buff)){
        cout<<buff<<endl;
    }
    readinf.close();

    return 0;
}