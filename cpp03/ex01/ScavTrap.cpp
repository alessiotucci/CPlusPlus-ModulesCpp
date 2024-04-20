/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:48:33 by atucci            #+#    #+#             */
/*   Updated: 2024/04/20 15:49:34 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <string>
#include "ClapTrap.hpp"
# define BLUE    "\033[1;34m"
# define PURPLE  "\033[1;35m"
# define GRAY    "\033[1;30m"
# define GREEN   "\033[1;32m"
# define CYAN    "\033[1;36m"
# define YELLOW  "\033[1;33m"
# define RED     "\033[1;31m"
# define RESET   "\033[0m"
# define BG_RESET        "\033[49m"
# define BG_GREEN        "\033[42m"
# define BG_CYAN         "\033[46m"
# define BG_YELLOW       "\033[43m"
# define BG_RED          "\033[41m"


ScavTrap::ScavTrap(std:: string name)
{
	std::cout << BG_GREEN << "ScavTrap" << BG_RESET << " name constructor called\n";
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap()
{
	std::cout << BG_GREEN << "ScavTrap" << BG_RESET << " default constructor called\n";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}
ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	*this = obj;
}

ScavTrap::~ScavTrap()
{
	std::cout << BG_RED << "ScavTrap" << BG_RESET << "destructor is called\n";
}

ScavTrap& ScavTrap::operator= (const ScavTrap &obj)
{
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_hitPoints = obj._hitPoints;
		this->_energyPoints = obj._energyPoints;
		this->_attackDamage = obj._attackDamage;
	}
	return *this;
}

void ScavTrap::guardGate()
{
	std::cout << RED << "ScavTrap is now in Gate keeper mode." << RESET
			  << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ScavTrap "
				  << _name << " attacks "
				  << target << ", causing "
				  << _attackDamage << " points of damage!\n";
		_energyPoints--;
	}
	else
		std::cout << "ScavTrap " << _name
		 << " has no energy points or hit points left to attack.\n";
}
