/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:53:10 by dpetrukh          #+#    #+#             */
/*   Updated: 2025/01/18 21:58:03 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>
#include <string.h>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_displayTimestamp();
	std::cout
	<< " index:"
	<< _accountIndex
	<< ";amount:"
	<< initial_deposit
	<< ";created"
	<< std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout
	<< " index:"
	<< _accountIndex
	<< ";amount:"
	<< _amount
	<< ";closed"
	<< std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return ( _totalNbDeposits);
}

int Account::getNbWithdrawals ( void )
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(NULL);
	std::tm* timestamp = std::localtime(&now);

	std::cout
	<< "["
	<< (1900 + timestamp->tm_year)
	<< (timestamp->tm_mon + 1 < 10 ? "0" : "") << (timestamp->tm_mon + 1)
	<< (timestamp->tm_mday < 10 ? "0" : "") << (timestamp->tm_mday)
	<< "_"
	<< (timestamp->tm_hour < 10 ? "0" : "") << (timestamp->tm_hour)
	<< (timestamp->tm_min < 10 ? "0" : "") << (timestamp->tm_min)
	<< (timestamp->tm_sec < 10 ? "0" : "") << (timestamp->tm_sec)
	<< "]";
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout
	<< " accounts:"
	<< _nbAccounts
	<< ";total:"
	<< _totalAmount
	<< ";deposits:"
	<< _totalNbDeposits
	<< ";withdrawals:"
	<< _totalNbWithdrawals
	<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_totalNbDeposits += 1;
	_nbDeposits += 1;
	_amount += deposit;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout
	<< " index:"
	<< _accountIndex
	<< ";p_amount:"
	<< _amount - deposit
	<< ";deposit:"
	<< deposit
	<< ";amount:"
	<< _amount
	<< ";nb_deposits:"
	<< _nbDeposits
	<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout
	<< " index:"
	<< _accountIndex
	<< ";p_amount:"
	<< _amount
	<< ";withdrawal:";
	if (_amount - withdrawal > 0)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		std::cout
		<< withdrawal
		<< ";amount:"
		<< _amount
		<< ";nb_withdrawals:"
		<< _nbWithdrawals
		<< std::endl;
		return (1);
	}
	std::cout
	<< "refused\n";
	return (0);
}

int	Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout
	<< " index:"
	<< _accountIndex
	<< ";amount:"
	<< _amount
	<< ";deposits:"
	<< _nbDeposits
	<< ";withdrawals:"
	<< _nbWithdrawals
	<< std::endl;
}

