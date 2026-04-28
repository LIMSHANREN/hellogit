#include <iostream>
using namespace std;
void drawBox(int w);
void drawFullLine(int w);
void drawEmptyLine(int w);

int main() {
    int width;
    while(true){
        cout << "\n Enter the side of the square box (1-16): ";
        if(!(cin >> width) || width < 1 || width > 16) {
            cout << "Ending program. Only integer values between 1 and 16 accepted." << endl;
            break;
        }
        drawBox(width);
    }
    return 0;
}

void drawBox(int w){
        drawFullLine(w);
        for(int i = 0; i < w-2; i++) {
            drawEmptyLine(w);
        }
        if(w>1) drawFullLine(w);
} 


void drawFullLine(int w){
    for(int i = 0; i < w; i++){
        cout << "* ";
    }
    cout << endl;
}

void drawEmptyLine(int w){
    cout << "* ";
    for (int i = 0; i < w-2; i++){
        cout << "  ";
    }
    if(w > 1) cout << "*";
    cout << endl; 
}