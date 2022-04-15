#include <iostream>
#include <string>
#include "textprocess.h"
#include "allcaps.h"
using namespace std;

AllCaps::AllCaps(TextProcessor *t): t{t} {}  // ctor
    
AllCaps::~AllCaps() {  // dtor
    delete t;
}
    
void AllCaps::setSource(std::istream *inp) { t->setSource(inp); }

std::string AllCaps::getWord() {
    string word = t->getWord();
    int wlen = word.size();
    for (int i = 0; i < wlen; ++i) {
        word[i] = toupper(word[i]);  // turn the whole word to uppercase
    }
    return word;
}