#include "scalarConverter.hpp"
#include <cmath>
#include <cstdlib>
#include <iomanip>

void ScalarConverter::convert(std::string &literal) {
  const char *convertedlit = literal.c_str();
  double dlit = atof(convertedlit);
  float flit = static_cast<float>(dlit);
  if (std::isnan(dlit) || std::isinf(dlit)) {
    std::cout << "Char: Impossible" << std::endl;
    std::cout << "Int: Impossible" << std::endl;
    std::cout << "Float: " << flit << "f" << std::endl;
    std::cout << "Double: " << dlit << std::endl;
    return;
  }

  int ilit = static_cast<int>(dlit);
  char clit;
  if (isprint(ilit)) {
    clit = static_cast<char>(ilit);
    std::cout << "Char: '" << clit << "'" << std::endl;
  } else {
    std::cout << "Char: Non displayable" << std::endl;
  }
  std::cout << "Int: " << ilit << std::endl;
  std::cout << std::fixed << std::setprecision(1);
  std::cout << "Float: " << flit << "f" << std::endl;
  std::cout << "Double " << dlit << std::endl;
}
