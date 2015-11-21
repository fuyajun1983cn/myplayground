/**
  Task: Print numbers from 1 to 1000 without using
  any loop or conditional statements. Don't just
  write the printf() or cout statement 1000 times.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

/**
 * Solution 1
 * compile cmd:  g++ -std=c++0x -ftemplate-depth=1001 test2.cpp
 */

template <int N>
struct NumberGenerate {
  static void out(ostream& os)
  {
    NumberGenerate<N-1>::out(os);
    os<< N << endl;
  }
};

template <>
struct NumberGenerate<1> {
  static void out(ostream& os)
  {
    os<< 1 <<endl;
  }
};

/**
 * Solution 2:
 */
void f(int j)
{
    static void (*const ft[2])(int) = { f, exit };

    printf("%d\n", j);
    ft[j/1000](j + 1);
}

/**
 * Solution 3:
 * 1000 = 5 * 5 * 5 * 8
 */
int i = 0;
void p()    { printf("%d\n", ++i); }
void a()    { p();p();p();p();p(); }
void b()    { a();a();a();a();a(); }
void c()    { b();b();b();b();b(); }
//main() { c();c();c();c();c();c();c();c(); return 0; }

/**
 * Solution 4:
 */
static int current = 1;

struct print
{
    print() { std::cout << current++ << std::endl; }
};

int main(int argc, char *argv[])
{
  // NumberGenerate<1000>::out(cout);
  //f(1);
  /*
  {
    c();
    c();
    c();
    c();
    c();
    c();
    c();
    c();
  }
  */

  print p[1000];
  
  return 0;
}

