#include <iostream>
#include <functional>

using namespace std;

/**
 * 返回lambda函数类型
 */
function<int(int,int)> returnLambda()
{
    return [] (int x, int y) {
        return x * y;
    };
}

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

    //x is passed by value, y is passed by reference
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

    auto lf = returnLambda();
    cout<<lf(6, 7)<<endl;

    return 0;
}


/*
 * 测试结果
 *
 
Hello, lambda
Hello, lambda again
Hello, Lambda
x: 0
y: 77
x: 0
y: 78
final y: 79
id: 0
id: 1
id: 2
42
42

*/
