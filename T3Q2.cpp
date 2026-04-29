#include <iostream>

using namespace std;

void swap(int* num1,int* num2);


int main() {
    int x=2,y=4;
    cout << "\n x = " << x;
    cout << "\n y = " << y;
    swap(x,y);
    cout << "\n\n After swapping " << endl;
    cout << "\n x = " << x;
    cout << "\n y = " << y;

    return 0;
}

void swap(int* num1, int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
