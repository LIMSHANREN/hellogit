#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    double salary;

public:
    // 默认构造函数
    Employee() {
        name = "";
        salary = 0.0;
    }

    // 带参数的构造函数
    Employee(string name, double a_salary) {
        this->name = name;
        this->salary = a_salary;
    }

    string getName() { return name; }
    void setName(string a_name) { name = a_name; }
    
    double getSalary() { return salary; }
    void setSalary(double a_salary) { salary = a_salary; }

    // 显示员工信息
    void displayStaffInformation() {
        cout << "Staff Name: " << name << ", Salary: RM " << salary << endl;
    }

    // 涨薪逻辑：只有当薪水低于 RM2000 时，才允许增加指定比例（如 0.20 代表 20%）
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
    Employee* staffList; // 动态 Employee 对象数组指针

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

    // 1. 从 staff.txt 中读取名字并统计人数
    void getDataFromFile(string filename) {
        fstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening " << filename << endl;
            return;
        }

        // 第一步：先数数一共有多少行（多少个员工）
        string str;
        int num = 0;
        while (getline(file, str)) {
            if (!str.empty()) { // 避免空行干扰
                num++;
            }
        }
        numberOfStaff = num;
        
        // 知道了人数，动态分配 Employee 数组
        staffList = new Employee[numberOfStaff];

        // 第二步：回到文件开头，真正把名字读进去
        file.clear();                 // 清除文件状态标志
        file.seekg(0, ios::beg);      // 将文件指针移回开头

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

    // 2. 从 salary.txt 中读取薪水，并和之前读入的员工一一对应
    void getSalaryFromFile(string filename) {
        fstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening " << filename << endl;
            return;
        }

        string str;
        double salaryValue;
        
        // 按照 getDataFromFile 统计出来的员工数，依次读取对应的薪水行
        for (int i = 0; i < numberOfStaff; i++) {
            if (getline(file, str)) {
                salaryValue = stof(str); // 将 string 转换为 float/double
                staffList[i].setSalary(salaryValue);
                
                // 顺便按题目要求即时显示出来
                staffList[i].displayStaffInformation();
            }
        }
        file.close();
    }

    // 3. 显示所有员工名字和总人数
    void showAllStaff() {
        cout << "\n--- Displaying All Staff Names ---" << endl;
        for (int i = 0; i < numberOfStaff; i++) {
            cout << i + 1 << ". " << staffList[i].getName() << endl;
        }
        cout << "Total Number of Staff: " << numberOfStaff << endl;
    }
};

int main() {
    // ---- 测试第一部分：单个 Employee 对象的涨薪测试 ----
    cout << "=== Testing Employee Class ===" << endl;
    Employee e1("Nurazlan", 1800);
    e1.displayStaffInformation();
    e1.incrementSalary(0.20); // 应该成功，因为 1800 < 2000
    cout << "After salary increment:" << endl;
    e1.displayStaffInformation();
    
    cout << endl;
    Employee e2("Donald James", 3500);
    e2.incrementSalary(0.20); // 应该失败并提示消息，因为 3500 >= 2000
    
    // ---- 测试第二部分：Company 类的文件读取测试 ----
    cout << "\n=== Testing Company Class (File I/O) ===" << endl;
    Company astro;
    
    cout << "Reading staff name from text file...";
    astro.getDataFromFile("staff.txt");
    astro.showAllStaff();
    
    cout << "\nReading salary from text file & displaying information:" << endl;
    astro.getSalaryFromFile("salary.txt");
    
    return 0;
}