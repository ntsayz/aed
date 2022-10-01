// AED 2022/2023 - Aula Pratica 02
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 25/09/2022]

#include "funWithComplexity.h"

// ----------------------------------------------------------
// Exercicio 4: Sequencias
// ----------------------------------------------------------
// TODO
int FunWithComplexity::maxSubArray(const vector<int> & v) {
    int maxSum = 0;
    int currSum = 0;
    int currEnd = v[0];
    int currStart = v[0];
    int bestSum = 0;

    for(int i = 0; i < v.size(); i++){
        if(currSum <= 0){
            currStart = currEnd;
            currSum = v[i];
        }else{
            currSum += v[i];
        }

        if(currSum >= maxSum){
            bestSum = currSum;
        }
    }

    return maxSum;
}


// ----------------------------------------------------------
// Exercicio 5: Analisando um rio
// ----------------------------------------------------------
// TODO
int FunWithComplexity::river(const vector<int> & v, int k, int t) {
    return 0;
}

// ----------------------------------------------------------
// Exercicio 6: Espiral de Números
// ----------------------------------------------------------
// TODO
pair<int, int> FunWithComplexity::spiral(int n) {
    pair<int, int> ans = {0, 0};
    return ans;
}

// ----------------------------------------------------------
// Exercicio 8: Caderno Quadriculado
// ----------------------------------------------------------
// TODO
long long FunWithComplexity::gridSum(int a, int b) {
    return 0;
}