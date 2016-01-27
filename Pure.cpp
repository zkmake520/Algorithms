#include <stdio.h>

class Base1
{
  public:

  virtual int virt1() { return 100; }

  int data1;
};

class Derived : public Base1
{
  public:

  virtual int virt1() { return 150; }

  int derivedData;
};

int Global1( Base1 * b1 )
{
  return b1->virt1();
}

main1()
{
  Derived * d = new Derived;

  printf( "%d %d\n", d->virt1(), Global1( d ));
}


