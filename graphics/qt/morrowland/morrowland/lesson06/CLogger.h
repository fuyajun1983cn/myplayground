#ifndef CLOGGER_H
#define CLOGGER_H

#include <iostream>
#include <string>

class CLogger
{
public:
    CLogger();

    static void info(const std::string& info);

    static void err(const std::string& err);

    static void warn(const std::string& warn);
};

#endif // CLOGGER_H
