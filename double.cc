#include <iostream>
#include <string>
#include "textprocess.h"
#include "double.h"
using namespace std;

Double::Double(TextProcessor *t, string dupeS, int n): t{t}, dupeS{dupeS}, n{n} {} // ctor
    
Double::~Double() { // dtor
    delete t;
}
    
void Double::setSource(std::istream *inp) { t->setSource(inp); }

std::string Double::getWord() {
    string word;
    if (n % 2 == 0) {  // if 0 or double achieved
        word = t->getWord();  // go to next word
        dupeS = word;
    } else {
        word = dupeS; // keep the same word to duplicate
    }
    ++n;  // add one to double count
    return word;
}
