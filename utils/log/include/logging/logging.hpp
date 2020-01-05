#pragma once

#include <logging/logger.hpp>
#include <logging/stream_handler.hpp>
#include <logging/file_handler.hpp>

namespace logging
{

logging::Logger GetLogger(std::string name)
{
	logging::Logger logger = logging::Logger(/* name= */name);
	return logger;
}

}
