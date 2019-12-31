#pragma once

#include <ctime>
#include <cassert>

#include <iostream>
#include <string>
#include <sstream>

namespace logging
{

// https://docs.python.org/ja/3/library/logging.html#levels
enum LoggingLevel
{
	NOTSET   =  0,
	DEBUG    = 10,
	INFO     = 20,
	WARNING  = 30,
	ERROR    = 40,
	CRITICAL = 50,
};

std::string RevertLoggingLevel(logging::LoggingLevel level)
{
	switch ((int) level)
	{
		case  0: return "NOTSET";
		case 10: return "DEBUG";
		case 20: return "INFO";
		case 30: return "WARNING";
		case 40: return "ERROR";
		case 50: return "CRITICAL";
		default: return "Failed to Revert Logging Level.";
	}
}

std::string GetDatetime()
{
	time_t now_time = std::time(0);
	//struct tm * now_tm = std::localtime(/* time_t * timer= */&now_time);
	struct tm now_tm;
	localtime_s(/* struct tm *restrict result= */&now_tm,
	            /* time_t * timer= */&now_time);
	char buf[256];
	size_t result = std::strftime(/* char * restrict s= */buf,
	                              /* size_t maxsize= */sizeof(buf),
	                              /* const char * restrict format= */"%Y-%m-%d %H:%M:%S %z",
	                              /* const struct tm * restrict timeptr= */&now_tm);
	assert(result != 0);
	std::string now_str(buf);
	return now_str;
}

std::string ReplaceAllStr(std::string &replaced_str, std::string from, std::string to)
// TODO : unsigned int を指定しなければ size_t が
//        signed int として扱われる環境があったため明示的に
//        unsigned int にしているがもっと安定した方法に変えたい
{
	// https://www.sejuku.net/blog/54493
	unsigned int pos = (unsigned int) replaced_str.find(from);
	const int to_len = to.length();

	if (from.empty())
	{
		return replaced_str;
	}

	while (true)
	{
		pos = (unsigned int) replaced_str.find(from, pos);
		// std::cout << "pos: " << pos << std::endl;
		if (pos == (unsigned int) std::string::npos){ break; }
		// std::cout << std::string::npos << std::endl;
		replaced_str.replace(pos, from.length(), to);
		pos += to_len;
	}
	return replaced_str;
}


}