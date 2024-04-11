/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:14:22 by atucci            #+#    #+#             */
/*   Updated: 2024/04/11 15:55:09 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook(void);
	void	Add();
	void	Search();
	void	Exit();
	void	PrintLine();
	void	PrintLine(std::string param[4]);

private:
	Contact	_contacts[8];
	int		_savedContacts;
	int		_iterators;
};
#endif
