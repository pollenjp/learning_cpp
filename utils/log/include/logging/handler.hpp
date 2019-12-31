#pragma once

#include <logging/utils.hpp>
#include <logging/formatter.hpp>
#include <logging/log_record.hpp>

namespace logging
{

class Handler
{
public:
	logging::Formatter fmt = logging::Formatter();
	logging::LoggingLevel level = logging::NOTSET;

public:
	Handler(){}

public:
	void SetLevel(logging::LoggingLevel level){ this->level = level; }
	void SetFormatter(logging::Formatter fmt){ this->fmt = fmt; }
	std::string Format(logging::LogRecord record);
	virtual void Emmit(logging::LogRecord record);
};

std::string Handler::Format(logging::LogRecord record)
{
	std::string s(this->fmt.style);
	std::string from, to;

	from = "%(asctime)";
	to = logging::GetDatetime();
	logging::ReplaceAllStr(/* replaced_str= */s, /* from= */from, /* to= */to);

	from = "%(name)";
	to = record.name;
	logging::ReplaceAllStr(/* replaced_str= */s, /* from= */from, /* to= */to);

	from = "%(levelname)";
	to = logging::RevertLoggingLevel(/* level= */record.level);
	logging::ReplaceAllStr(/* replaced_str= */s, /* from= */from, /* to= */to);

	from = "%(message)";
	to = record.msg;
	logging::ReplaceAllStr(/* replaced_str= */s, /* from= */from, /* to= */to);

	return s;
}

void Handler::Emmit(logging::LogRecord record)
{
	// TODO : Not Implemented Error
}

}