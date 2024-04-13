/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:05:09 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 15:34:01 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
const std::string&	Weapon::getType() const
{
	return type;
}

void	Weapon::setType(std::string param)
{
	type = param;
}

Weapon::Weapon(std:: string _type)
{
	this->type = _type;
}

Weapon::~Weapon() {}
