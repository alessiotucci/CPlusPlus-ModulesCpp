/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:38:21 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 17:20:11 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("")
{
	std::cout << "Animal Constructor called!" << std::endl;
}

Animal::Animal(std::string param)
{
	(void)param;
	std::cout << "Animal param Constructor called!" << std::endl;
}

// copy constractor
Animal::Animal(const Animal &obj)
{
	*this = obj; // enough?
}

Animal::~Animal() {}

// copy assignment operator
Animal& Animal::operator=(const Animal &obj)
{
	if (this != &obj)
	{
		this->type = obj.type;
	}
	return *this;
}

std::string Animal::getType() const
{
	return this->type;
}
/* virtual keyword */
void Animal::makeSound() const
{
	std::cout << "Animal sound\n";
}
//https://stackoverflow.com/questions/33350175/c-override-inherited-methods
