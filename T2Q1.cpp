#include<iostream>

using namespace std;

int factorial(int num);

int main(){
    int x=4;
    cout << "\n Factorial of " << x << "= " << factorial(x);

    return 0;
}

int factorial(int num){
    int result=1;

    for(;num>1;num--){
        result*=num;
    }
    return result;
}