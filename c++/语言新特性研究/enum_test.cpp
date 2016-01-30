#include <iostream>

using namespace std;

enum class A { a = 1, b = 100 };  //scoped enum with default underlying type of 'int'
enum class B : char { a = 1, b }; //scoped enum with underlying type of 'char'
enum C { a = 1, b = 100 }; //unscoped enum with no fixed underlying type
enum D : long { a2 = 1, b2 };  //unscoped enum with underlying type of 'long'

int main(int argc, char *argv[])
{
    A e = A::a;
 //   B e1 = A::a;
//    int x1 = A::a;

    bool b3 = A::a <= A::b;

}
