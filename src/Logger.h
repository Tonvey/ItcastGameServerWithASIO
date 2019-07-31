#pragma once
#include "Macro.h"
#include <string>
#define GG_LOG_DEBUG(...) do{\
        GG_NAMESPACE::Logger::LogDebug("%s#%d#%s",__FILENAME__,__LINE__,__VA_ARGS__); \
}while(0)
GG_NAMESPACE_BEGIN
class Logger
{
public:
    static Logger &getInstance(){return smInstance;};
    static Logger smInstance;
    static void LogDebug(const char *fmt,...);
    static void LogDebug(std::string &str);
    static void LogWarning(std::string &str);
    static void LogError(std::string &str);
    static void LogInformation(std::string &str);

private:
};
GG_NAMESPACE_END
