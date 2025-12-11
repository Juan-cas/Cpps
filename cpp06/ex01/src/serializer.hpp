#include <cstddef>
#include <stdint.h>
#include <string>

struct Data {
  int test1;
  std::string test2;
};

class Serializer {
public:
  Serializer();
  virtual ~Serializer() = 0;
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};
