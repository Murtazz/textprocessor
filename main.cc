#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "textprocess.h"
#include "echo.h"
#include "dropfirst.h"
#include "count.h"
#include "allcaps.h"
#include "double.h"
using namespace std;

int main () {
  cin.exceptions(ios::failbit|ios::eofbit);
  string s;

  try {
    while(1) {
      getline(cin,s);
      istringstream iss{s};
      iss.exceptions(ios::failbit);
      string fname;
      iss >> fname;
      istream *in = (fname == "stdin") ? &cin : new ifstream(fname.c_str());
      in->exceptions(ios::failbit|ios::eofbit);
  
      TextProcessor *tp = new Echo;
      string dec;
      try {
        while (true) {
          iss >> dec;
          if (dec == "dropfirst") {
            int n;
            iss >> n;
            tp = new DropFirst{tp, n};
          }
          else if (dec == "doublewords") {
            tp = new Double{tp, ""};
          }
          else if (dec == "allcaps") {
            tp = new AllCaps{tp};
          }
          else if (dec == "count") {
            char c;
            iss >> c;
            tp = new Count{tp, c};
          }
       } 
      }
      catch (ios::failure) {}

      tp->setSource(in);

      string word;

      try {
        int lineNum = 1;
        while (true) {
          word = tp->getWord();
          cout << lineNum++ << ' ' << word << endl;
        }
      }
      catch (ios::failure) {}
  
      if (in != &cin) delete in;
      delete tp;
    }
  }
  catch (ios::failure) {}
}
