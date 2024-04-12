/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:19:24 by atucci            #+#    #+#             */
/*   Updated: 2024/04/12 14:22:18 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main()
{
	std::string	command;
	PhoneBook my_new_phonebook = PhoneBook();
	std::cout << "The program only accepts ADD, SEARCH and EXIT\n";
	while (1)
	{
		//cout << "| ADD | SEARCH | EXIT |\n";
		//getline(cin, command);
		if (std::cin >> command)
		{
			if (command.compare("SEARCH") == 0)
				my_new_phonebook.Search();
			if (command.compare("ADD") == 0)
				my_new_phonebook.Add();
			if (command.compare("EXIT") == 0)
			{
				std::cout << "Exiting the program\n";
				return (0);
			}
		}
		else
		{
			std::cin.clear();
			std::cout << "error with the cin\n";
			return (-1);
		}
	}
	return (1);
}
