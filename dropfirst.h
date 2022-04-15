#ifndef __DROPFIRST_H__
#define __DROPFIRST_H__
#include <iostream>
#include <string>
#include "textprocess.h"

class DropFirst: public TextProcessor {
    TextProcessor *t;
    int n;  // holds the amount to drop from the first 
  public:
    DropFirst(TextProcessor *t, int n);
    ~DropFirst() override;
    void setSource(std::istream *inp) override;
    std::string getWord() override;
};

#endif