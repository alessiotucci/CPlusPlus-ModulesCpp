/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:38:21 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 17:57:23 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

AAnimal::AAnimal() : type("")
{
	std::cout << "AAnimal Constructor called!" << std::endl;
}

AAnimal::AAnimal(std::string param)
{
	(void)param;
	std::cout << "AAnimal param Constructor called!" << std::endl;
}

// copy constractor
AAnimal::AAnimal(const AAnimal &obj)
{
	*this = obj; // enough?
}

AAnimal::~AAnimal() {}

// copy assignment operator
AAnimal& AAnimal::operator=(const AAnimal &obj)
{
	if (this != &obj)
	{
		this->type = obj.type;
	}
	return *this;
}

std::string AAnimal::getType() const
{
	return this->type;
}
