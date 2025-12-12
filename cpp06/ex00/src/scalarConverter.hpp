#include <iostream>

class ScalarConverter {
private:
  ScalarConverter(ScalarConverter &other);
  ScalarConverter operator=(ScalarConverter &other);

public:
  ScalarConverter();
  virtual ~ScalarConverter() = 0;
  static void convert(std::string &literal);
};
