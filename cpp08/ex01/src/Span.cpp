#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits.h>
#include <ostream>


Span::Span(int size)
{
	_N = size;
	_array = new int[size];
	_numOfElements = 0;
}

Span::Span(Span& other)
{
	_N = other._N;
	_numOfElements = other._numOfElements;
	_array = new int[_N];

	for (unsigned int i = 0; i < _numOfElements; i++)
	{
		_array[i] = other._array[i];
	}
};

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_N = other._N;
		_numOfElements = other._numOfElements;
		_array = new int[_N];

		for (unsigned int i = 0; i < _numOfElements; i++)
		{
			_array[i] = other._array[i];
		}
	}
	return (*this);
};

Span::~Span() { delete[] _array; };

void Span::addNumber(int number)
{
	if ((_numOfElements + 1) > _N)
		throw maxElementsReachedException();
	_array[_numOfElements] = number;
	_numOfElements += 1;
};

unsigned int Span::shortestSpan()
{
	if (_numOfElements == 0 || _numOfElements == 1)
		throw noSpanCanBeFoundException();

	int shortestSpan = INT_MAX;

	for (unsigned int i = 0; i < _numOfElements; i++)
	{
		for (unsigned int j = i + 1; j < _numOfElements; j++)
		{
			if (abs(_array[i] - _array[j]) < shortestSpan)
				shortestSpan = abs(_array[i] - _array[j]);
		}
	}
	return shortestSpan;
}

unsigned int Span::longestSpan()
{
	if (_numOfElements == 0 || _numOfElements == 1)
		throw noSpanCanBeFoundException();

	int lowestNumb = INT_MAX;
	int higestNumb = INT_MIN;

	for (unsigned int i = 0; i < _numOfElements; i++)
	{
		if (lowestNumb > _array[i])
		{
			lowestNumb = _array[i];
		}
	}
	for (unsigned int i = 0; i < _numOfElements; i++)
	{
		if (higestNumb < _array[i])
			higestNumb = _array[i];
	}
	return abs(higestNumb - lowestNumb);
}

void Span::randomNumberGenerator(int number)
{
	srand((unsigned int)std::time(NULL));
	for (int i = 0; i < number; i++)
	{
		try
		{
			addNumber(abs(rand() % 1000));
		}
		catch (const maxElementsReachedException&)
		{
			throw maxElementsReachedException();
		}
	}
}


const char* Span::maxElementsReachedException::what() const throw()
{
	return ("The maximum number of elements has been reached, can't add a new one");
}

const char* Span::noSpanCanBeFoundException::what() const throw() { return ("Error: No Span can be found"); }
