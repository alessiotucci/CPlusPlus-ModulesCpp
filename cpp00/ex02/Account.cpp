/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:50:34 by atucci            #+#    #+#             */
/*   Updated: 2024/04/11 17:47:40 by atucci           ###   ########.fr       */
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
/*static int	getNbAccounts( void )
{

}

static int	getTotalAmount( void )
{

}

static int	getNbDeposits( void )
{

}

static int	getNbWithdrawals( void )
{

}
*/
/*static*/ void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "account: " << "total: " << "deposit: " << "withdrawls " << "\n";
}

// this is the constructor
Account::Account( int initial_deposit )
{
	Account::_displayTimestamp();
	std::cout << "index: " << _accountIndex; 
	std::cout << "amount: " << initial_deposit << ";created" << "\n";
}
// this is the destructor
Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex; 
	std::cout << "amount:" << _amount << ";closed" << "\n";
}

void	Account::makeDeposit( int deposit )
{
	(void)deposit;
	Account::_displayTimestamp();
	std::cout << "amount " << "deposit " << "amount " << "nb_deposit" << "\n";
}

bool	Account::makeWithdrawal( int withdrawal )
{
	(void)withdrawal;
	Account::_displayTimestamp();
	std::cout << "amount " << "withdrawal " << "amount " << "nb_withdrawals:" << "\n";
	return true;
}

int		Account::checkAmount( void ) const
{
	return 0;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index: " << "amount: " << "deposit " << "withdraws " << "\n";
}

/*static*/ void	Account::_displayTimestamp( void )
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
