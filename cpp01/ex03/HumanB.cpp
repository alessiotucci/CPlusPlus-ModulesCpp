/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:06:09 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 16:41:02 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

void HumanB::setWeapon(Weapon& newWeapon)
{
	weapon = &newWeapon;
}

void HumanB::attack() const
{
	//TODO: Add the check for null since we are using a pointer
	if (weapon)
		std::cout << name << " attack with their " << weapon->getType() << "\n";
	else
		std::cout << name << " attack with without any weapon " << "\n";
}

