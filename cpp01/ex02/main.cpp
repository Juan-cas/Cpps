#include <iostream>
#include <string>

using namespace std;

int main()
{
	string name = "HI THIS IS BRAIN";
	string	*stringPTR = &name;
	string	&stringREF = name;

	cout << &name << endl;
	cout << stringPTR << endl;
	cout << (&stringREF) << endl;

	cout << name << endl;
	cout << (*stringPTR) << endl;
	cout << stringREF << endl;
	return (0);

};
