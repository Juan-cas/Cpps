#include <cstring>
#include <iostream>

int main(int argc, char **argv){
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		char *tmpstr = argv[i];
		for (size_t j = 0; j < strlen(tmpstr); j++)
			if (islower(tmpstr[j]))
				tmpstr[j] = toupper(tmpstr[j]);
		std::cout << tmpstr;
		if (i != argc - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}

 
