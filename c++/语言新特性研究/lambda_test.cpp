#include <iostream>
#include <functional>
#include <string>
#include <algorithm>

/**
 * lambda expression
 *  [capture](parameter)->return-type {body}
 *
 */

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
void simple_lambda_test()
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
}

/**
  * count how many uppercase letters a string contains.
  *
  */
void count_uppercase_letters(string str)
{
    int Uppercase = 0;//modified by the lambda
    const char *s = str.c_str();
    for_each(s, s + sizeof(s), [&Uppercase] (char c) {
        if (isupper(c)) {
            Uppercase++;
        }
    });
    cout<<Uppercase<<" uppercase letters in: "<< str<<endl;
}

/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *argv[])
{

  //  simple_lambda_test();

    count_uppercase_letters("Hello, World");

    return 0;
}



