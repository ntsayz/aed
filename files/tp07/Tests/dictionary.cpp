#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

set<WordMean> Dictionary::getWords() const {
	return words;
}

void Dictionary::addWord(WordMean wm)  {
    words.insert(wm);
}

// ---------------------------------------------

//TODO
bool WordMean::operator< (const WordMean& wm2) const {
     return true;
}


//TODO
void Dictionary::readFile(ifstream &f) {

}

//TODO
string Dictionary::consult(string w1, WordMean& previous, WordMean& next) const {
    return "";
}

//TODO
bool Dictionary::update(string w1, string m1) {
    return true;
}

//TODO
void Dictionary::print() const {
}
