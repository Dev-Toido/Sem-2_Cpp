#include <iostream>
using namespace std;

int main()
{
    char c='A';
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j=0;j<i;j++){
            cout<<"  ";
        }
        for (int j = 0; j < n-i; j++)
        {
            cout << j+1 << " ";
        }
        cout << endl;
    }
    return 0;
}