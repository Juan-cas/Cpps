#include "PhoneBook.h"

string itst(int number)
{
  stringstream ss;
  ss << number;
  return ss.str();
}

string check_str(const string& information) {
  if (information.length() > 10)
    return information.substr(0, 9) + '.';
  else
	return (information + string(10 - information.length(), ' '));
}

static string new_contact(int flag) {
  string information;
  if (flag == 0)
    cout << "Please enter the contact First_name: ";
  if (flag == 1)
    cout << "Please enter the contact last_name: ";
  if (flag == 2)
    cout << "Please enter the contact Nickname: ";
  if (flag == 3)
    cout << "Please enter the contact phone number: ";
  if (flag == 4)
    cout << "Please enter the contact Darkest_secret: ";
  while (true) {
    getline(cin, information);
    if (information.empty() == false)
      break;
    else
      cout << "Please enter the information correctly: ";
  }
  information = check_str(information);
  return (information);
}



int main()
{
  PhoneBook book;
  string information[5];
  string checker;
  int    counter = 0;

  cout << "Hi Welcome to your PhoneBook" << endl;
  cout << "Write ADD for adding a contact" << endl;
  cout << "Write SEARCH in order to show the current contacts" << endl;
  cout << "Write EXIT to terminate the program" << endl;
  while(true) {
    getline(cin, checker);
    if (checker == "ADD") {
      for(int i = 0; i < 5; i++) {
        information[i] = new_contact(i);
      }
      book.c_adder(&book, information, counter);
      counter++;
    }
    else if (checker == "SEARCH") {
      book.c_print(&book);
    }
    else if (checker == "EXIT")
      break;
    else
      cout << "Please only use ADD, SEARCH or EXIT" << endl;
  }
  return (0);
}