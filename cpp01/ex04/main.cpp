#include "sed_is_bad.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		cout << "Please provide an infile, string1, string2" << endl;
		return (1);
	}
	string s1 = argv[2];
	string s2 = argv[3];

	string tmp_file_content = read_file(argv[1]);
	if (tmp_file_content.empty())
	{
		cout << "Failed to get data from file" << endl;
		exit(1);
	}
	tmp_file_content = find_and_replace(tmp_file_content,s1, s2);
	if (tmp_file_content.empty())
	{
		cout << "Failed to replace anything" << endl;
		exit(1);
	}
	write_file("outfile.txt", tmp_file_content);
	return (0);
}