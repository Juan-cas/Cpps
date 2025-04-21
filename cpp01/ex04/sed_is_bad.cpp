#include "sed_is_bad.hpp"

string find_and_replace(const string &file_content, string &str1, string &str2)
{
    string result;
    size_t pos = 0;
	size_t prev_pos = 0;
    while ((pos = file_content.find(str1, prev_pos)) != string::npos)
    {
        result.append(file_content, prev_pos, pos - prev_pos);
        result.append(str2);
        prev_pos = pos + str1.length();
    }
    result.append(file_content, prev_pos, string::npos);
    return (result);
};

string read_file(const string &filename)
{
	if (filename.empty())
	{
		cout << "Please Input a correct infile filename" << endl;
		exit(1);
	}
	ifstream infile;
	infile.open(filename.c_str());
	if (!infile.is_open())
	{
		cout << "Please check infile permisions" << endl;
		exit(1);
	}
	string line;
	string file_contents;
	while (getline(infile, line))
		file_contents += line + '\n';
	infile.close();
	if (file_contents.empty())
	{
		cout << "file is empty" << endl;
		exit(1);
	}
	return (file_contents);
}

void write_file(const string &filename, const string &content)
{
	if (filename.empty())
	{
		cout << "Please input a correct outfile filename";
		exit(1);
	}
	ofstream outfile;
	outfile.open(filename.c_str());
	if (!outfile.is_open())
	{
		cout << "Please check outfile permissions" << endl;
		exit(1);
	}
	outfile << content;
	outfile.close();
}

