#include <iostream>
#include <vector>
#include "template.hpp"


int main()
{
	std::vector<int> v;
	v.push_back(5);
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(55);
	v.push_back(52);
	v.push_back(59);
	v.push_back(99);
	std::cout << "first test finding the needle" << std::endl;
	try
	{
		int result = easyfind(v, 99);
		std::cout << "found the needle: " << result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "second test finding the needle should throw exception" << std::endl;
	try
	{
		int result = easyfind(v, 105);
		std::cout << "found the needle: " << result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
