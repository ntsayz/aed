#include "funSortProblem.h"
#include <algorithm>

FunSortProblem::FunSortProblem() {}


//-----------------------------------------------------------------
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

    for(int i = 0 ; i < products.size(); i++){
        if(products[i].getPrice() ==  <)
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

