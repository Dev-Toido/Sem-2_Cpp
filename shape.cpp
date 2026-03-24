#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

string d_unit = "cm";
string a_unit = "degree";
const double PI = 3.14159265358979323846;

class Shape
{
public:
    string sname;
    float area;
    float perimeter;
    string color;

    Shape()
    {
        area = 0;
        perimeter = 0;
        color = "";
        cout << "The Shape object is created! " << endl;
    }
    void displayDetails()
    {
        cout << left << setw(15) << "Shape Name: " << sname << endl;
        cout << left << setw(15) << "Area: " << area << " " << d_unit << "^2" << endl;
        cout << left << setw(15) << "Perimeter: " << perimeter << " " << d_unit << endl;
        cout << left << setw(15) << "Color: " << color << endl;
        cout << string(30, '=') << endl;
    }
};

class Square : public Shape
{
public:
    int side;

    Square(int s, string c)
    {
        side = s;
        color = c;
        sname = "Square";
        calArea();
        calPeri();
        cout << "The Square object is created! " << endl;
    }
    void calArea()
    {
        area = side * side;
    }
    void calPeri()
    {
        perimeter = 4 * side;
    }
};

class Rombus : public Square
{
public:
    float angle;
    Rombus(int s, float a, string c): Square(s,c)
    {
        side = s;
        color = c;
        sname = "Rombus";
        angle = (a_unit == "degree") ? (a * (PI / 180)) : a;
        calArea();
        calPeri();
        cout << "The Rombus object is created! " << endl;
    }
    void calArea()
    {
        area = side * side * sin(angle);
    }
};

class Rectangle : public Shape
{
public:
    int lenght, breadth;
    Rectangle(int l, int b, string c)
    {
        lenght = l;
        breadth = b;
        color = c;
        sname = "Rectangle";
        calArea();
        calPeri();
        cout << "The Rectangle object is created! " << endl;
    }
    void calArea()
    {
        area = lenght * breadth;
    }
    void calPeri()
    {
        perimeter = 2 * (lenght + breadth);
    }
};
class Parallelogram : public Rectangle
{
public:
    float angle;
    Parallelogram(int l, int b, float a, string c):Rectangle(l,b,c)
    {
        lenght = l;
        breadth = b;
        angle = (a_unit == "degree") ? (a * (PI / 180)) : a;
        color = c;
        sname = "Parallelogram";
        calArea();
        calPeri();
        cout << "The Parallelogram object is created! " << endl;
    }
    void calArea()
    {
        area = lenght * breadth * sin(angle);
    }
};

class Circle : public Shape
{
public:
    int radius;

    Circle(int r, string c)
    {
        radius = r;
        color = c;
        sname = "Circle";
        calArea();
        calPeri();
        cout << "The Circle object is created! " << endl;
    }
    void calArea()
    {
        area = PI * radius * radius;
    }
    void calPeri()
    {
        perimeter = 2 * PI * radius;
    }
};

int main()
{
    Square s1(5, "Blue");
    Rectangle r1(3, 2, "Red");
    Circle c1(10, "Violet");
    Rombus rom1(5, 30, "Yellow");
    Parallelogram p1(15, 5, 30, "Pink");

    s1.displayDetails();
    r1.displayDetails();
    c1.displayDetails();
    rom1.displayDetails();
    p1.displayDetails();
    // Ellipse left
    return 0;
}