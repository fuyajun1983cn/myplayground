/**
 * The class pair treats two values as a single unit
 * 通常用于容器类如map, multimap, unordered_map和unordered_multimap中
 * 当函数需要返回两个值时，也可以使用此类，如minmax()
 *
 * pair支持copy/assign/swap和compare等操作
 */

#include <utility>
#include <tuple>
#include <iostream>
#include <string>

//generic output operator for pairs(limited solution)
//
template <typename T1, typename T2>
std::ostream& operator << (std::ostream& strm, const std::pair<T1, T2>& p)
{
    return strm << "[" << p.first << ", " << p.second << "]";
}

int main(int argc, const char *argv[])
{
    std::pair<int, std::string> p;
    std::cout<<"Default Pair: "<< p << std::endl;

    std::pair<int, std::string> p2(1, "value1");
    std::cout<<"P2: "<<p2<<std::endl;

    std::pair<int, std::string> p3(p2);
    std::cout<<"P3: "<< p3 <<std::endl;

    std::pair<int, std::string> p4 = std::make_pair(2, "value2");
    std::cout<<"P4: "<< p4 <<std::endl;

    /*--------------------------------------------------*/
    {
        typedef std::pair<int, float> IntFloatPair;
        IntFloatPair p(42, 3.14);

        std::cout<<"std::get<0>(p) = "<<std::get<0>(p)<<std::endl;
        std::cout<<"std::get<1>(p) = "<<std::get<1>(p)<<std::endl;
        std::cout<<"std::tuple_size<IntFloatPair>::value = "<<std::tuple_size<IntFloatPair>::value<<std::endl;
        //std::cout<<"std::tuple_element<0, IntFloatPair>::type = "<<std::tuple_element<0, IntFloatPair>::type<<std::endl;
    }

    return 0;
}
/**
 * since C++11, a pair<> using a type that has only nonconstant copy constructor
 * will no longer compile.
 */

