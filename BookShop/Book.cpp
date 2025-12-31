#include <iostream>
#include <string>

using namespace std;

class Book {
    int isbn;
    string title;
    int price;
public:
    Book(): isbn(0), title(""), price(0) {}
    Book(int i, const char* t, int p): isbn(i), title(t), price(p) {}
    int getISBN() const { return isbn; }
    string getTitle() const { return title; }
    int getPrice() const { return price; }
    void setPrice(int p) { price = p; }
    void print() const {
        cout << "ISBN: " << isbn << ", Title: " << title << ", Price: " << price << endl;
    }
};
