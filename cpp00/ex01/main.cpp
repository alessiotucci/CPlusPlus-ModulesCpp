/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:19:24 by atucci            #+#    #+#             */
/*   Updated: 2024/04/09 20:26:26 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

using namespace std;
int	main()
{
	string	name;
	while (1)
	{
		cout << "This is a Phonebook\n";
		getline(cin, name);
	}
}
