#ifndef B_H
#define B_H

class A; //forward reference A

class B
{
  public:
    B() { value = 0; }
    void subscribe(A* a) { this->a = a; }
    void  publish(int c) { a->update(c); }
    void   update(int c) { value = c; }
  private:
    A* a;
    int value;
};

#endif
