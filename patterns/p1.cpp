#include <iostream>
using namespace std;

int main()
{
    int n = 3;
    for (int i = 0; i < n * n; i++)
    {
        cout << i + 1<< " ";
        if ((i + 1) % n == 0)
        {
            cout << endl;
        }
    }
    return 0;
}