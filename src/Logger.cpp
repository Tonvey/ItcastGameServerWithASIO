#include "Logger.h"
#include <cstdarg>
#include <cstring>
#include <iostream>
#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/attributes/timer.hpp>
#include <boost/log/attributes/named_scope.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/support/date_time.hpp>
using namespace std;
GG_NAMESPACE_BEGIN
Logger Logger::smInstance;
void Logger::LogDebug(const char *fmt,...)
{
    char buf[1024];
    memset(buf,0,sizeof(buf));va_list ap;
    int ret = -999999, tmp;
    va_start(ap, fmt);
    vsnprintf(buf,sizeof(buf),fmt,ap);
    va_end(ap);
    cerr<<buf<<endl;
}
void Logger::LogDebug(std::string &str)
{
    cerr<<str<<endl;
}
void Logger::LogWarning(std::string &str)
{
    LogDebug(str);
}
void Logger::LogError(std::string &str)
{
    LogDebug(str);
}
void Logger::LogInformation(std::string &str)
{
    LogDebug(str);
}
GG_NAMESPACE_END
