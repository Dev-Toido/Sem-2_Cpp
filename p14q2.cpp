// Q2 . File Copy Program
// Write a program to:
// Copy content from file1.txt to file2.txt
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream readinf1("fivenums.txt");
    ofstream writeinf("fivenums(copy).txt");
    
    // Reading from the source file and coping them to the destination file
    cout << "The elements in the are being copied to the other file! " << endl;
    string buff;
    while (getline(readinf1, buff))
    {
        writeinf << buff << "\n";
    }
    readinf1.close();
    writeinf.close();


    // Reading the destination file
    ifstream readinf2("fivenums(copy).txt");
    cout << "The elements in the destination file are: " << endl;
    while (getline(readinf2, buff))
    {
        cout << buff << endl;
    }

    readinf2.close();

    return 0;
}