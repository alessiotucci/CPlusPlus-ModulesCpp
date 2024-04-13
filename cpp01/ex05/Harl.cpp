/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:07:19 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 17:27:00 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}


void Harl::_debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!";
	std::cout << std::endl;
}

void Harl::_info()
{
	std::cout << GREEN << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET;
	std::cout << std::endl;
}

void Harl::_warning()
{
	std::cout << YELLOW << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << RESET;
	std::cout << std::endl;
}

void Harl::_error()
{
	std::cout << RED << "This is unacceptable! I want to speak to the manager now." << RESET;
	std::cout << std::endl;
}

void Harl::complain( std::string level)
{
	// create here an array instead of a single elements
	void (Harl::*complaint)() = NULL;

	/*void (Harl::*complaint)() = NULL;*/
	if (level.empty())
	{
		return ;
	}
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
		std::cout <<  "invalid levels here\n";
		break;
	}

	// If a valid level was provided, call the corresponding function
	// here instead of a if, create a while cicle!
	if (complaint != NULL)
	{
		(this->*complaint)();
	}
}
