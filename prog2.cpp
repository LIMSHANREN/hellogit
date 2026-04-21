#include<iostream>

using namespace std; 
int main(){
    double mass, height, bmi;
        cout << "Get weight in kg: ";
        cin >> mass;
        cout << "Get height in meter: ";
        cin >> height;

        bmi = mass / (height * height);
        cout << "Your bmi = " << bmi << endl;

    if (bmi < 18.5) cout << "Your weight category is: Underweight" << endl;
    else if (bmi < 25) cout << "Your weight category is: Normal Weight" << endl;
    else if (bmi < 30) cout << "Your weight category is: Overweight" << endl;
    else cout << "Your weight category is: Obesity" << endl;
return 0;
}