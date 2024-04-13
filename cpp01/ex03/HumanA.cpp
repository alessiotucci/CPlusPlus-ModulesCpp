/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:05:47 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 15:30:33 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

/*HumanA::HumanA(std::string name, Weapon& weapon)
{
	this->name = name;
	this->weapon = weapon; //TODO; this is not good!
}*/
HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

void HumanA::attack() const
{
	std::cout << name
			  << " attack with their "
			  << weapon.getType()
			  << std::endl;
}

