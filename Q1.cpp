#include <iostream>
using namespace std;

class Shape {
protected:
    string nameOfShape;
    double width, height;

public:
    Shape(string name, double width, double height) 
        : nameOfShape(name), width(width), height(height) {}

    virtual ~Shape() {}

    string getName() { return nameOfShape; }
    
    virtual double getArea() = 0; 
};

class Rectangle : public Shape {
public:
    using Shape::Shape;
    virtual double getArea() override { return width * height; }
};

class Triangle : public Shape {
public:
    using Shape::Shape; 

    virtual double getArea() override { return 0.5 * width * height; }
};

int main() {
    Rectangle r1("My rectangle", 2.0, 4.0);
    Triangle t1("My triangle", 2.0, 4.0);

    cout << r1.getName() << " area = " << r1.getArea() << endl; 
    cout << t1.getName() << " area = " << t1.getArea() << endl;

    return 1;
}
