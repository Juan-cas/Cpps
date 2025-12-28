#include <iostream>
#include "Span.hpp"

int main()
{

	{
		Span BaseArray(20);
		BaseArray.randomNumberGenerator(20);
		std::cout << "the shortestSpan in this array is: " << BaseArray.shortestSpan() << std::endl;
		std::cout << "the longestSpan in this array is: " << BaseArray.longestSpan() << std::endl;
	}

	{
		Span BaseArray(100);
		BaseArray.addNumber(4);
		BaseArray.addNumber(9);
		BaseArray.addNumber(1);
		std::cout << "the shortestSpan in this array is: " << BaseArray.shortestSpan() << std::endl;
		std::cout << "the longestSpan in this array is: " << BaseArray.longestSpan() << std::endl;
	}
}
