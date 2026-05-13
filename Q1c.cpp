#include<iostream>
#include<cmath>

using namespace std;

class Point {
private:
    double x, y;
public:
    Point(const double x = 0, const double y = 0) : x(x), y(y) {}
    double getX()const { return x; };
    double getY()const { return y; };
};

class Line {
private:
    Point p1, p2;
public:
    Line(const Point &p1, const Point &p2) : p1(p1), p2(p2) {}

    double length() const {
        double dx = p2.getX() - p1.getX();
        double dy = p2.getY() - p1.getY();
        return sqrt(dx * dx + dy * dy);
    }

};

int main() {
    Point p1(0,0);
    Point p2(3,4);

    Line line1(p1, p2);

    cout << "Length of line: " << line1.length() << endl;

    return 0;
}