
#include <iostream>
#include <ctime> 
#include "Account.hpp"

// Static members
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Private constructor (not used)
Account::Account(void) {}

// Utils
void Account::_displayTimestamp(void) {
	std::time_t now = std::time(nullptr);
	std::tm *ptm = std::localtime(&now);
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", ptm);
	std::cout << buffer;
}

/*
Constructor, Assigns a unique _accountIndex based on the current number of accounts.
Initializes:
_amount to the initial_deposit
_nbDeposits and _nbWithdrawals to 0
Increments:
_nbAccounts (total number of accounts)
_totalAmount (adds new deposit to global total)
Logs the account creation with timestamp.
*/ 

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created" << std::endl;
}
// DESTRUCTOR Called when an account object is destroyed. Logs account closure with its index and current amount.

Account::~Account(void) 
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
}

// STATIC GETTERS
// These return the current global stats:
int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}
int Account::getTotalAmount(void)
{
	return _totalAmount;
}
// // Static Summary Display, Shows summary info across all accounts. Called in tests.cpp after major operations.
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
			  << "total:" << getTotalAmount()
			  << "deposits:" << getNbDeposits()
			  << "withdrawals:" << getNbWithdrawals()
			  << std::endl;
}

// // Individual Account Display, displays the current state of one account
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << "amount:" << _amount
			  << "deposits:" << _totalNbDeposits
			  << "withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}

// Returns current balance in the account. Used for internal checks (like makeWithdrawal).
int Account::checkAmount(void)const
{
	return _amount;
}
/*
Logs the deposit intent with previous amount (p_amount).
Updates:
Individual account amount.
Local and global deposit counters.
Global total.
Logs updated state.
*/

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount
			  << ";deposit:" << deposit;

	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits
			  << std::endl;
}

/*
Checks if there’s enough money.
If not enough, logs withdrawal:refused and returns false.
If enough, updates:
Balance
Withdrawal counters
Global total
Logs the transaction and returns true.
*/
bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount;

	if (_amount < withdrawal) {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout << ";withdrawal:" << withdrawal
			  << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals
			  << std::endl;

	return true;
}
