#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstddef>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>

void PhoneBook::c_print() {
  const int witdth = 10;
  std::cout << std::setw(witdth) << std::right << "Index" << "|"
            << std::setw(10) << std::right << "First Name"
            << "|" << std::setw(witdth) << std::right << "Last Name " << "|"
            << std::setw(witdth) << std::right << "Nickname  " << std::endl;

  for (int i = 0; i < 8; i++) {
    if (this->Contacts[i].getFirstName().empty() == true)
      break;
    std::cout << std::setw(10) << std::right << this->Contacts[i].getIndex()
              << "|" << std::setw(10) << std::right
              << Contact::check_str(this->Contacts[i].getFirstName()) << "|"
              << std::setw(10) << std::right
              << Contact::check_str(this->Contacts[i].getLastName()) << "|"
              << std::setw(10) << std::right
              << Contact::check_str(this->Contacts[i].getNickName())
              << std::endl;
  }
  std::string checker;
  std::cout << "Write the number of the index of the contact you want to review"
            << std::endl;
  getline(std::cin, checker);
  if (check_pnumb(checker) == false) {
    std::cout << "only write numerical values" << std::endl;
    return;
  }
  std::stringstream ss(checker);
  int choice;
  ss >> choice;
  if (choice < 0 || choice > 7 || Contacts[choice].getFirstName().empty()) {
    std::cout << "Invalid index selected." << std::endl;
    return;
  }
  get_info(choice);
}

void PhoneBook::get_info(int choice) {
  if (choice > 7) {
    std::cout << "you can only check the index 0 to 7" << std::endl;
    return;
  }
  if (this->Contacts[choice].getFirstName().empty() == true) {
    std::cout << "There is no contact in this index" << std::endl;
    return;
  }

  std::cout << "First Name: " << this->Contacts[choice].getFirstName()
            << std::endl;

  std::cout << "Last Name: " << this->Contacts[choice].getLastName()
            << std::endl;

  std::cout << "Nickname: " << this->Contacts[choice].getNickName()
            << std::endl;

  std::cout << "Phone Number: " << this->Contacts[choice].getPhoneNumber()
            << std::endl;

  std::cout << "Darkest Secret: " << this->Contacts[choice].getDaskestSecret()
            << std::endl;
}

bool is_whitespace_only(std::string &input) {
  for (size_t i = 0; i < input.size(); i++) {
    if (!isspace(input[i]))
      return false;
  }
  return true;
}

std::string PhoneBook::new_contact(int flag) {
  std::string information;
  std::string quotes[5] = {"Please enter the contact First_name: ",
                           "Please enter the contact Last_name: ",
                           "Please enter the contact Nickname",
                           "Please enter the contact phone number",
                           "Please enter the contact Darkest Secret"};
  std::cout << quotes[flag] << std::endl;
  while (true) {
    getline(std::cin, information);
    if (information.empty()) {
      std::cout << "You must write something" << std::endl;
      continue;
    }
    if (flag == 3) {
      if (check_pnumb(information) == false) {
        std::cout << "Only write numbers" << std::endl;
        continue;
      }
      break;
    } else if (information.empty() || is_whitespace_only(information)) {
      std::cout << ". please try again: " << std::endl;
      continue;
    }
    break;
  }
  return (information);
}

bool PhoneBook::check_pnumb(std::string phone_number) {
  for (size_t i = 0; i < phone_number.size(); i++) {
    if (!std::isdigit(phone_number[i]))
      return false;
  }
  return true;
}
