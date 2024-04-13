/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:05:29 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 15:19:44 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
#include <iostream>
//TODO: HumanA takes the Weapon in its constructor
/*		HumanA will ALWAYS be armed */
class HumanA
{
private:
	std::string name;
	Weapon& weapon;
public:
	HumanA(std::string name, Weapon& weapon);
	void attack() const;
};
#endif
