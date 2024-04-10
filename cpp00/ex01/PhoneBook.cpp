/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:14:50 by atucci            #+#    #+#             */
/*   Updated: 2024/04/10 22:34:38 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
PhoneBook::PhoneBook(void)
{
	this->_savedContacts = 0;
	this->_oldest = 0;
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
	cout << GREEN << "Contact created\n" << RESET;
	return ;
}

void	PhoneBook::Search()
{
	int	input;
	string definitions[4] = {"INDEX", "FIRST NAME", "LAST NAME", "NICKNAME"};
	string content[4];
	cout << "Enter the index of the contact you want to display: ";
	if (cin >> input)
		cout << "Looking for contact at index " << input << endl;
	else
	{
		cin.clear();
		cout << RED << "Invalid input\n" << RESET;
	}
	
	if (input >= 8)
	{
		cout << RED << "Out of bound, be carefull\n" << RESET;
		return ;
	}
    //int num = 123;
    //std::stringstream ss;
	stringstream ss;
    ss << input;
    //std::string str = ss.str();
	content[0] = ss.str(); //input; // make it as string;
	content[1] = _contacts[input].getFirstName();
	content[2] = _contacts[input].getLastName();
	content[3] = _contacts[input].getNickname();
	PhoneBook::PrintLine();
	PhoneBook::PrintLine(definitions);
	PhoneBook::PrintLine();
	PhoneBook::PrintLine(content);
	PhoneBook::PrintLine();
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
		for (int j = 0; j < 10 - len; j++)
		{
			cout << " ";
		}
		cout << param[i];
	}
	cout << "|\n";
}

