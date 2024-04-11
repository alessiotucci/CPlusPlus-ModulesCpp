/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:10:02 by atucci            #+#    #+#             */
/*   Updated: 2024/04/11 15:58:43 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {} //empty constructor

Contact::Contact(std::string firstN, std::string lastN, std::string nick, std::string phoneN, std::string darkestSecret)
{
	this->_firstName = firstN;
	this->_lastName = lastN;
	this->_nickname = nick;
	this->_phoneNumber = phoneN;
	this->_darkestSecret = darkestSecret;
}
std::string	Contact::getFirstName()
{
	return this->_firstName;
}

std::string	Contact::getLastName()
{
	return this->_lastName;
}

std::string	Contact::getNickname()
{
	return this->_nickname;
}

std::string	Contact::getPhoneNumber()
{
	return this->_phoneNumber;
}

std::string	Contact::getDarkestSecret()
{
	return this->_darkestSecret;
}
