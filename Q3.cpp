#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    double salary;

public:
    Employee() {
        name = "";
        salary = 0.0;
    }

    Employee(string name, double a_salary) {
        this->name = name;
        this->salary = a_salary;
    }

    string getName() { return name; }
    void setName(string a_name) { name = a_name; }
    
    double getSalary() { return salary; }
    void setSalary(double a_salary) { salary = a_salary; }

    void displayStaffInformation() {
        cout << "Staff Name: " << name << ", Salary: RM " << salary << endl;
    }

    void incrementSalary(float rate) {
        if (salary < 2000.0) {
            salary = salary * (1.0 + rate);
            cout << "Increment successful for " << name << "." << endl;
        } else {
            cout << "Message: " << name << " is not qualified for increment (Salary is already RM2000 or above)." << endl;
        }
    }
};

class Company {
private:
    int numberOfStaff;
    Employee* staffList;

public:
    Company() {
        numberOfStaff = 0;
        staffList = nullptr;
    }

    ~Company() {
        if (staffList != nullptr) {
            delete[] staffList;
        }
    }

    void getDataFromFile(string filename) {
        fstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening " << filename << endl;
            return;
        }

        string str;
        int num = 0;
        while (getline(file, str)) {
            if (!str.empty()) { 
                num++;
            }
        }
        numberOfStaff = num;

        staffList = new Employee[numberOfStaff];

        file.clear();              
        file.seekg(0, ios::beg);     

        int index = 0;
        while (getline(file, str) && index < numberOfStaff) {
            if (!str.empty()) {
                staffList[index].setName(str);
                index++;
            }
        }
        
        cout << "\nNumber of staff loaded = " << numberOfStaff << endl;
        file.close();
    }

    void getSalaryFromFile(string filename) {
        fstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening " << filename << endl;
            return;
        }

        string str;
        double salaryValue;

        for (int i = 0; i < numberOfStaff; i++) {
            if (getline(file, str)) {
                salaryValue = stof(str); 
                staffList[i].setSalary(salaryValue);

                staffList[i].displayStaffInformation();
            }
        }
        file.close();
    }

    void showAllStaff() {
        cout << "\n--- Displaying All Staff Names ---" << endl;
        for (int i = 0; i < numberOfStaff; i++) {
            cout << i + 1 << ". " << staffList[i].getName() << endl;
        }
        cout << "Total Number of Staff: " << numberOfStaff << endl;
    }
};

int main() {
    cout << "=== Testing Employee Class ===" << endl;
    Employee e1("Nurazlan", 1800);
    e1.displayStaffInformation();
    e1.incrementSalary(0.20);
    cout << "After salary increment:" << endl;
    e1.displayStaffInformation();
    
    cout << endl;
    Employee e2("Donald James", 3500);
    e2.incrementSalary(0.20); 
    
    cout << "\n=== Testing Company Class (File I/O) ===" << endl;
    Company astro;
    
    cout << "Reading staff name from text file...";
    astro.getDataFromFile("staff.txt");
    astro.showAllStaff();
    
    cout << "\nReading salary from text file & displaying information:" << endl;
    astro.getSalaryFromFile("salary.txt");
    
    return 0;
}