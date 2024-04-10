/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:19:24 by atucci            #+#    #+#             */
/*   Updated: 2024/04/10 19:51:35 by atucci           ###   ########.fr       */
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
		cout << "Waiting for a command\n";
		getline(cin, command);
		if (command.compare("SEARCH") == 0)
		{
			cout << "Start search...\n";
			my_new_phonebook.Search();
		}
		if (command.compare("ADD") == 0)
		{
			cout << "Let's add\n";
			my_new_phonebook.Add();
		}
		if (command.compare("EXIT") == 0)
		{
			cout << "Exiting the program\n";
			return (0);
		}
	}
	return (1);
}
