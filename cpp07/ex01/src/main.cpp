
#include "templates.hpp"
#include <iostream>
#include <string>

void numPrinter(int x) { std::cout << "The number is: " << x << std::endl; }

void numAdder(int &x) { x += 1; }

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6};

  iter(arr, 6, numPrinter);
  iter(arr, 6, numAdder);
  std::cout << "<< before adding || after adding >> " << std::endl;
  iter(arr, 6, numPrinter);
}
