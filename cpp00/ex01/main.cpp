/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:19:24 by atucci            #+#    #+#             */
/*   Updated: 2024/04/09 22:01:01 by atucci           ###   ########.fr       */
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
	cout << "| SEARCH | ADD | EXIT |\n";
	while (1)
	{
		cout << "Waiting for a command\n";
		getline(cin, command);
		if (command.compare("SEARCH") == 0)
			cout << "Start search...\n";
		if (command.compare("ADD") == 0)
			cout << "Let's add\n";
		if (command.compare("EXIT") == 0)
			return (0);
	}
	return (1);
}
