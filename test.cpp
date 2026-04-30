#include <iostream>
using namespace std;

int fact(int n){
    if(n==1||n==0){
        return n;
    }
    else{
        return n*fact(n-1);
    }
}
int main()
{
    cout<<"HI there"<<fact(5)<<endl;
    cerr<<"HI there"<<endl;
    clog<<"HI there"<<endl;

    return 0;
}