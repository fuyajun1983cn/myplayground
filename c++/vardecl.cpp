
#include <iostream>

int sqr(int x)
{
  return x*x;
}
int main()
{
  char oldchoice,choice='y';
  int i=20;
  double electron_mass = 0.511;
  int mes[6]{33,22,34,0,89,3};
  bool flag = true;
  double *p = nullptr;
  decltype(i) j=9;
  auto positron_mass = electron_mass;
  auto f = sqr;
  //Sure, we could have written...
  //int (*f)(int)=&sqr;
  //but you see the point!
  std::cout << f(j) << '\n';
}
