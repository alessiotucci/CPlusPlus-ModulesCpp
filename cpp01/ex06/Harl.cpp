/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:08:19 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 16:21:18 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}


void Harl::_debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n"
			<< std::endl;
}

void Harl::_info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << GREEN << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n"
		<< RESET
		<< std::endl;
}

void Harl::_warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << YELLOW << "I think I deserve to have some extra bacon for free."
			  << std::endl
			  <<"I’ve been coming for years whereas you started working here since last month.\n"
			  << RESET << std::endl;;
}

void Harl::_error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << RED << "This is unacceptable! I want to speak to the manager now.\n"
			  << RESET<< std::endl;;
}

void Harl::complain( std::string level)
{
	// create here an array instead of a single elements
	void (Harl::*complaint[4])() ={&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	int start_level = 0;
	/*void (Harl::*complaint)() = NULL;*/
	if (level.empty())
	{
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		return ;
	}
	switch (level[0])
	{
		case 'D':
		start_level = 0;
		break ;

		case 'I':
		start_level = 1;
		break ;

		case 'W':
		start_level = 2;
		break ;

		case 'E':
		start_level = 3;
		break ;

		default:
		std:: cout <<  "invalid levels here\n";
		break;
	}

	// If a valid level was provided, call the corresponding function
	// here instead of a if, create a while cicle!
	/*if (complaint != NULL)*/
	for(int i = start_level; i < 4; i++)
	{
		(this->*complaint[i])();
	}
}
