#include "Bookstore.h"

#include <bits/stdc++.h>
Bookstore::Bookstore() : catalog(BookCatalogItem("", "", 0)) {}

void Bookstore::generateCatalog(vector<Book *> inventory) {
    catalog.makeEmpty();
    for (auto & b : inventory) {
        catalog.insert(b);
    }
}

BST<BookCatalogItem> Bookstore::getCatalog() const {
    return catalog;
}


//=============================================================================
//TODO:

bool cmpBooks(Book* &b1, Book* &b2){

    
}
vector<Book *> Bookstore::getBooksBy(string a) const {
    vector<Book*> result;
    BSTItrIn<BookCatalogItem> it(catalog);
    while(!it.isAtEnd()){
        if(it.retrieve().getAuthor() == a){
            result.push_back(it.retrieve().getBook());
        }
        it.advance();
    }
    return result;
}

//TODO:
vector<Book *> Bookstore::getBooksBetween(unsigned y1, unsigned y2) const {
    vector<Book *> result;
    BSTItrIn<BookCatalogItem> it(catalog);
    while(!it.isAtEnd()){
        if(it.retrieve().getYear() >= y1 && it.retrieve().getYear() <= y2){
            result.push_back(it.retrieve().getBook());
        }
        it.advance();
    }

    return result;
}
