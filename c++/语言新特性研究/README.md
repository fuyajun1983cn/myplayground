##C++新语言特性
* 语法的微小改动

The requirement to put a space between two closing template expressions has gone:
```c++
vector<list<int> >;// OK in each C++ version
vector<list<int>>; // OK since C++11
```
C++11 lets you use nullptr instead of 0 or NULL to specify that a pointer refers to no value (which differs from having an undefined value) `nullptr` is a new keyword.  It has type `std::nullptr_t`, defined in `<cstddef>`
* 使用auto进行类型自动推导
With C++11, you can declare a variable or an object without specifying its specific type by using `auto`.
```c++
auto i = 42; // i has type int
double f();
auto d = f(); // d has type double
```
The type of a variable declared with `auto` is deduced from its initializer. Thus, an initialization is required:
```c++
auto i; // ERROR: can’t dedulce the type of i
```
* 通用初始化和初始化列表

Initialization could happen with parentheses, braces, and/or assignment operators.For this reason, C++11 introduced the concept of uniform initialization, which means that for any initialization, you can use one common syntax. This syntax uses braces, so the following is possible now:
```c++
int values[] { 1, 2, 3 };
std::vector<int> v { 2, 3, 5, 7, 11, 13, 17 };
std::vector<std::string> cities {"Berlin", "New York", "London", "Braunschweig", "Cairo", "Cologne"};
std::complex<double> c{4.0,3.0}; // equivalent to c(4.0,3.0)
```
however, that narrowing initializations — those that reduce precision or where the supplied value gets modified — are not possible with braces. 
```c++
int x2 = 5.3; // OK,but OUCH: x2 becomes 5
int x3{5.0}; // ERROR: narrowing
```
To support the concept of initializer lists for user-defined types, C++11 provides the class `template std::initializer_list<>`. It can be used to support initializations by a list of values or in any other place where you want to process just a list of values.
```c++
void print (std::initializer_list<int> vals)
{
　　for (auto p=vals.begin(); p!=vals.end(); ++p) {
    　　std::cout << *p << "\n";
　　}
}
// process a list of values
print ({12,3,5,7,11,13,17}); // pass a list of values to print()
```
* 基于范围的循环
```c++
for ( decl : coll ) {　　
    statement
}
```
Example:
```c++
for ( int i : { 2, 3, 5, 7, 9, 13, 17, 19 } ) {
　　std::cout << i << std::endl;
}
```
* move语义和右值


左值和右值的一点差异

当使用decltype时，作用于左值时，结果将是一个引用，作用于右值时，结果将是一个指针，例如：假设
```c++
int *p;
decltype(*p) -> int&
decltype(&p) -> int**
```
当对象是一个本地非静态对象时，将其右值引用作为一个返回值将会导致错误。
```c++
X&& foo (){
    X x;
    ...
    return x; // ERROR: returns reference to nonexisting object
}
* 新的字符串表示方法

原始字符串常量
`“\\\\n”` can be defined as `R(”\\n”)`
编码过的字符串常量u8 defines a UTF-8 encoding. A UTF-8 string literal is
 initialized with the given characters as encoded in UTF-8. The characters
 have type const char.
1. u defines a string literal with characters of type char16_t.
2. U defines a string literal with characters of type char32_t.
3. L defines a wide string literal with characters of type wchar_t.
For example:
```c++
L"hello" // defines ‘‘hello’’ as wchar_t string literal
```
* 关键字noexcept

用于指明一个函数不能抛出或不打算抛出异常，例如：
```c++
void foo() noexcept
```
这样，如果在foo()函数内部发生异常，但是又没有去处理，则程序会停止，并调用`std::terminate()`，它默认为调用`std::abort()`。
* 关键字constexpr

常量表达式的值不能改变，且在编译期间就会解析。
在C++11中，引入了`constexpr`声明一个变量的初始化是一个常量表达式。由于声明为`constexpr`类型的变量隐式地为`const`，
所以必须由一个常量表达式初始化。如：
```c++
constexpr int mf = 20;
constexpr int limit = mf + 1;
constexpr int sz = size(); //只有当size()是一个constexpr类型的函数时，则成立。
```
当使用`constexpr`声明一个指针常量表达式时，**`constexpr`修饰的是指针本身**，而不是指针所指的类型，如：
```c++
const int *p = nullptr;  //p是一个指向常量整型的指针
constexpr int *q = nullptr;//q是一个指向整型变量的常量指针
```
* 新的模板特性

从C++11开始，模板可以使用可变参数的形式，这种能力叫做*variadic templates*。例如，你可以使用如下方法调用`print()`，
使用类型可变，且参数个数可变的。
```c++
template<typename T>
void print(const T& arg)
{
    std::cout<<arg<<std::endl;
}

