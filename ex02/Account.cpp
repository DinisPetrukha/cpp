/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:53:10 by dpetrukh          #+#    #+#             */
/*   Updated: 2025/01/13 14:20:00 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>
#include <string.h>
#include <ctime>

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_totalAmount += _totalAmount;
	_amount = initial_deposit;
	_displayTimestamp();
	std::cout
	<< " index:"
	<< _accountIndex
	<< ";amount:"
	<< initial_deposit
	<< ";created";
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout
	<< " index:"
	<< _accountIndex
	<< ";amount:"
	<< _amount
	<< ";created";
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
	<< _totalNbWithdrawals;
}

