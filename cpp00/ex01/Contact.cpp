#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

void Contact::c_adder(PhoneBook *book, std::string information[5], int number) {
  if (number > 7) {
    number = 7;
    for (int i = 1; i < 8; i++) {
      book->Contacts[i - 1] = book->Contacts[i];
    }
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

// setters:
void Contact::setIndex(std::string number) { _index = number; }
void Contact::setFirstName(std::string name) { _first_name = name; }
void Contact::setLastName(std::string last_name) { _last_name = last_name; }
void Contact::setNickName(std::string nickname) { _nick_name = nickname; }
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
