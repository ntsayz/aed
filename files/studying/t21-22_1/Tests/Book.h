#ifndef AED2122_CI1_BOOK_H
#define AED2122_CI1_BOOK_H

#include <string>
#include <vector>
#include <ostream>

using namespace std;

class Book {
    string author;
    string title;
    unsigned year;
public:
    Book(string author, string title, unsigned year);
    string getAuthor() const;
    string getTitle() const;
    unsigned getYear() const;
    friend ostream &operator<<(ostream &os, const Book &b);
    friend class BookCatalogItem;
};

class BookCatalogItem {
    Book *bookItem;
public:
    BookCatalogItem(Book *bookItem);
    BookCatalogItem(string author, string title, unsigned year);
    Book *getBook() const;
    string getAuthor() const;
    string getTitle() const;
    unsigned getYear() const;
    friend ostream &operator<<(ostream &os, const BookCatalogItem &b);
    //TODO:
    bool operator<(const BookCatalogItem &bci1) const;
};

#endif //AED2122_CI1_BOOK_H
