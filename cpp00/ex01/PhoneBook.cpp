/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:14:50 by atucci            #+#    #+#             */
/*   Updated: 2024/04/11 15:59:46 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

PhoneBook::PhoneBook(void)
{
	this->_savedContacts = 0;
	this->_iterators = 0;
}

void	PhoneBook::Add()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	Contact	new_Contact;

	while (1)
	{
		std::cout << "1) Enter firstName\n";
		std::cin >> firstName; // add control
		std::cout << "2) Enter lastName\n";
		std::cin >> lastName; // add controll
		std::cout << "3) Enter nickName\n";
		std::cin >> nickName; // ADD CONTROL
		std::cout << "4) Enter phoneNumber\n";
		std::cin >> phoneNumber;
		std::cout << "5) Enter darkestSecret\n";
		std::cin >> darkestSecret;
		if (!firstName.empty() && !lastName.empty() && !nickName.empty()
			&& !phoneNumber.empty() && !darkestSecret.empty())
			break ;
		std::cout << RED << "A saved contact can’t have empty field\n" << RESET;
	}
	new_Contact = Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	if (this->_iterators < 8)
	{
		this->_contacts[this->_iterators] = new_Contact;
		if (this->_savedContacts < 8) // this check fixed
			_savedContacts++;
		_iterators++;
	}
	else
	{
		this->_iterators = 0;
		this->_contacts[this->_iterators] = new_Contact;
		this->_iterators++;
	}
	std::cout << GREEN << "Contact created\n" << RESET;
	return ;
}

void	PhoneBook::Search()
{
	std::string definitions[4] = {"INDEX", "FIRST NAME", "LAST NAME", "NICKNAME"};
	std::string content[4];
	std::stringstream sos;
	int count;

	if (_contacts[0].getFirstName().empty())
	{
		std::cout << RED << "The phonebook is empty\n" << RESET ;
		return ;
	}
	PhoneBook::PrintLine();
	PhoneBook::PrintLine(definitions);
	PhoneBook::PrintLine();
	count = this->_savedContacts - 1;
	while (count >= 0)
	{
		sos.str(""); // Clear the string stream
		sos.clear(); // Clear any error flags
		sos << count;
		content[0] = sos.str();
		content[1] = _contacts[count].getFirstName();
		content[2] = _contacts[count].getLastName();
		content[3] = _contacts[count].getNickname();
		PhoneBook::PrintLine(content);
		PhoneBook::PrintLine();
		count--;
	}
	int	input;
	std::cout << "\nEnter the index of the contact you want to display: ";
	if (std::cin >> input)
		std::cout << "Looking for contact at index " << input << std::endl;
	else
	{
		std::cin.clear();
		std::cout << RED << "Invalid input\n" << RESET;
		return ;
	}
	
	if (input >= 8 || input < 0)
	{
		std::cout << RED << "Out of bound, be carefull\n" << RESET;
		return ;
	}
	std::cout << "First name: "<< YELLOW << _contacts[input].getFirstName() << RESET << std::endl;
	std::cout << "Last name: " << YELLOW << _contacts[input].getLastName() << RESET << std::endl;
	std::cout << "Nickname: " << YELLOW << _contacts[input].getNickname() << RESET << std::endl;
	std::cout << "Phone number: " << YELLOW << _contacts[input].getPhoneNumber() << RESET << std::endl;
	std::cout << "Darkest Secret: " << YELLOW << _contacts[input].getDarkestSecret() << RESET << std::endl;

	return ;
}

void	PhoneBook::PrintLine()
{
	for (int i = 0; i < 4; i++)
	{
		std::cout << "|";
		for (int j= 0; j < 10; j++)
			std::cout << "-";
	}
	std::cout << "|\n";
}

void	PhoneBook::PrintLine(std::string param[4])
{
	for (int i = 0; i < 4; i++)
	{
		std::cout << "|";
		if (!param[i].empty() && param[i].length() > 10)
			param[i] = param[i].substr(0, 9) + ".";
		std::cout << std::right << std::setw(10) << param[i]; // Right align with field width of 10
	}
	std::cout << "|\n";
}

