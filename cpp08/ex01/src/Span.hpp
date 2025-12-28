#include <exception>

class Span
{

private:
	// Span();

public:
	unsigned int _N;
	int* _array;
	unsigned int _numOfElements;

	Span(int Size);
	Span(Span& other);
	Span& operator=(const Span& other);
	~Span();
	void addNumber(int number);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	void randomNumberGenerator(int number);

	class maxElementsReachedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class noSpanCanBeFoundException : public std::exception

	{
	public:
		virtual const char* what() const throw();
	};
};
