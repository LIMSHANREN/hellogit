#include<iostream>
#include<cmath>

using namespace std;

class Point {
private:

public:
    double x, y;
    Point(double x = 0, double y = 0){
        this->x = x;
        this->y = y;
    }
};

class Line {
private:
    Point p1, p2;
public:
    Line(Point p1, Point p2) : p1(p1), p2(p2) {}

    double length() {
        double dx = p2.x - p1.x;
        double dy = p2.y - p1.y;
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