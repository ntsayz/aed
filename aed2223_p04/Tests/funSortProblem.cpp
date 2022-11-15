#include "funSortProblem.h"
#include <algorithm>
#include <limits.h>

FunSortProblem::FunSortProblem() {}
void sortByWeight(vector<Product> &products){
    int i , key, j;
    for(i = 1 ; i < products.size(); i++){
        key = products[i].getWeight();
        Product prod = products[i];
        j = i-1;
        while(j>= 0 && products[j].getWeight() > key){
            products[j+1] = products[j];
            j--;
        }
        products[j+1]= prod;
    }
}

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
    for(int i = 1; i < size-j; i++){
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

int nge(const vector<unsigned> arr, int n, int val) {
    int next, i, j;
    for (i = 0; i < n; i++) {
        next = -1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] < arr[j] && arr[i] == val) {
                next = (int) arr[j];
                break;
            }
        }
        return next;
    }
}
// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    if(values.size() < nc) return -1;
    int currMax = values[0];
    vector<int> nc_Arr;
    nc_Arr.push_back(currMax);

    vector<unsigned> vals = values;
    sort(vals.begin(), vals.end());

    for(int i = 1; i < vals.size(); i++){
        if(vals[i] >= currMax){
            nc_Arr.push_back(vals[i]);
            if(nc_Arr.size() == nc) break;
            currMax = vals[i];
        }
    }
    sort(nc_Arr.begin(),nc_Arr.end());
    return nc_Arr[nc -1] - nc_Arr[0];
}


// TODO
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    int size = arrival.size();
    unsigned platformsBeingUsed = 1;
    unsigned platformsUsed = 1;
    int arr = 1 , dep = 0 ;
    vector<float> orderArr = arrival;
    vector<float> orderDep = departure;
    sort(orderArr.begin(), orderArr.end());
    sort(orderDep.begin(), orderDep.end());

    while (arr < size && dep < size){
        if (orderArr[arr] < orderDep[dep]) {
            platformsBeingUsed++;
            arr++;
        } else if (orderArr[arr] > orderDep[dep]) {
            platformsBeingUsed--;
            dep++;
        }
        if (platformsBeingUsed > platformsUsed) {
            platformsUsed = platformsBeingUsed;
        }
    }
    return platformsUsed;
}

//TODO
unsigned FunSortProblem::numInversions(vector <int> v) {
    return 0;
}

// TODO
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
}

