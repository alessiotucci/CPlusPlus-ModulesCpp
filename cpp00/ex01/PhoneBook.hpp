/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:14:22 by atucci            #+#    #+#             */
/*   Updated: 2024/04/09 21:38:34 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

using std::string;
class PhoneBook
{
public:
	PhoneBook(void);
	void	Add();
	void	Search();
	void	Exit();

private:
	Contact	_contacts[8];
	int		_savedContacts;
	int		_oldest;
};
#endif
