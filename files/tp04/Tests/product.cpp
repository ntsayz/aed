#include "product.h"

Product::Product(string i, float p, float w): id(i), price(p), weight(w) {}

string Product::getId() const {
    return id;
}

float Product::getPrice() const {
    return price;
}

float Product::getWeight() const {
    return weight;
}
void Product::operator=(const Product prod){
    id = prod.getId();
    price = prod.getPrice();
    weight = prod.getWeight();
}
