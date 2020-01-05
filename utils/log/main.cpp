#pragma once
#include <logging/logging.hpp>

int main()
{
	logging::Logger logger = logging::GetLogger(/* name= */"LogTest");
	logger.SetLevel(/* level= */logging::DEBUG);

	logging::Formatter handler_format = logging::Formatter(
		/* fmt= */"%(asctime) | %(name) | %(levelname) | %(message)");
	logging::StreamHandler stream_handler = logging::StreamHandler();
	stream_handler.SetLevel(/* level= */logging::DEBUG);
	stream_handler.SetFormatter(/* fmt= */handler_format);

	logger.AddHandler(/* hdlr= */&stream_handler);

	std::cout << "Hello" << std::endl;
	logger.Debug(/* msg= */"Hello, World!");
}