#pragma once

#include <string>

namespace sformatter
{

std::string ReplaceAllStr(std::string &replaced_str, std::string from, std::string to)
{
	// ref : https://www.sejuku.net/blog/54493
	size_t pos = replaced_str.find(from);
	const size_t to_len = to.length();

	if (from.empty())
	{
		return replaced_str;
	}

	while (true)
	{
		pos = replaced_str.find(from, pos);
		// std::cout << "pos: " << pos << std::endl;
		if (pos == std::string::npos){ break; }
		// std::cout << std::string::npos << std::endl;
		replaced_str.replace(pos, from.length(), to);
		pos +=  to_len;
	}
	return replaced_str;
}

}
