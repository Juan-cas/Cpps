#include <cstddef>
template <typename T, typename Func>

void iter(T *array, size_t length, Func foo) {
  for (size_t i = 0; i < length; i++)
    foo(array[i]);
}
