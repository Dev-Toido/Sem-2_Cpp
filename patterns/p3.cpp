#include <iostream>
using namespace std;

int main()
{
    char c = 'A';
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << char(c + i) << " ";
        }
        cout << endl;
    }
    return 0;
}