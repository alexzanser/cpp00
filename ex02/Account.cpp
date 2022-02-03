#include "Account.hpp"
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	Account::_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts += 1;
	Account::_amount = initial_deposit;
	Account::_totalAmount += Account::_amount;
	Account::_nbDeposits = 0;
	Account::_totalNbDeposits += Account::_nbDeposits;
	Account::_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "closed" << std::endl;
}

int Account::getNbAccounts( void )
{
    return (Account::_nbAccounts);
}

int Account::getTotalAmount( void )
{
    return (Account::_totalAmount);
}

int Account::getNbDeposits( void )
{
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
    return (Account::_totalNbWithdrawals);
}

void Account::_displayTimestamp( void )
{
   time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    std::cout << "[" << (now->tm_year + 1900) 
		<< std::setfill('0') 
		<< std::setw(2) << (now->tm_mon + 1) 
        << std::setw(2) <<  now->tm_mday << "_" 
		<<  std::setw(2) <<  now->tm_hour
		<<  std::setw(2) <<  now->tm_min
		<< std::setw(2) <<  now->tm_sec << "] ";
}

int Account:: checkAmount( void ) const
{
	return (Account::_amount);
}

void Account:: displayStatus( void ) const
{
    _displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "deposits:" << Account::_nbDeposits << ";";
	std::cout << "withdrawals:" << Account::_nbWithdrawals << std::endl;
}

void Account:: displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account:: makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "p_amount:" << Account::_amount << ";";
	Account::_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	std::cout << "deposit:" << deposit << ";";
	Account::_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "nb_deposits:" << Account::_nbDeposits << std::endl;
}

bool Account:: makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "p_amount:" << Account::_amount << ";";
	if (withdrawal > Account::checkAmount())
		{
			std::cout << "withdrawal:refused" << std::endl;
			return (false);
		}
	Account::_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;
	std::cout << "withdrawal:" << withdrawal << ";";
	Account::_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "nb_withdrawals:" << Account::_nbWithdrawals << std::endl;
	return (true);
}
