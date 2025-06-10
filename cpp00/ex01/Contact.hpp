#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

typedef class PhoneBook PhoneBook;

class Contact {
private:
  std::string _index;
  std::string _first_name;
  std::string _last_name;
  std::string _nick_name;
  std::string _phone_number;
  std::string _darkest_secret;

public:
  void c_adder(PhoneBook *book, std::string information[5], int number);
  static std::string check_str(const std::string &information);

  // setters:
  void setIndex(std::string number);
  void setFirstName(std::string name);
  void setLastName(std::string last_name);
  void setNickName(std::string nickname);
  void setPhoneNumber(std::string phone_number);
  void setDaskestSecret(std::string Darkest_secret);

  // getters:
  std::string getIndex();
  std::string getPhoneNumber();
  std::string getFirstName();
  std::string getLastName();
  std::string getNickName();
  std::string getDaskestSecret();
};

#endif
