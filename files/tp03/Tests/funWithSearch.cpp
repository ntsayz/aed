// AED 2022/2023 - Aula Pratica 03
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 02/10/2022]

#include "funWithSearch.h"
#include <climits>
#include <algorithm>

// ----------------------------------------------------------
// Exercicio 1: Pesquisa Elementar
// ----------------------------------------------------------
// TODO
int FunWithSearch::search(const vector<int> & v, int key) {
    int lower = 0,  upper = v.size() -1 , middle;
    while(lower <= upper){
        middle =  (upper + lower) /2;
        if(key < v[middle]) upper = middle -1 ;
        else if(key > v[middle]) lower = middle + 1 ;
        else return middle;
    }
    return -1;
}

// ----------------------------------------------------------
// Exercicio 2: Limite Inferior
// ----------------------------------------------------------
// TODO
int FunWithSearch::lowerBound(const vector<int> &v, int key) {

    //sequential search
    /*
    for(int i = 0 ; i < v.size(); i++){
        if(v[i] >= key) return i;
    }
    return -1;
     */

    // binary search
    int lower = 0,  upper = v.size() -1 , middle;
    while(true){
        if(v[upper] <= key) return -1;

        if(v[lower] >= key){
            return lower_bound(v.begin(), v.end(), v[middle]) - v.begin();
        }

        middle =  (upper + lower) /2;
        if(key < v[middle]) upper = middle -1 ;
        else if(key > v[middle]) lower = middle + 1;
        else{
            return -1;
        }

    }


}

// ----------------------------------------------------------
// Exercicio 3: Intervalos
// ----------------------------------------------------------
// TODO
int FunWithSearch::countRange(const vector<int> & v, int a, int b) {
    return 0;
}

// ----------------------------------------------------------
// Exercicio 4a: Viagem de mochila às costas (isPossible)
// ----------------------------------------------------------
// TODO
bool FunWithSearch::isPossible(const vector<int> & v, int x, int k) {
    vector<int> parts;
    for(int i = 0; i < v.size(); i++){
        
    }
    return false;
}

// ----------------------------------------------------------
// Exercicio 4b: Viagem de mochila às costas (partitions)
// ----------------------------------------------------------
// TODO
int FunWithSearch::partitions(const vector<int> & v, int k) {
    return 0;
}

// ----------------------------------------------------------
// Exercicio 5: Somas mais próximas
// ----------------------------------------------------------
// TODO
vector<int> FunWithSearch::closestSums(const vector<int> & v, const vector<int> & p) {
    vector<int> ans;
    return ans;
}

// ----------------------------------------------------------
// Exercicio 6: Jogo de strings
// ----------------------------------------------------------
// TODO
int FunWithSearch::stringGame(const string & a, const string & b, const vector<int> & p) {
    return 0;
}

// ----------------------------------------------------------
// Exercicio 7: Regras Quadriculadas
// ----------------------------------------------------------
// TODO
long long FunWithSearch::rules(int k, long long a, long long b) {
    return 0;
}