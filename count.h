#ifndef __COUNT_H__
#define __COUNT_H__
#include <iostream>
#include <string>
#include "textprocess.h"

class Count: public TextProcessor {
    TextProcessor *t;
    char c;  // holds the char to find
    int n;   // counter to keep track
  public:
    Count(TextProcessor *t, char c, int n = 1);  // default n to 1 as it is for our use only
    ~Count() override;
    void setSource(std::istream *inp) override;
    std::string getWord() override;
};

#endif