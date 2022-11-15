#include "Bookstore.h"

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
vector<Book *> Bookstore::getBooksBy(string a) const {
    vector<Book *> result;
    /*edd
     * ue procura no catálogo da galeria (dado-membro catalog) todos os livros do autor a, independentemente
do seu título e ano de publicação, retornando-os num vetor. Este deve estar ordenado por ordem
decrescente de ano de publicação do livro e, em caso de igualdade, por ordem alfabética de título do
livro. Caso não se encontrem quaisquer livros do autor, o vetor retornado pela função estará vazio*/
    auto it = catalog.begin();
    while(it != catalog.end()){
        it++;
    }
    return result;
}

//TODO:
vector<Book *> Bookstore::getBooksBetween(unsigned y1, unsigned y2) const {
    vector<Book *> result;
    return result;
}
