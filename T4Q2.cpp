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
    void calculate(float&grandPrice);
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

void Purchase::calculate(float &grandPrice) {
    total = qty * price;
    grandPrice += total;
}

void Purchase::print() {
    cout << "---------------------------------\n" << 
         left << setw(15) << "Item" << ": " << itemName << "\n" <<
         left << setw(15) << "Subtotal" << ": RM" << fixed << setprecision(2) << total << "\n" <<
         "---------------------------------\n" << endl;
}

int main() {
    string name;
    int quantity;
    float price;
    int grandQty = 0; 
    float grandPrice = 0.0;

    Purchase p1("None", 0, 0.0);

    cout << "Welcome to the Purchase System (Enter 'q' to quit)" << endl;
    
    while(true){
        cout << left << setw(15) << "Enter item name" << ": ";
        cin >> name;
        if(name == "q" || name == "Q") break;

        cout << left << setw(15) << "Enter quantity" << ": ";
        cin >> quantity;
        cout << left << setw(15) << "Enter price" << ": RM";
        cin >> price;

        if(price < 0 || quantity < 0){
            cout << "Invalid input! Try again." << endl;
            continue;
        }

        p1.set_data(name, quantity, price);
        p1.calculate(grandPrice);
        p1.print();
        grandQty += quantity;
    } 
    cout << "==================================" << endl;
    cout << "            GRAND TOTAL           " << endl;
    cout << "==================================" << endl;
    cout << left << setw(15) << "Total Items" << ": " << grandQty << endl;
    cout << left << setw(15) << "Total Amount" << ": RM" << fixed << setprecision(2) << grandPrice << endl;
    cout << "==================================" << endl;

    cout << "Exiting system. Thank you!" << endl;
    return 0; 
}