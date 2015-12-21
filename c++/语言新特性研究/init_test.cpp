#include <iostream>
#include <string>

using namespace  std;

struct A
{
    A()=default; //c++11
    virtual ~A()=default; //C++11
};

struct NoCopy
{
    NoCopy& operator=(const NoCopy&) = delete;
    NoCopy(const NoCopy& )=delete;
};

class M
{
    int x, y;
    char *p;
public:
    M(int v) : x(v), y(0), p(new char[20]) {} //#1 target
    M(): M(0) {cout<<"delegating ctor"<<endl;}//#2 delegating
};

int main(int argc, char *argv[])
{
    string s("hello");
    string s2{"hello"};

    return 0;
}
