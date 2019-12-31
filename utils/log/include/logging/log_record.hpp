#pragma once

#include <logging/utils.hpp>

namespace logging
{

class LogRecord
{
public:
    std::string name;
    logging::LoggingLevel level;
    std::string msg;

public:
    LogRecord(
        std::string name,
        logging::LoggingLevel level,
        std::string msg
    ) : name(name), level(level), msg(msg) {}

};

}