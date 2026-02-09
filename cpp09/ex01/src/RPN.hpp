#ifndef RPNHPP
#define RPNHPP

#include <string>
#include <vector>

void letsParseInput(char *argv);
int findCase(std::string token);
bool valueChecker(int num);

void cleanStack(std::vector<int> &stack);

#endif
