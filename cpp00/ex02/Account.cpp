/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:45:04 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/15 21:23:21 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Account.hpp>
#include <ctime>
#include <iostream>

int Account::_nbAccounts         = 0;
int Account::_totalAmount        = 0;
int Account::_totalNbDeposits    = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return (Account::_nbAccounts); }

int Account::getTotalAmount(void) { return (Account::_totalAmount); }

int Account::getNbDeposits(void) { return (Account::_totalNbDeposits); }

int Account::getNbWithdrawals(void) { return (Account::_totalNbWithdrawals); }

Account::Account(void) :
    _accountIndex(getNbAccounts()),
    _amount(0),
    _nbDeposits(0),
    _nbWithdrawals(0)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << checkAmount();
    std::cout << ";created" << std::endl;
    _nbAccounts += 1;
}

Account::Account(int initial_deposit) :
    _accountIndex(getNbAccounts()),
    _amount(initial_deposit),
    _nbDeposits(0),
    _nbWithdrawals(0)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << checkAmount();
    std::cout << ";created" << std::endl;
    _nbAccounts += 1;
    _totalAmount += checkAmount();
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << checkAmount();
    std::cout << ";closed" << std::endl;
    _nbAccounts -= 1;
    _totalAmount -= checkAmount();
    _totalNbDeposits -= this->_nbDeposits;
    _totalNbWithdrawals -= this->_nbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts();
    std::cout << ";total:" << getTotalAmount();
    std::cout << ";deposits:" << getNbDeposits();
    std::cout << ";withdrawals:" << getNbWithdrawals();
    std::cout << std::endl;
}

void Account::_displayTimestamp(void)
{
    struct tm *time_struct;
    time_t     curret_time;
    char       buffer[20];

    curret_time = time(0);
    time_struct = localtime(&curret_time);
    strftime(buffer, sizeof(buffer), "[%Y%m%d_%I%M%S] ", time_struct);
    std::cout << buffer;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";p_amount:" << checkAmount();
    std::cout << ";deposit:" << deposit;
    std::cout << ";amount:" << checkAmount() + deposit;
    std::cout << ";nb_deposits:" << this->_nbDeposits + 1;
    std::cout << std::endl;
    _totalNbDeposits += 1;
    _totalAmount += deposit;
    this->_nbDeposits += 1;
    this->_amount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    if (checkAmount() < withdrawal) {
        std::cout << "index:" << this->_accountIndex;
        std::cout << ";p_amount:" << checkAmount();
        std::cout << ";withdrawal:refused";
        std::cout << std::endl;
        return (false);
    }
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";p_amount:" << checkAmount();
    std::cout << ";withdrawal:" << withdrawal;
    std::cout << ";amount:" << checkAmount() - withdrawal;
    std::cout << ";nb_withdrawals:" << this->_nbWithdrawals + 1;
    std::cout << std::endl;
    _totalNbWithdrawals += 1;
    _totalAmount -= withdrawal;
    this->_nbWithdrawals += 1;
    this->_amount -= withdrawal;
    return (true);
}

int Account::checkAmount(void) const { return (this->_amount); }

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << checkAmount();
    std::cout << ";deposits:" << this->_nbDeposits;
    std::cout << ";withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;
}
