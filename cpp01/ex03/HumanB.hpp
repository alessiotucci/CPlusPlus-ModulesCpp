/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:05:59 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 15:23:50 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include "Weapon.hpp"
//TODO: HumanB may not always have a Weapon
class HumanB
{
private:
	std::string name;
	Weapon* weapon;
public:
	HumanB(std::string name);
	void setWeapon(Weapon& newWeapon);
	void attack() const;
};
#endif
