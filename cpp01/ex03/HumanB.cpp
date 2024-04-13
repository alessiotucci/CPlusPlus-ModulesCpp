/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:06:09 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 15:32:32 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
	this->name = name;
}

void HumanB::setWeapon(Weapon& newWeapon)
{
	weapon = &newWeapon;
}

void HumanB::attack() const
{
	//TODO: Add the check for null since we are using a pointer
	std::cout << name
			   << " attack with their "
			   << weapon->getType()
			   << std::endl;
}

