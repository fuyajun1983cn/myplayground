#include "CLogger.h"

CLogger::CLogger()
{
}

void CLogger::info(const std::string &info)
{
    //输出绿色字符串
    std::cout<<"\033[0;32;1mINFO: "<<info<<"\033[0m"<<std::endl;
}

void CLogger::err(const std::string &err)
{
    //输出红色字符串
    std::cerr<<"\033[0;31;1mERROR: "<<err<<"\033[0m"<<std::endl;
}

void CLogger::warn(const std::string &warn)
{
    //输出蓝色字符串
    std::cout<<"\033[0;34;1mWARNING: "<<warn<<"\033[0m"<<std::endl;
}
