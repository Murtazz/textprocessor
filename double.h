#ifndef __DOUBLE_H__
#define __DOUBLE_H__
#include <iostream>
#include <string>
#include "textprocess.h"

class Double: public TextProcessor {
    TextProcessor *t;   
    std::string dupeS;  // current duplication word
    int n;  // count for duplication
  public:
    Double(TextProcessor *t, std::string dupeS, int n = 0);  // n is defaulted to 0 for our use
    ~Double() override;
    void setSource(std::istream *inp) override;
    std::string getWord() override;
};

#endif