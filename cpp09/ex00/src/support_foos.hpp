#pragma once

#include <list>
#include <map>
#include <string>

typedef std::map<std::string, float> map;
typedef map::iterator mapIt;

std::list<std::string> formatter(std::string);

void read_file(const char *filename, std::map<std::string, float> &dataBase);

void load_database(const char *filename,
                   std::map<std::string, float> &dataBase);

float boundChecker(std::map<std::string, float> &dataBase, std::string preline);

bool checkDateValues(std::string preline);

bool checkAmountValues(std::string postline);
