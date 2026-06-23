#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string employeeName;
    string companyName;
    string departmentName;
    unsigned int employeeId;
    double annualSalary;

public:
    Employee(string name, unsigned int id, double salary)
        : employeeName(name), employeeId(id), annualSalary(salary), companyName(""), departmentName("") {}

    virtual ~Employee() {}

    void SetCompanyName(string compName) {
        companyName = compName;
    }

    void SetDepartmentName(string deptName) {
        departmentName = deptName;
    }

    string GetEmployeeName() const {
        return employeeName;
    }

    unsigned int GetEmployeeId() const {
        return employeeId;
    }

    double GetAnnualSalary() const {
        return annualSalary;
    }

    virtual double calculateBonus() = 0;
};

class Manager : public Employee {
private:
    unsigned int numExecutives;
    double calculatedBonus;    

public:
    using Employee::Employee;

    void setNumExecutives(unsigned int num) {
        numExecutives = num;
    }

    virtual double calculateBonus() override {
        calculatedBonus = annualSalary * (numExecutives * 0.15);
        return calculatedBonus;
    }
};

class Engineer : public Employee {
private:
    unsigned int numTechnicians; 
    double calculatedBonus;     

public:
    using Employee::Employee;

    virtual ~Engineer() override = default;

    void setNumTechnicians(unsigned int num) {
        numTechnicians = num;
    }

    virtual double calculateBonus() override {
        calculatedBonus = annualSalary * (numTechnicians * 0.10);
        return calculatedBonus;
    }
};

int main() {
    string compName, deptName;
    
    cout << "Enter Company Name: ";
    getline(cin, compName);
    cout << "Enter Department Name: ";
    getline(cin, deptName);

    string mName;
    unsigned int mId, mExecs;
    double mSalary;
    
    cout << "\n--- Enter Manager Details ---" << endl;
    cout << "Name: ";
    getline(cin >> ws, mName);
    cout << "ID: ";
    cin >> mId;
    cout << "Annual Salary: ";
    cin >> mSalary;
    cout << "Number of Executives supervised: ";
    cin >> mExecs;

    Manager mgr(mName, mId, mSalary);
    mgr.SetCompanyName(compName);
    mgr.SetDepartmentName(deptName);
    mgr.setNumExecutives(mExecs);

    string eName;
    unsigned int eId, eTechs;
    double eSalary;
    
    cout << "\n--- Enter Engineer Details ---" << endl;
    cout << "Name: ";
    getline(cin >> ws, eName);
    cout << "ID: ";
    cin >> eId;
    cout << "Annual Salary: ";
    cin >> eSalary;
    cout << "Number of Technicians assigned: ";
    cin >> eTechs;

    Engineer eng(eName, eId, eSalary);
    eng.SetCompanyName(compName);
    eng.SetDepartmentName(deptName);
    eng.setNumTechnicians(eTechs);

    cout << "\n================ OUTPUT ================" << endl;
    cout << "Manager: " << mgr.GetEmployeeName() << " (ID: " << mgr.GetEmployeeId() << ")" << endl;
    cout << "Salary: $" << mgr.GetAnnualSalary()+mgr.calculateBonus() << endl;

    cout << "\nEngineer: " << eng.GetEmployeeName() << " (ID: " << eng.GetEmployeeId() << ")" << endl;
    cout << "Salary: $" << eng.GetAnnualSalary()+eng.calculateBonus() << endl;
    cout << "========================================" << endl;

    return 0;
}