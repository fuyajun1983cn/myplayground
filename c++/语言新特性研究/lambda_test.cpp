#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    //simple lambda
    [] {
        cout<<"Hello, lambda"<<endl;
    }();

    auto l = [] {
        cout<<"Hello, lambda again"<<endl;
    };
    l();

    auto l2 = [] (const std::string& s) {
        cout<<s<<endl;
    };
    l2("Hello, Lambda");

    int x = 0;
    int y = 42;

    auto qqq = [x, &y] {
        cout<< "x: "<<x<<endl;//不能修改x
        cout<< "y: "<<y<<endl;
        ++y; //OK
    };
    x = y = 77;
    qqq();
    qqq();
    cout<<"final y: "<<y<<endl;

    int id = 0;
    auto f = [id] () mutable {
        cout << "id: "<<id<<endl;
        ++id; //OK
    };
    id = 42;
    f();
    f();
    f();
    cout<<id<<endl;

    return 0;
}
