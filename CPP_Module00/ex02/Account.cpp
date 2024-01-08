#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>

int Account::_totalAmount;
int Account::_nbAccounts;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account(int initial_deposit)
{
    _totalAmount        +=  initial_deposit;
    _amount             =   initial_deposit;
    _accountIndex       =   _nbAccounts;
    _nbDeposits         =   0;
    _nbWithdrawals      =   0;

    _displayTimestamp();
    std::cout   << "index:" 
                << _accountIndex 
                << ";amount:" 
                << _amount 
                << ";created" 
                << std::endl;

    _nbAccounts++;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout   << "index:" 
                << _accountIndex 
                << ";amount:" 
                << _amount 
                << ";closed" << std::endl;
}

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout   << "accounts:" 
                << _nbAccounts 
                << ";total:" 
                << _totalAmount 
                << ";deposits:" 
                << _totalNbDeposits 
                << ";withdrawals:" 
                << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _amount         += deposit;
    _totalAmount    += deposit;
    _totalNbDeposits++;
    _nbDeposits++;

    _displayTimestamp();
    std::cout   << "index:"
                << _accountIndex 
                << ";p_amount:"
                << (_amount - deposit) 
                << ";deposit:"
                << deposit
                << ";amount:"
                << _amount
                << ";nb_deposits:"
                << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    if (_amount - withdrawal < 0)
    {
        _displayTimestamp();
        std::cout << "index:"
                  << _accountIndex
                  << ";p_amount:"
                  << (_amount)
                  << ";withdrawal:"
                  << "refused" << std::endl;
        return (false);
    }
    else
    {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        _nbWithdrawals++;

        _displayTimestamp();
        std::cout << "index:"
                  << _accountIndex
                  << ";p_amount:"
                  << (_amount + withdrawal)
                  << ";withdrawal:"
                  << withdrawal
                  << ";amount:"
                  << _amount
                  << ";nb_withdrawals:"
                  << _nbWithdrawals << std::endl;
        return (true);
    }
}

int Account::checkAmount(void) const
{
    return _amount;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout   << "index:"
                << _accountIndex 
                << ";amount:"
                << _amount 
                << ";deposits:"
                << _nbDeposits
                << ";withdrawals:"
                << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void ){
    //Create a function that displays the time and date in the following order:
    //Year + Month + Day _ Hour + Minutes + Seconds

    time_t now  = time(0);
    tm* ltm     = localtime(&now);
    std::cout   << "[" 
                << 1900 + ltm->tm_year 
                << "0" 
                << 1 + ltm->tm_mon 
                << "0" 
                << ltm->tm_mday 
                << "_" 
                << ltm->tm_hour 
                << ltm->tm_min 
                << ltm->tm_sec 
                << "] ";
}