template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args)
{
    std::cout<<firstArg<<std::endl; //print first argument
    print(args...); //call print() for remaining arguments.
}
```

**模块别名**
```c++
template<typename T>
using Vec = std::vector<T, MyAlloc<T>>; //standard vector using own allocator
```
这样，如下两条语句等价：
```C++
Vec<int> coll;
std::vecotr<int, MyAlloc<int>> coll;
```

**其他新特性**
从C++11开始，函数模板可以默认模板参数。另外，本地类型也可以做为模板参数。内部链接的函数现在
也可以被用做无类型模板的函数指针或指针引用的参数。

* Lambda

最简单的lambda
```c++
[] {
      Std::cout << “hello lambda” << std::endl
  }
  语法形式为：
  [...]  {...}
  或
  [...] (...) mutable throwSpec ->retType {...}
  Lambda不能应用模板
  [] {
        return 42;
    }
    
[] () -> double {
    //指定了参数时，则必须显示指定返回值类型
    return 42;
    }
    
    [=]，表明lambda外部的变量通过传值的方式，给lambda内部访问，不能在内部进行修改。
    [&], 表明lambda外部的变量通过引用的方式，给lambda内部访问，可以在内部进行修改。
* 关键字decltype

使用关键字`decltype`，可以让编译器找到一个表达式的类型。这就是`typeof`的特性。
然后，`typeof`不一致和不完整，所以C++11引入了新的关键字，例如：
```c++
std::map<std::string, float> coll;
decltype(coll)::value_type elem;
```

* 新的函数声明语法

```c++
template<typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x+y)
```
* 限定型枚举类型
```c++
enum class Salutation : char { mr, ms, co, none};
```

1. 从int到enum的隐式转换不可能了。
2. mr不再在所在域的一部分，必须使用Salutation::mr。
3. 你可以显式定义底层的类型（此处定义了`char`），默认是`int`。
4. 枚举类型的前向声明是允许的，这样，如果仅仅使用了枚举类型，当加入新的枚举值时，不需要重新编译。
* 新的基本数据类型

```c++
char16_t , char32_t
long long , unsigned long long
std::nullptr_t
```
##旧语法新用法

1. 无类型模板参数
```
class bitset<>
bitset<32> flag32; //bitset32 with 32 bits
bitset<50> flag50; //bitset with 50 bits
```

2. 默认模板参数
```
template<typename T, typename container = vector<T>>
class MyClass;
```

3. 关键字`typename`
```
template<typename T>
class MyClass {
    typename T::SubType * ptr;
    ...
};
```
`typename`用于告诉编译器SubType是定义于类T里面的一个内部类型。

4. 模板成员函数
```c++
class MyClass {
    ...
    template<typename T>
    void f(T);
};
```
**模板成员函数不能是虑函数**

5. 嵌套的类模板
```c++
template<typename T>
class MyClass {
    ...
    template <typename T2>
    class NestedClass;
    ...
};
```

* 基本数据类型的显式初始化

```c++
int i1;
int i2 = int();
int i3{};
```
* main()函数定义

只有如下两种main()函数形式是可移植的：
```c++
int main()
{
    ...
}

int main(int argc, char *argv[])
{
    ...
}
```
在C++中，main函数可以不用显式写返回语句，默认会加入：
```c++
return 0;
```

要想从main()函数中不通过return的方式退出，必须调用`call()`, `quick_exit()`或者`terminate()`。
