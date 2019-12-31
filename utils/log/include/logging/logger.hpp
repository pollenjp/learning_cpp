#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <logging/utils.hpp>
#include <logging/handler.hpp>
#include <logging/log_record.hpp>

namespace logging
{

class Logger
{
public:
	std::string name;
	int level;

private:
	logging::Handler *hdlr;
	std::vector<logging::Handler *> handlers = {};

public:
	Logger(std::string name) : name(name) {}

private:
	logging::LogRecord MakeRecord(
		std::string name,
		logging::LoggingLevel level,
		std::string msg
	);

public:
	void Logger::SetLevel(logging::LoggingLevel level);

	void Logger::AddHandler(logging::Handler * hdlr);

	void Log(logging::LoggingLevel level, const std::string msg);
	void Debug(std::string msg);
	void Info(std::string msg);
	void Warning(std::string msg);
	void Error(std::string msg);
	void Critical(std::string msg);
};

void Logger::SetLevel(logging::LoggingLevel level)
{
	this->level = level;
}

void Logger::AddHandler(logging::Handler * hdlr)
{
	// append hdlr to handlers list
	//this->hdlr = hdlr;
	std::vector<logging::Handler *>::iterator it = this->handlers.end();
	this->handlers.insert(/* pos= */it, /* val= */hdlr);
}

logging::LogRecord Logger::MakeRecord(
	std::string name,
	logging::LoggingLevel level,
	std::string msg
){
	return logging::LogRecord(/* name= */name, /* level= */level, /* msg= */msg);
}

void Logger::Log(logging::LoggingLevel level, const std::string msg)
{
	for (auto hdlr : this->handlers)
	{
		logging::LogRecord record = Logger::MakeRecord(/* name= */this->name, /* level= */level, /* msg= */msg);
		hdlr->Emmit(/* record= */record);
	}
};
void Logger::Debug(std::string msg)   { Logger::Log(/* level= */logging::DEBUG,    /* msg= */msg); }
void Logger::Info(std::string msg)    { Logger::Log(/* level= */logging::INFO,     /* msg= */msg); }
void Logger::Warning(std::string msg) { Logger::Log(/* level= */logging::WARNING,  /* msg= */msg); }
void Logger::Error(std::string msg)   { Logger::Log(/* level= */logging::ERROR,    /* msg= */msg); }
void Logger::Critical(std::string msg){ Logger::Log(/* level= */logging::CRITICAL, /* msg= */msg); }

}