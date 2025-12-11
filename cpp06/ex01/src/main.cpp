#include "serializer.hpp"
#include <iostream>

int main() {

  Data data;
  data.test1 = 42;
  data.test2 = "Mary Janne";

  uintptr_t raw = Serializer::serialize(&data);
  std::cout << "Serialized value: " << raw << std::endl;

  Data *deserialized = Serializer::deserialize(raw);
  std::cout << "Deserialized value: " << deserialized << std::endl;

  if (deserialized == &data)
    std::cout << "Pointer restored correctly" << std::endl;
  else
    std::cout << "Pointer wasn't restored correctly" << std::endl;

  std::cout << "Original.test1: " << data.test1 << std::endl;
  std::cout << "Deserialized.test1: " << deserialized->test1 << std::endl;
}
