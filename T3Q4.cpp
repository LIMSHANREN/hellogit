#include <iostream>

void getInputIntoVector(float* pArray, int size ); 
void displayVector(float* pArray, int size);

using namespace std;



int main() {
    int size;
    cout << "Enter how many numbers to enter >> " ;
    cin >> size;
    float *pArray = new float[size];
    getInputIntoVector(pArray, size);
    displayVector(pArray, size);


    return 1;
}

void displayVector(float* pArray, int size){
    cout << "\nNumber of elements in array = " << size << endl;
    cout << "\nDisplay data in array" << endl;
    for(int i = 0; i < size; i++){
        cout << pArray[i] << " ";
    }
    cout << endl;
}

void getInputIntoVector(float* pArray, int size ){
    for(int i = 0; i < size; i++){
        cout << "\nEnter element A[" << i << "]" << " = ";
        cin >> pArray[i] ;

    }
}