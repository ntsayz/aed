#include "funSortProblem.h"
#include <algorithm>
#include <limits.h>

FunSortProblem::FunSortProblem() {}


//-----------------------------------------------------------------

// TODO
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
void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {
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

// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    return 0;
}


// TODO
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    return 0;
}

//TODO
unsigned FunSortProblem::numInversions(vector <int> v) {
    return 0;
}

// TODO
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
}

