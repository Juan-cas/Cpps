#include "RPN.hpp"
#include <iostream>
#include <sstream>

void letsParseInput(char *argv) {
  std::istringstream iss(argv);
  std::vector<int> stack;
  std::string token;

  while (getline(iss, token, ' ')) {
    int Num;
    if (std::istringstream(token) >> Num) {
      if (valueChecker(Num)) {
        stack.push_back(Num);
      } else {
        cleanStack(stack);
        return;
      }
    } else {
      if (stack.size() > 1) {
        int secondNum = stack.back();
        stack.pop_back();
        int firstNum = stack.back();
        stack.pop_back();
        int c = findCase(token);
        switch (c) {
        case 1:
          stack.push_back(firstNum * secondNum);
          break;
        case 2:
          stack.push_back(firstNum / secondNum);
          break;
        case 3:
          stack.push_back(firstNum - secondNum);
          break;
        case 4:
          stack.push_back(firstNum + secondNum);
          break;
        case 5:
          std::cerr << "Error";
          cleanStack(stack);
          return;
        }
      } else {
        std::cerr << "Error";
        cleanStack(stack);
        return;
      }
    }
  }
  if (stack.size() != 1) {
    std::cerr << "Error";
    cleanStack(stack);
    return;
  }
  int result = stack.back();
  stack.pop_back();
  std::cout << result;
}

int findCase(std::string token) {
  if (token == "*")
    return 1;
  if (token == "/")
    return 2;
  if (token == "-")
    return 3;
  if (token == "+")
    return 4;
  return 5;
}

bool valueChecker(int num) {
  if (num < 0 || num > 9) {
    std::cerr << "Error";
    return false;
  }
  return true;
}

void cleanStack(std::vector<int> &stack) {
  while (stack.size() > 0) {
    stack.pop_back();
  }
}
