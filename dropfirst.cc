#include <iostream>
#include <string>
#include "textprocess.h"
#include "dropfirst.h"
using namespace std;

DropFirst::DropFirst(TextProcessor *t, int n = 0): t{t}, n{n} {}  // ctor

DropFirst::~DropFirst() { // dtor
    delete t;
}

void DropFirst::setSource(std::istream *inp) { t->setSource(inp); } 

string DropFirst::getWord() {
    string word = t->getWord();
    int wlen = word.size();
    while (wlen <= n) {
        return getWord();  // recurse over words with a lower length than n
    }
    return word.erase(0, n); // remove from the start of the string (0) to n
}
