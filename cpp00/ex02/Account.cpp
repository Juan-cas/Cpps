#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <ostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// getters:

int Account::getNbAccounts(void) { return _nbAccounts; }

int Account::getTotalAmount(void) { return _totalAmount; }

int Account::getNbDeposits(void) { return _totalNbDeposits; }

int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

int Account::checkAmount(void) const { return _amount; }

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";amount:" << _amount
            << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
            << std::endl;
}

// setters:
Account::Account(int initial_deposit) {
  _displayTimestamp();
  _amount = initial_deposit;
  std::cout << " index" << _nbAccounts << ";amount:" << initial_deposit
            << ";created" << std::endl;
  _accountIndex = _nbAccounts;
  _nbDeposits = 0;
  _nbWithdrawals = 0;
  _nbAccounts++;
  _totalAmount += initial_deposit;
}

//[19920104_091532] index:0;amount:47;closed

Account::~Account(void) {
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";Closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
  _amount += deposit;
  _totalAmount += deposit;
  _nbDeposits++;
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";p_amount:" << _amount
            << ";deposit:" << deposit << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  if (_amount < withdrawal) {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount
              << ";withdrawal:refused" << std::endl;
    return false;
  }
  _amount -= withdrawal;
  _totalAmount -= withdrawal;
  _nbWithdrawals++;
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";p_amount:" << _amount
            << "withdrawal:" << withdrawal
            << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
  return true;
}

void Account::_displayTimestamp(void) {
  std::time_t now = std::time(0);
  std::tm *now_tm = std::localtime(&now);
  char buffer[20];
  std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", now_tm);
  std::cout << buffer;
}
