#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

string  itst(int number);
string  check_str(const string& information);

class Users {
  public:
    string index;
    string first_name;
    string last_name;
    string nick_name;
    string phone_number;
    string darkest_secret;
};

class PhoneBook {
  Users contacts[8];
  public:
    void c_adder(PhoneBook *book, string information[5], int number) {
      if (number > 7) {
        number = 7;
      }
        book->contacts[number].index = check_str(itst(number + 1));
        book->contacts[number].first_name = information[0];
        book->contacts[number].last_name = information[1];
        book->contacts[number].nick_name = information[2];
        book->contacts[number].phone_number = information[3];
        book->contacts[number].darkest_secret = information[4];
    };

    void c_print(PhoneBook *book) {
        cout << setw(10) << "Index     " << "|" << setw(10) << "First Name" << "|"
             << setw(10) << "Last Name " << "|" << setw(10) << "Nickname  " << endl;
        cout << string(43, '-') << endl;

        for (int i = 0; i < 8; i++) {
            if (book->contacts[i].first_name.empty() == true)
              break;
            cout << setw(10) << book->contacts[i].index << "|"
                 << setw(10) << book->contacts[i].first_name << "|"
                 << setw(10) << book->contacts[i].last_name << "|"
                << setw(10) << book->contacts[i].nick_name << endl;
        }
    }
};


#endif