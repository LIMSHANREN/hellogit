#include <iostream>
using namespace std;

int main() {
    int num;
    
    while (true) {
        cout << "Enter the length of the side of the square between 1 to 20 (any other value to end): ";
        
        if (!(cin >> num) || num < 1 || num > 20) {
            break;
        }

        for (int rows = 0; rows < num; rows++) {
            for (int columns = 0; columns < num; columns++) {
                cout << "* ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << "Ending program. Only integer values between 1 and 20 accepted." << endl;
    
    return 0;
}