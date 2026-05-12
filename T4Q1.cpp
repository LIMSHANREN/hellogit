#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Purchase {
private:
    int qty; 
    float price;
    string itemName;
    float total;

public:
    Purchase(string name, int quantity, float p);
    
    void set_data(string name, int quantity, float p);
    void calculate();
    void print();
};


Purchase::Purchase(string name, int quantity, float p) {
    set_data(name, quantity, p);
}

void Purchase::set_data(string name, int quantity, float p) {
    itemName = name;
    qty = quantity;
    price = p;
    total = 0.0;
}

void Purchase::calculate() {
    total = qty * price;
}

void Purchase::print() {
    cout << "----------------------------\n" << 
         left << setw(15) << "Item" << ": " << itemName << "\n" <<
         left << setw(15) << "Subtotal" << ": RM" << fixed << setprecision(2) << total << "\n" <<
         "----------------------------\n" << endl;
}

int main() {
    string name;
    int quantity;
    float price;

    Purchase p1("None", 0, 0.0);

    cout << "Welcome to the Purchase System (Enter 'q' to quit)" << endl;
    
    while(true){
        cout << "Enter item name: ";
        cin >> name;
        if(name == "q" || name == "Q") break;

        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Enter price: RM";
        cin >> price;

        if(price < 0 || quantity < 0){
            cout << "Invalid input! Try again." << endl;
            continue;
        }

        p1.set_data(name, quantity, price);
        p1.calculate();
        p1.print();
    } 

    cout << "Exiting system. Thank you!" << endl;
    return 0; 
}