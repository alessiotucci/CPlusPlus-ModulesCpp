/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:08:19 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 14:16:55 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}


void Harl::_debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::_info()
{
	std::cout << GREEN << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << RESET;
}

void Harl::_warning()
{
	std::cout << YELLOW << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << RESET;
}

void Harl::_error()
{
	std::cout << RED << "This is unacceptable! I want to speak to the manager now.\n" << RESET;
}

void Harl::complain( std::string level)
{
//	if (level.compare("DEBUG") == 0)
//		this->*_debug();
//	if (level.compare("INFO") == 0)
//		this->*_info();
//	if (level.compare("WARNING") == 0)
//		this->*_warning();
//	if (level.compare("ERROR") == 0)
//		this->*_error();
/*			TODO: study well this part! */
// Declare a member function pointer and initialize it to NULL
//
    void (Harl::*complaint)() = NULL;
/*
    // Assign the appropriate member function to the pointer
    if (level == "DEBUG")
        complaint = &Harl::_debug;
    else if (level == "INFO")
        complaint = &Harl::_info;
    else if (level == "WARNING")
        complaint = &Harl::_warning;
    else if (level == "ERROR")
        complaint = &Harl::_error;
*/
	switch (level[0])
	{
		case 'D':
		complaint = &Harl::_debug;
		break ;

		case 'I':
		complaint = &Harl::_info;
		break ;

		case 'W':
		complaint = &Harl::_warning;
		break ;

		case 'E':
		complaint = &Harl::_error;
		break ;

		default:
		std:: cout <<  "invalid levels here\n";
		break;
	}

    // If a valid level was provided, call the corresponding function
    if (complaint != NULL)
        (this->*complaint)();
}
