#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    float price;
    string currency;

public:
    Book(string a_title, float a_price, string a_currency) {
        title = a_title;
        price = a_price;
        currency = a_currency;
    }

    float getPrice(void) {
        if(currency=="USD") return price*3.948;
        else if(currency=="EUR") return price*4.62;
        else if(currency=="RM") return price;
        else{
            cout << "Invalid currency!" << endl;
            return -1;
        }
    }
    string getTitle(void){
        return title;
    }
    void showPriceTitle(void){
        if(price==-1) {
            cout << "Cannot display price and title due to invalid currency." << endl;
        } else {
            cout << "Title of book: " << getTitle() << endl;
            cout << "Price in RM: " << getPrice() << endl;
        }
    }
};


int main() {
    Book b1("C++ is Fun", 50.0, "RM");
    cout << "\nI just bought the book " << b1.getTitle() << endl;
    b1.showPriceTitle();

    cout << endl;
    Book b2("Snow White", 50.0, "USD");
    cout << "\nI just bought the book" << b2.getTitle() << endl;
    b2.showPriceTitle();

    return 0;
}
