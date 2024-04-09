/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:10:02 by atucci            #+#    #+#             */
/*   Updated: 2024/04/09 21:43:11 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {} //empty constructor

Contact::Contact(string firstN, string lastN, string nick, string phoneN, string darkestSecret)
{
	this->_firstName = firstN;
	this->_lastName = lastN;
	this->_nickname = nick;
	this->_phoneNumber = phoneN;
	this->_darkestSecret = darkestSecret;
}
string	Contact::getFirstName()
{
	return this->_firstName;
}

string	Contact::getLastName()
{
	return this->_lastName;
}

string	Contact::getNickname()
{
	return this->_nickname;
}

string	Contact::getPhoneNumber()
{
	return this->_phoneNumber;
}

string	Contact::getDarkestSecret()
{
	return this->_darkestSecret;
}
