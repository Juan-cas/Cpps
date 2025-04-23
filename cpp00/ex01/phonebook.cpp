#include "PhoneBook.h"
#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

void PhoneBook::c_print(PhoneBook *book) {
  std::cout << std::setw(10) << std::right << "Index" << "|" << std::setw(10)
            << std::right << "First Name"
            << "|" << std::setw(10) << std::right << "Last Name " << "|"
            << std::setw(10) << std::right << "Nickname  " << std::endl;

  for (int i = 0; i < 8; i++) {
    if (book->Contacts[i].getFirstName().empty() == true)
      break;
    std::cout << std::setw(10) << std::right << Contact::check_str(book->Contacts[i].getIndex()) << "|"
              << std::setw(10) << std::right << Contact::check_str(book->Contacts[i].getFirstName()) << "|"
              << std::setw(10) << std::right << Contact::check_str(book->Contacts[i].getLastName()) << "|"
              << std::setw(10) << std::right << Contact::check_str(book->Contacts[i].getNickName()) << std::endl;
  }
  std::string checker;
  std::cout << "Write the number of the index of the contact you want to review" << std::endl;
  getline(std::cin, checker);
  if (check_pnumb(checker) == false) {
    std::cout << "only write numerical values" << std::endl;
    return;
  }
  std::stringstream ss(checker);
  int choice;
  ss >> choice;
  get_info(book, choice);
}

std::string PhoneBook::new_contact(int flag) {
  std::string information;
  if (flag == 0)
    std::cout << "Please enter the contact First_name: ";
  if (flag == 1)
    std::cout << "Please enter the contact last_name: ";
  if (flag == 2)
    std::cout << "Please enter the contact Nickname: ";
  if (flag == 3)
    std::cout << "Please enter the contact phone number: ";
  if (flag == 4)
    std::cout << "Please enter the contact Darkest_secret: ";
  while (true) {
    getline(std::cin, information);
    if (flag == 3) {
      if (check_pnumb(information) == false) {
        std::cout << "Please only input numbers" << std::endl;
        continue;
      }
      break ;
    }
    else if (information.empty() == false)
      break;
    else
      std::cout << "Please enter the information correctly: ";
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

void Contact::c_adder(PhoneBook *book, std::string information[5], int number) {
  if (number > 7) {
    number = 7;
  }
  std::stringstream ss;
  ss << number;
  std::string index = ss.str();
  book->Contacts[number].setIndex(index);
  book->Contacts[number].setFirstName(information[0]);
  book->Contacts[number].setLastName(information[1]);
  book->Contacts[number].setNickName(information[2]);
  book->Contacts[number].setPhoneNumber(information[3]);
  book->Contacts[number].setDaskestSecret(information[4]);
};

std::string Contact::check_str(const std::string &information) {
  if (information.length() > 10)
    return information.substr(0, 9) + '.';
  else
    return (information + std::string(10 - information.length(), ' '));
}

void PhoneBook::get_info(PhoneBook *book, int choice) {
  if (choice > 7) {
    std::cout << "you can only check the index 0 to 7" << std::endl;
    return;
  }
  if (book->Contacts[choice].getFirstName().empty() == true) {
    std::cout << "There is no contact in this index" << std::endl;
    return;
  }

  std::cout << "First Name: " << book->Contacts[choice].getFirstName()
            << std::endl;

  std::cout << "Last Name: " << book->Contacts[choice].getLastName() << std::endl;

  std::cout << "Nickname: " << book->Contacts[choice].getNickName() << std::endl;

  std::cout << "Phone Number: " << book->Contacts[choice].getPhoneNumber()
            << std::endl;

  std::cout << "Darkest Secret: " << book->Contacts[choice].getDaskestSecret()
            << std::endl;
}

// setters:
void Contact::setIndex(std::string number) { _index = number; }
void Contact::setFirstName(std::string name) { _first_name = name; }
void Contact::setLastName(std::string last_name) {
  _last_name = last_name;
}
void Contact::setNickName(std::string nickname) {
  _nick_name = nickname;
}
void Contact::setPhoneNumber(std::string phone_number) {
  _phone_number = phone_number;
}
void Contact::setDaskestSecret(std::string Darkest_secret) {
  _darkest_secret = Darkest_secret;
}

// getters:
std::string Contact::getIndex() { return _index; }
std::string Contact::getPhoneNumber() { return _phone_number; }
std::string Contact::getFirstName() { return _first_name; }
std::string Contact::getLastName() { return _last_name; }
std::string Contact::getNickName() { return _nick_name; }
std::string Contact::getDaskestSecret() { return _darkest_secret; }
