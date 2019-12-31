#pragma once

#include <iostream>
#include <sformatter.hpp>


int main()
{
	std::string str = "samurai, engineer, ninja, se, engineer!";
	std::cout << "置換前：" << str << std::endl;
	sformatter::ReplaceAllStr(str, "engineer", "programmer");
	std::cout << "置換後：" << str << std::endl;
	return 0;
}