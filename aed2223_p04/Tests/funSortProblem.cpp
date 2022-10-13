#include "funSortProblem.h"
#include <algorithm>
#include <limits.h>

FunSortProblem::FunSortProblem() {}


//-----------------------------------------------------------------

// TODO
void sortByPrice(vector<Product> &products){
    int i , key, j;
    for(i = 1 ; i < products.size(); i++){
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
    int len = arrival.size();
    unsigned usedPlatforms = 1;
    unsigned final = 1;
    int a = 1;
    int d = 0;
    vector<float> order_A = arrival;
    vector<float> order_D = departure;
    sort(order_A.begin(), order_A.end());
    sort(order_D.begin(), order_D.end());

    while (a < len && d < len) {
        if (order_A[a] <= order_D[d]) {
            usedPlatforms += 1;
            a++;
        } else if (order_A[a] > order_D[d]) {
            usedPlatforms -= 1;
            d++;
        }

        if (usedPlatforms > final) {
            final = usedPlatforms;
        }
    }
    return final;
}

//TODO
unsigned FunSortProblem::numInversions(vector <int> v) {
    return 0;
}

// TODO
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
}

