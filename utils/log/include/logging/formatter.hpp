#pragma once

#include <logging/utils.hpp>

namespace logging
{

class Formatter
{
public:
    std::string style; // ex) '%(asctime) | %(name) | %(levelname) | %(message)'

public:
    Formatter(std::string fmt = "%(message)") : style(fmt) {}
};

}