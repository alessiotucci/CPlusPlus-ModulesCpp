/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:48:16 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 16:28:07 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("")
{
	std::cout << "WrongAnimal Constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string param)
{
	(void)param;
	std::cout << "WrongAnimal param Constructor called!" << std::endl;
}

// copy constractor
WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	*this = obj; // enough?
}

WrongAnimal::~WrongAnimal() {}

// copy assignment operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj)
{
	if (this != &obj)
	{
		this->type = obj.type;
	}
	return *this;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}
/* virtual keyword */
void WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal sound\n";
}
