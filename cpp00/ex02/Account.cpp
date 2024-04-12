/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:50:34 by atucci            #+#    #+#             */
/*   Updated: 2024/04/12 11:19:11 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <iostream>
#include <ctime>

	int Account::_nbAccounts = 0;
	int Account::_totalAmount = 0;
	int Account::_totalNbDeposits = 0;
	int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals << "\n";
}

// this is the constructor
Account::Account( int initial_deposit )
{
	_amount = initial_deposit; // setting the amount to the first deposit
	_nbAccounts += 1; // increment the account by one
	_accountIndex = _nbAccounts -1; // index starting from zero
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << "\n";
	// increment the total amout of everything
	_totalAmount += initial_deposit;
}
// this is the destructor
Account::~Account( void )
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << "\n";
}
// method for deposit, we need to increment some stuff
void	Account::makeDeposit( int deposit )
{
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	//_amount += deposit; the logic is clear if we do this after
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";deposit:" << deposit // the parameter
				<< ";amount:" << (_amount + deposit)
				<< ";nb_deposits:" << _nbDeposits << "\n";
	// after we print we will update
	_amount += deposit;
	_totalAmount += deposit;
}
/* here there is a little bit more logic */
bool	Account::makeWithdrawal( int withdrawal )
{
	if (_amount >= withdrawal)
	{
	_nbWithdrawals += 1; // increment the counter of the operations
	_totalNbWithdrawals += 1;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:" << withdrawal // the parameters
				<< ";amount:" << (_amount - withdrawal)
				<< ";nb_withdrawals:" <<_nbWithdrawals << "\n";
	_amount -= withdrawal; // after the print we updated
	_totalAmount -= withdrawal;
				return true;
	}
	else
	{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:refused\n";
		return false;
	}
}

int		Account::checkAmount( void ) const
{
	return _amount;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals << "\n";
}

void	Account::_displayTimestamp( void )
{
	// Get the current time as a std::time_t value
	std::time_t now = std::time(0);
	// Convert the std::time_t value to a std::tm structure
	std::tm* now_tm = std::localtime(&now);
	// Print the date and time
	std::cout << '[' << now_tm->tm_year + 1900
	<< std::setw(2) << std::setfill('0') << now_tm->tm_mon + 1
	<< std::setw(2) << std::setfill('0')<< now_tm->tm_mday << '_'
	<< std::setw(2) << std::setfill('0')<< now_tm->tm_hour
	<< std::setw(2) << std::setfill('0')<< now_tm->tm_min
	<< std::setw(2) << std::setfill('0')<< now_tm->tm_sec << "] ";
}
