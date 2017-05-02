#ifndef A_H
#define A_H

#include "B.h"

class A
{
  public:
    A() { value = 0; }
    void subscribe(B* b) { this->b = b; }
    void  publish(int c) { b->update(c); }
    void   update(int c) { value = c; }
  private:
    B* b;
    int value;
};

#endif
