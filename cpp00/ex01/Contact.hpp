/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:14:37 by atucci            #+#    #+#             */
/*   Updated: 2024/04/09 21:24:46 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

using std::string;

class	Contact
{
public:
	Contact();
	Contact(string firstName, string lastName, string nickname, string phoneNumber, string darkestSecret);
	string	getFirstName();
	string	getLastName();
	string	getNickname();
	string	getPhoneNumber();
	string	getDarkestSecret();

private:
	string	_firstName;
	string	_lastName;
	string	_nickname;
	string	_phoneNumber;
	string	_darkestSecret;
};

#endif
