/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:14:50 by atucci            #+#    #+#             */
/*   Updated: 2024/04/10 20:13:54 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

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
		getline(cin, firstName);
		cout << "2) Enter lastName\n";
		getline(cin, lastName);
		cout << "3) Enter nickName\n";
		getline(cin, nickName);
		cout << "4) Enter phoneNumber\n";
		getline(cin, phoneNumber);
		cout << "5) Enter darkestSecret\n";
		getline(cin, darkestSecret);
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
	return ;
}

void	PhoneBook::Exit()
{
	return ;
}

