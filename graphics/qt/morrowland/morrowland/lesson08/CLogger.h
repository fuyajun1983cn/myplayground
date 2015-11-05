#ifndef CLOGGER_H
#define CLOGGER_H

#include <iostream>
#include <string>
#include <strstream>

class CLogger
{
public:
    CLogger();

    template<typename T>
    static void info(const T& info)
    {
        //输出绿色字符串
        std::cout<<"\033[0;32;1mINFO: "<<info<<"\033[0m"<<std::endl;
    }

    template<typename T>
    static void err(const T& err)
    {
        //输出红色字符串
        std::cerr<<"\033[0;31;1mERROR: "<<err<<"\033[0m"<<std::endl;
    }

    template<typename T>
    static void warn(const T& warn)
    {
        //输出蓝色字符串
        std::cout<<"\033[0;34;1mWARNING: "<<warn<<"\033[0m"<<std::endl;
    }
};

#endif // CLOGGER_H
