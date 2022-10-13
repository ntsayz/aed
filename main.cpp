#include <vector>
#include <iostream>

#include <string>
using namespace std;

class Product {
    string id;
    float price;
    float weight;
public:
    Product(string i, float p, float w);
    string getId() const;
    float getPrice() const;
    float getWeight() const;
    void operator=(const Product prod);
};

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


void sortByPrice(vector<Product> &products){
    int i , key, j;

    for(i = 0 ; i < products.size(); i++){
        key = products[i].getPrice();
        Product prod = products[i];
        j = i-1;
        while(j>= 0 && products[j].getPrice() > key){
            products[j+1] = products[j];
            j--;
        }
        products[j+1]= prod;
    }
}
// TODO
void expressLane(vector<Product> &products, unsigned k) {
    sortByPrice(products);
    int j = 1;
    int size = products.size();
    for(int i = 0; i < size-j; i++){
        if(products[i].getPrice() == products[i+1].getPrice()){
            if(products[i].getWeight() < products[i+1].getWeight()) products.erase(products.begin()+ i +1);
            else products.erase(products.begin() + i );
            j++;
        }
    }
    int i = products.size();
    while(products.size() > k){
        products.erase(products.begin() + i-1 );
        i--;
    }
}

int main() {
  Product p1("apples",9.9,100);
    Product p2("oranges",4.2,100 );
    Product p3("kiwis",4.2,200);
    Product p4("bananas",2.0,300);
    Product p5("lemons",2.0,200);
    Product p6("grapes",1.6,400);

    vector v1 = {p1, p2, p3, p4, p5, p6};

    expressLane(v1,4);
    for(Product prod: v1){
        std::cout << prod.getId() << "\n";
    }
    std::cout << v1.size() << " --> 4 \n\n";

    vector v2= {p1, p2, p3, p4, p5, p6};

    expressLane(v2,2);
    for(Product prod: v2){
        std::cout << prod.getId() << "\n";
    }
    std::cout << v2.size() << " --> 2\n\n";

    vector v4= {p3, p4, p1, p2, p6, p5};
    expressLane(v4,1);
    for(Product prod: v4){
        std::cout << prod.getId() << "\n";
    }
    std::cout << v4.size() << " --> 1\n\n";
  return 0;
}