#include "Array.hpp"
#include <cassert>
#include <iostream>

#define TEST(name)                                                             \
  std::cout << "[TEST] " << name << " ... ";                                   \
  std::cout.flush();

#define PASS() std::cout << "OK" << std::endl;

/* ============================================================
   1. Default constructor
   ============================================================ */
void test_default_constructor() {
  TEST("Default constructor");

  Array<int> a;

  assert(a.size() == 0);

  PASS();
}

/* ============================================================
   2. Sized constructor
   ============================================================ */
void test_sized_constructor() {
  TEST("Sized constructor");

  Array<int> a(5);

  assert(a.size() == 5);

  // Access should not throw for valid indices
  for (int i = 0; i < 5; i++)
    a[i] = i * 10;

  for (int i = 0; i < 5; i++)
    assert(a[i] == i * 10);

  PASS();
}

/* ============================================================
   3. Out of bounds access
   ============================================================ */
void test_out_of_bounds() {
  TEST("Out of bounds access");

  Array<int> a(3);

  bool thrown = false;

  try {
    a[3];
  } catch (const Array<int>::OutOfBoundsException &) {
    thrown = true;
  }

  assert(thrown);

  thrown = false;

  try {
    a[-1];
  } catch (const Array<int>::OutOfBoundsException &) {
    thrown = true;
  }

  assert(thrown);

  PASS();
}

/* ============================================================
   4. Copy constructor (deep copy)
   ============================================================ */
void test_copy_constructor() {
  TEST("Copy constructor deep copy");

  Array<int> a(3);
  for (int i = 0; i < 3; i++)
    a[i] = i + 1;

  Array<int> b(a);

  assert(b.size() == a.size());

  for (int i = 0; i < 3; i++)
    assert(b[i] == a[i]);

  // Modify original, copy must not change
  a[0] = 42;
  assert(b[0] == 1);

  PASS();
}

/* ============================================================
   5. Assignment operator
   ============================================================ */
void test_assignment_operator() {
  TEST("Assignment operator");

  Array<int> a(4);
  for (int i = 0; i < 4; i++)
    a[i] = i;

  Array<int> b(2);
  b = a;

  assert(b.size() == a.size());

  for (int i = 0; i < 4; i++)
    assert(b[i] == a[i]);

  // Deep copy check
  a[1] = 99;
  assert(b[1] == 1);

  PASS();
}

/* ============================================================
   6. Self-assignment
   ============================================================ */
void test_self_assignment() {
  TEST("Self-assignment");

  Array<int> a(3);
  for (int i = 0; i < 3; i++)
    a[i] = i * 5;

  a = a;

  assert(a.size() == 3);
  for (int i = 0; i < 3; i++)
    assert(a[i] == i * 5);

  PASS();
}

/* ============================================================
   7. Const correctness
   ============================================================ */
void test_const_correctness() {
  TEST("Const correctness");

  Array<int> a(3);
  for (int i = 0; i < 3; i++)
    a[i] = i + 10;

  const Array<int> b(a);

  assert(b.size() == 3);
  assert(b[0] == 10);
  assert(b[1] == 11);
  assert(b[2] == 12);

  // b[0] = 5; // <-- must NOT compile

  PASS();
}

/* ============================================================
   8. Template with non-primitive type
   ============================================================ */
void test_with_string() {
  TEST("Template with std::string");

  Array<std::string> a(2);
  a[0] = "hello";
  a[1] = "world";

  Array<std::string> b = a;

  assert(b[0] == "hello");
  assert(b[1] == "world");

  a[0] = "changed";
  assert(b[0] == "hello");

  PASS();
}

/* ============================================================
   main
   ============================================================ */
int main() {
  test_default_constructor();
  test_sized_constructor();
  test_out_of_bounds();
  test_copy_constructor();
  test_assignment_operator();
  test_self_assignment();
  test_const_correctness();
  test_with_string();

  std::cout << "\nAll tests passed successfully." << std::endl;
  return 0;
}
