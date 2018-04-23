

#include <cstdio>

class Base
{
public:
  Base(){}
  ~Base(){}
  virtual void Say() const{puts("Base");}
};

class Derived : public Base
{
public:
  Derived(){}
  ~Derived(){}
  virtual void Say() const override {puts("Derived");}
};

int main(int argc, char const *argv[])
{
  Base *a = new Derived();
  a->Say();
  Base &b = Derived();
  b.Say();

  delete a;
  return 0;
}