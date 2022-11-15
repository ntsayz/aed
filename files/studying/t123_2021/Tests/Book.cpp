#include "Book.h"

/**
 * Classe Book
 */
Book::Book(string author, string title, unsigned year) :
        author(author), title(title), year(year) {}

string Book::getAuthor() const {
    return author;
}

string Book::getTitle() const {
    return title;
}

unsigned Book::getYear() const {
    return year;
}

ostream &operator<<(ostream &os, const Book &b) {
    os << b.author << " " << b.title << " " << b.year;
    return os;
}


/**
 * Classe BookCatalogItem
 */
BookCatalogItem::BookCatalogItem(Book *bookItem) : bookItem(bookItem) {}

BookCatalogItem::BookCatalogItem(string author, string title, unsigned year) {
    bookItem = new Book(std::move(author), title, year);
}

Book *BookCatalogItem::getBook() const {
    return bookItem;
}

string BookCatalogItem::getAuthor() const {
    return bookItem->author;
}

string BookCatalogItem::getTitle() const {
    return bookItem->title;
}

unsigned BookCatalogItem::getYear() const {
    return bookItem->year;
}

ostream &operator<<(ostream &os, const BookCatalogItem &b) {
    os << b.getAuthor() << " " << b.getTitle() << " " << b.getYear();
    return os;
}


//=============================================================================
//TODO:
bool BookCatalogItem::operator<(const BookCatalogItem &bci1) const {
    return true;
}
