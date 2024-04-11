/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:19:24 by atucci            #+#    #+#             */
/*   Updated: 2024/04/11 10:22:06 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

using namespace std;
int	main()
{
	string	command;
	PhoneBook my_new_phonebook = PhoneBook();
	cout << "The program only accepts ADD, SEARCH and EXIT\n";
	while (1)
	{
		cout << "| ADD | SEARCH | EXIT |\n";
		//getline(cin, command);
		if (cin >> command)
		{
			if (command.compare("SEARCH") == 0)
				my_new_phonebook.Search();
			if (command.compare("ADD") == 0)
				my_new_phonebook.Add();
			if (command.compare("EXIT") == 0)
			{
				cout << "Exiting the program\n";
				return (0);
			}
		}
		else
		{
			cout << "error with the cin\n";
			return (-1);
		}
	}
	return (1);
}
