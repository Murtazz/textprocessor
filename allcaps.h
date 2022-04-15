#ifndef __ALLCAPS_H__
#define __ALLCAPS_H__
#include <iostream>
#include <string>
#include "textprocess.h"

class AllCaps: public TextProcessor {
    TextProcessor *t;
  public:
    AllCaps(TextProcessor *t);
    ~AllCaps() override;
    void setSource(std::istream *inp) override;
    std::string getWord() override;
};

#endif