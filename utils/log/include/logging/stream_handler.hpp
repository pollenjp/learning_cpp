#pragma once

#include <logging/utils.hpp>
#include <logging/handler.hpp>

namespace logging
{

class StreamHandler : public logging::Handler
{
public:
	virtual void Emmit(logging::LogRecord record);
};

void StreamHandler::Emmit(logging::LogRecord record)
{
	if (record.level >= this->level){
		std::string log_text = this->Format(/* record= */record);
		std::cout << log_text << std::endl;
	}
}

}