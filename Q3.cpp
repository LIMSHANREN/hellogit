#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    string address;

public:
    Person(string name, string address) : name(name), address(address) {}
    
    string getName() const { return name; }
    string getAddress() const { return address; }
};

class Package {
protected:
    Person sender;       
    Person recipient;   
    double weight;       
    double cost_per_kg;  

public:
    Package(Person s, Person r, double w, double c) 
        : sender(s), recipient(r), weight((w > 0.0) ? w : 0.0), cost_per_kg((c > 0.0) ? c : 0.0) {}

    virtual ~Package() {}

    virtual double calculateCost() const {
        return weight * cost_per_kg;
    }
};

class TwoDayPackage : public Package {
private:
    double flat_fee;   

public:
    TwoDayPackage(Person s, Person r, double w, double c, double fee)
        : Package(s, r, w, c), flat_fee((fee > 0.0) ? fee : 0.0) {}

    virtual double calculateCost() const override {
        return Package::calculateCost() + flat_fee; 
    }
};

int main() {
    Package pkg1(Person("Ali", "Jalan 123"), Person("Lim", "Cyberjaya"), 1.5, 50); 
    cout << "\n The cost of package pkg1 = " << pkg1.calculateCost(); 
    cout << endl; 

    TwoDayPackage pkg2(Person("Ali", "Jalan 123"), Person("Lim", "Cyberjaya"), 1.5, 50, 10);
    cout << "\n The cost of package pkg2 = " << pkg2.calculateCost(); 
    cout << endl; 

    system("pause"); 
    
    return 1; 
}