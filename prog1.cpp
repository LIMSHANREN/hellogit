#include <iostream>
using namespace std;

int main() {
    int selection, x1, x2;

    while (true) {
        cout << "\nSimple calculator" << endl;
        cout << "Enter option: 1)+ 2)- 3)* 4)/ 5) mod(x1, x2) -1) Exit" << endl;
        cout << "Your selection -> ";
        cin >> selection;

        if (selection == -1) break;

        cout << "Enter first number: ";
        cin >> x1;
        cout << "Enter second number: ";
        cin >> x2;
 
        switch (selection) {
            case 1: cout << x1 << " + " << x2 << " = " << x1 + x2 << endl; break;
            case 2: cout << x1 << " - " << x2 << " = " << x1 - x2 << endl; break;
            case 3: cout << x1 << " * " << x2 << " = " << x1 * x2 << endl; break;
            case 4: 
                if (x2 != 0) cout << x1 << " / " << x2 << " = " << x1 / (double)x2 << endl; 
                else cout << "Error: Division by zero!" << endl;
                break;
            case 5: cout << x1 << " mod " << x2 << " = " << x1 % x2 << endl; break;
            default: cout << "Invalid selection!" << endl;
        }
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
    }
    return 0;
}