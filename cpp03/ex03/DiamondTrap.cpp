/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:00:13 by atucci            #+#    #+#             */
/*   Updated: 2024/04/16 21:27:42 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// DiamondTrap.cpp
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	// Initialize attributes here
	this->_attackDamage = FragTrap::getAttackDamage();
	this->_energyPoints = ScavTrap::getEnergyPoints();
	this->_hitPoints = FragTrap::getHitPoints();
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name+"_clap_name"), FragTrap(name), ScavTrap(name)
{
	_name = name;
	this->_attackDamage = FragTrap::getAttackDamage();
	this->_energyPoints = ScavTrap::getEnergyPoints();
	this->_hitPoints = FragTrap::getHitPoints();

}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj), FragTrap(obj), ScavTrap(obj)
{
	*this = obj;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Diamondt Trap Destructor\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &obj)
{
	if (this != &obj)
	{
		ClapTrap::operator=(obj);
		FragTrap::operator=(obj);
		ScavTrap::operator=(obj);
		_name = obj._name;
	}
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "WhoamI: " << _name;
	std::cout << " Base class: " << ClapTrap::getName();
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target); 
}

