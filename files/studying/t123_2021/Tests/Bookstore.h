#ifndef AED2122_CI1_BOOKSTORE_H
#define AED2122_CI1_BOOKSTORE_H

#include <string>
#include "bst.h"
#include "Book.h"

using namespace std;

class Bookstore {
    BST<BookCatalogItem> catalog;
public:
    Bookstore();
    void generateCatalog(vector<Book *> inventory);
    BST<BookCatalogItem> getCatalog() const;
    vector<Book *> getBooksBy(string a) const;
    vector<Book *> getBooksBetween(unsigned y1, unsigned y2) const;
};

#endif //AED2122_CI1_BOOKSTORE_H
