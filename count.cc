#include <iostream>
#include <string>
#include "textprocess.h"
#include "count.h"
using namespace std;

Count::Count(TextProcessor *t, char c, int n): t{t}, c{c}, n{n} {}  // ctor
    
Count::~Count() {  // dtor
    delete t;
}
    
void Count::setSource(std::istream *inp) { t->setSource(inp); }

std::string Count::getWord() {
    string word = t->getWord();
    int wlen = word.size();
    for (int i = 0; i < wlen; ++i) {
        if (c == word[i]) {
            word.replace(i, 1, to_string(n));  // replace char c with n
            ++n;
        }
    }
    return word;
}