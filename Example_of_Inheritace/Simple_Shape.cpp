#include <iostream>
using namespace std;

class Shape{
    public:
        int area;
        void display(){
            cout<<area<<endl;
        }
};
class Rectangle:public Shape{
    public:
    int l,b;
    Rectangle(int l,int b){
        this->l=l;
        this->b=b;
        area=l*b;
    }
};


int main() {
    Rectangle r(3,6);
    r.display();
    return 0;
}