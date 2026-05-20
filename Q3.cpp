#include <iostream>
using namespace std;

#include <iostream>

class Book {
private:
    string title;
    int pages;

public:
    Book() { title="None"; pages=0; }
    Book(string t, int p) : title(t), pages(p) {}

    void print(int id) const {
        cout <<id  <<"  Title: " << title << ", Pages: " << pages << endl;
    }
};

class Library {
private:
    Book* pbooks; // Library has many books

public:
    //Library() : books{Book("Book 1", 100), Book("Book 2", 200), Book("Book 3", 300)} {}
    Library(int numBook)
    {
        pbooks = new Book[ numBook ] ;
    }

    void printBooks() const {
        for (int i = 0; i < 3; ++i) {
            pbooks[i].print(i);
        }
    }

    void addBook( Book bb, int i)
    {
        pbooks[i] = bb;
    }

};

int main() {
    Library library(3);
    library.printBooks();
    
    Book bb[3];
    bb[0] = Book("Hello Guys", 200) ;
    bb[1] = Book("Bye Bye", 300) ;
    bb[2] = Book("The book", 350) ;
    // Alternative is Book bb[3] = {  Book("Hello Guys", 200)  ,Book("Bye Bye", 300)  ,Book("The book", 350)   } ;
    
    for (int i=0; i<3 ; i++)
      { library.addBook( bb[i], i) ; }

    cout <<endl;
    library.printBooks();

    // Error added below, fix it
    library.addBook( Book("C++ Is Fun", 800), 1 ) ;
    library.printBooks();
    Book b1("My book is good", 500);
    Book b2 = Book() ;
    b2.print(5);

    Book* bookA = new Book[5] ;
    cout << b1.getBookTile();


    return 0;
}
