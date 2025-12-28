
#include <cstddef>
#include <exception>
class NeedleNotFoundException : public std::exception
{
public:
	virtual const char* what() const throw() { return ("Needle not found in haystack"); }
};


template <typename T>
int easyfind(T haystack, int needle)
{
	for (size_t i = 0; i < haystack.size(); ++i)
	{
		if (haystack[i] == needle)
			return needle;
	}
	throw NeedleNotFoundException();
}
