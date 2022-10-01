// AED 2022/2023 - Aula Pratica 01
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 18/09/2022]

#include "funWithCycles.h"
#include <map>
#include <algorithm>
// ----------------------------------------------------------
// Exercicio 1: Palindromos
// ----------------------------------------------------------
// TODO
bool FunWithCycles::palindrome(const std::string & s) {
    unsigned length = s.size();
    for (unsigned i = 0; i < length/2; i++)
        if (s[i] != s[length-i-1])
            return false;
    return true;
}

// ----------------------------------------------------------
// Exercicio 2: Frases Palindromo
// ----------------------------------------------------------
// TODO


bool FunWithCycles::palindromeSentence(const std::string & s) {
    std::string s1 = "";
    for(int i = 0 ; i < s.size(); i++){
        if(!isalpha(s[i])) continue;
        s1+= tolower(s[i]);
    }
    return palindrome(s1);
}


// ----------------------------------------------------------
// Exercicio 3: Numeros Interessantes
// ----------------------------------------------------------
// TODO
int FunWithCycles::nextInterestingNumber(int n, int sum) {
    for(int i = n+1; i < 1000000000; i++){
        if (digitSum(i) == sum) return i;
    }
    return 0;
}

// Esta funcao auxiliar devera devolver a soma dos digitos de n
// TODO
int FunWithCycles::digitSum(int n) {
    if(n <=0) return n;
    int sum = 0;
    while(n !=0){
        sum += n%10;
        n = n/10;
    }
    return sum;
}

// ----------------------------------------------------------
// Exercicio 4: O Inverno esta a chegar
// ----------------------------------------------------------
// TODO
int FunWithCycles::winter(const vector<int>& v) {
    std::vector<int> diff;
    for(int i =0 ; i < v.size()-1 ; i++){
        diff.push_back(v[i+1] - v[i]);
    }
    int c =0, max = 0;
    for(int i = 0; i < diff.size(); i++){
        if(diff[i] < 0){
            c++;
            if(c >= max ) max = c;
        }else{
            c = 0;
        }
    }
    return max;
}


// ----------------------------------------------------------
// Exercicio 5: Brincando com vectores
// ----------------------------------------------------------

// a) count
// TODO
int FunWithCycles::count(const vector<int> & v, int n) {
    int count = 0;
    for(int i = 0 ; i < v.size() ; i++){
        if(v[i] == n) count++;
    }
    return count;
}

// b) hasDuplicates
// TODO
bool FunWithCycles::hasDuplicates(const vector<int> & v) {
    std::map<int,int> m;
    for(int i = 0; i < v.size(); i++){
        m[v[i]] = 0;
    }
    for(int i = 0; i < v.size(); i++){
        m[v[i]] += 1;
        if(m[v[i]] >= 2) return true;
    }
    return false;
}

// c) removeDuplicates
// TODO

void FunWithCycles::removeDuplicates(vector<int> & v) {
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }
    v.erase(end, v.end());
}



// d) merge
// TODO
vector<int> FunWithCycles::merge(const vector<int> & v1, const vector<int> & v2) {
    vector<int> ans;
    int max = v1.size();
    if(max < v2.size()) max = v2.size();
    ans = v1;
    ans.insert( ans.end(), v2.begin(), v2.end() );
    sort(ans.begin(), ans.end());
    return ans;
}

// ----------------------------------------------------------
// Exercicio 6: Brincando com numeros primos
// ----------------------------------------------------------

// a) isPrime
// TODO
bool FunWithCycles::isPrime(int n) {
    for(int i = 2; i <= sqrt(n); i++ ){
        if(n%i == 0) return false;
    }
    return true;
}

// b) factorize
// TODO
vector<int> FunWithCycles::factorize(int n) {
    vector<int> ans;
    return ans;
}

// c) listPrimes
// TODO
vector<int> FunWithCycles::listPrimes(int n) {
    vector<int> ans;
    return ans;
}


// ----------------------------------------------------------
// Exercicio 7: Numeros interessantes (versao desafio)
// ----------------------------------------------------------
// TODO
long long FunWithCycles::fastNextInterestingNumber(long long n, int sum) {

    return 0;
}
