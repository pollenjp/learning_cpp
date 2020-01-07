#include <iostream>
#include <example.hpp>

int main()
{
	std::cout << "hello world!" << std::endl;
	Example inst = Example();
	int a = inst.add(5, 8);
	std::cout << a << std::endl;
}