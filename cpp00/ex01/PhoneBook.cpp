/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:14:50 by atucci            #+#    #+#             */
/*   Updated: 2024/04/11 10:26:41 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;
PhoneBook::PhoneBook(void)
{
	this->_savedContacts = 0;
}

void	PhoneBook::Add()
{
	string	firstName;
	string	lastName;
	string	nickName;
	string	phoneNumber;
	string	darkestSecret;
	Contact	new_Contact;

	while (1)
	{
		cout << "1) Enter firstName\n";
		cin >> firstName;
		cout << "2) Enter lastName\n";
		cin >> lastName;
		cout << "3) Enter nickName\n";
		cin >> nickName;
		cout << "4) Enter phoneNumber\n";
		cin >> phoneNumber;
		cout << "5) Enter darkestSecret\n";
		cin >> darkestSecret;
		if (!firstName.empty() && !lastName.empty() && !nickName.empty()
			&& !phoneNumber.empty() && !darkestSecret.empty())
			break ;
		cout << RED << "A saved contact can’t have empty field\n" << RESET;
	}
	new_Contact = Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	if (this->_savedContacts < 8)
	{
		this->_contacts[this->_savedContacts] = new_Contact;
		_savedContacts++;
	}
	else
	{
		this->_savedContacts = 0;
		this->_contacts[this->_savedContacts] = new_Contact;
	}
	cout << GREEN << "Contact created\n" << RESET;
	return ;
}

void	PhoneBook::Search()
{
	string definitions[4] = {"INDEX", "FIRST NAME", "LAST NAME", "NICKNAME"};
	string content[4];
	stringstream sos;
	//ss << input;
	//content[0] = sos.str();
	PhoneBook::PrintLine();
	PhoneBook::PrintLine(definitions);
	PhoneBook::PrintLine();
	int count = this->_savedContacts - 1;
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
	cout << "Enter the index of the contact you want to display: ";
	if (cin >> input)
		cout << "Looking for contact at index " << input << endl;
	else
	{
		cin.clear();
		cout << RED << "Invalid input\n" << RESET;
	}
	
	if (input >= 8 || input < 0)
	{
		cout << RED << "Out of bound, be carefull\n" << RESET;
		return ;
	}
	cout << "First name: "<< YELLOW << _contacts[input].getFirstName() << RESET << endl;
	cout << "Last name: " << YELLOW << _contacts[input].getLastName() << RESET << endl;
	cout << "Nickname: " << YELLOW << _contacts[input].getNickname() << RESET << endl;
	cout << "Phone number: " << YELLOW << _contacts[input].getPhoneNumber() << RESET << endl;
	cout << "Darkest Secret: " << YELLOW << _contacts[input].getDarkestSecret() << RESET << endl;
	//stringstream ss;
	//ss << input;

	return ;
}

void	PhoneBook::PrintLine()
{
	for (int i = 0; i < 4; i++)
	{
	 cout << "|";
		for (int j= 0; j < 10; j++)
			cout << "-";
	}
	cout << "|\n";
}

void	PhoneBook::PrintLine(string param[4])
{
	for (int i = 0; i < 4; i++)
	{
		cout << "|";
		int len = param[i].length();
		if (len > 10)
		{
			param[i] = param[i].substr(0, 9) + ".";
			len = 10;
		}
		cout << right << setw(10) << param[i]; // Right align with field width of 10
	}
	cout << "|\n";
}

