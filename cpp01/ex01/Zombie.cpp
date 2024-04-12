/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:03:20 by atucci            #+#    #+#             */
/*   Updated: 2024/04/12 22:47:17 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// It’s called an initializer list,
// and it’s a feature of C++ that allows you to initialize member variables directly 
Zombie::Zombie(std::string name)
{
	this->name = name;
	std:: cout << GREEN << this->name << " is being created" << RESET << std::endl;
}

Zombie::Zombie() {}

Zombie::~Zombie()
{
	std::cout << name << RED << " is destroyed" << RESET << std::endl;
}

void Zombie::announce(void)
{
	std::cout << YELLOW << name << RESET << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
