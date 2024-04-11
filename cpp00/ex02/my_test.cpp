/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_test.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:19:18 by atucci            #+#    #+#             */
/*   Updated: 2024/04/11 12:21:31 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(void)
{

	// Define some types for convenience
	typedef std::vector<Account::t> accounts_t; // A vector of Account objects
	typedef std::vector<int> ints_t; // A vector of integers
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t; // A pair of iterators

	// Initialize arrays with the initial deposit amounts, deposit amounts, and withdrawal amounts
	int const amounts[] = {42, 54, 957, 432, 1234, 0, 754, 16576};
	int const d[] = {5, 765, 564, 2, 87, 23, 9, 20};
	int const w[] = {321, 34, 657, 4, 76, 275, 657, 7654};

	// Create vectors from the arrays
	accounts_t accounts(amounts, amounts + sizeof(amounts) / sizeof(int));
	ints_t deposits(d, d + sizeof(d) / sizeof(int));
	ints_t withdrawals(w, w + sizeof(w) / sizeof(int));

	// Create iterators pointing to the beginning and end of the vectors
	accounts_t::iterator acc_begin = accounts.begin();
	accounts_t::iterator acc_end = accounts.end();
	ints_t::iterator dep_begin = deposits.begin();
	ints_t::iterator dep_end = deposits.end();
	ints_t::iterator wit_begin = withdrawals.begin();
	ints_t::iterator wit_end = withdrawals.end();

	// Display the initial state of all accounts
	Account::displayAccountsInfos();
	std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));

	// Iterate over the accounts and the deposit amounts simultaneously
	// For each account, make a deposit of the corresponding amount
	for (acc_int_t it(acc_begin, dep_begin); it.first != acc_end && it.second != dep_end; ++(it.first), ++(it.second))
	{
		(*(it.first)).makeDeposit(*(it.second));
	}

	// Display the state of all accounts after making deposits
	Account::displayAccountsInfos();
	std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));

	// Iterate over the accounts and the withdrawal amounts simultaneously
	// For each account, attempt to make a withdrawal of the corresponding amount
	for (acc_int_t it(acc_begin, wit_begin); it.first != acc_end && it.second != wit_end; ++(it.first), ++(it.second))
	{
		(*(it.first)).makeWithdrawal(*(it.second));
	}

	// Display the final state of all accounts
	Account::displayAccountsInfos();
	std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));

	return 0;
}

