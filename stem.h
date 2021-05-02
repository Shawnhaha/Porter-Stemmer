#ifndef STEM_H
#define STEM_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Stem {
   public:
      bool cons(string str, int i);
      int m(string str);
      bool vowel(string str);
      bool cvc(string str,int i);
      bool end(string str, string end);
      string step1ab(string str);
      string step1c(string str);
      string step2(string str);
      string step3(string str);
      string step4(string str);
      string step5(string str);
      string stem(string str);
      void inout(string str);
};

#endif
