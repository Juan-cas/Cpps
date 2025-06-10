#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contact.hpp"
#include <string>

class PhoneBook {
public:
  Contact Contacts[8];

  static std::string new_contact(int flag);
  void get_info(int choice);
  void c_print();
  void get_info(PhoneBook *book, int choice);
  static bool check_pnumb(std::string phone_number);
};

bool is_whitespace_only(std::string &input);

#endif
