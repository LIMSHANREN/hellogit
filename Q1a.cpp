#include <iostream>
#include <iomanip>

using namespace std;

class Temperature {
private:
    char unit;
    float degree;

public:
    Temperature(char u, float d) {
        unit = u;
        degree = d;
    }

    float getCels() {
        if (unit == 'C' || unit == 'c') {
            return degree;
        } else {
            return (degree - 32) * 5.0 / 9.0;
        }
    }

    float getFar() {
        if (unit == 'F' || unit == 'f') {
            return degree;
        } else {
            return (degree * 9.0 / 5.0) + 32;
        }
    }

    void equal(Temperature t) {
        this->unit = t.unit;
        this->degree = t.degree;
    }
};

int main() {
    Temperature t1('C', 100), t2('F', 100);

    cout << fixed << setprecision(4); 
    cout << "t1 = " << t1.getCels() << " C" << endl;
    cout << "t1 = " << t1.getFar() << " F" << endl;
    cout << "t2 = " << t2.getCels() << " C" << endl;
    cout << "t2 = " << t2.getFar() << " F" << endl;

    t1.equal(t2);

    cout << "After assigning t2 to t1" << endl;
    cout << "t1 = " << t1.getCels() << " C" << endl;
    cout << "t1 = " << t1.getFar() << " F" << endl;

    return 0;
}