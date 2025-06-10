#include "PhoneBook.hpp"
#include <iostream>
#include <ostream>

int main() {
  PhoneBook book;
  std::string information[5];
  std::string checker;
  int counter = 0;

  std::cout << "Hi Welcome to your PhoneBook" << std::endl;
  std::cout << "Write ADD for adding a contact" << std::endl;
  std::cout << "Write SEARCH in order to show the current contacts"
            << std::endl;
  std::cout << "Write EXIT to terminate the program" << std::endl;
  while (true) {
    getline(std::cin, checker);
    if (checker == "ADD") {
      for (int i = 0; i < 5; i++) {
        information[i] = PhoneBook::new_contact(i);
      }
      if (counter > 7)
        counter = 7;
      book.Contacts[counter].c_adder(&book, information, counter);
      counter++;
    } else if (checker == "SEARCH") {
      book.c_print();
    } else if (checker == "EXIT")
      break;
    std::cout << "Please only use ADD, SEARCH or EXIT" << std::endl;
  }
  return (0);
}
