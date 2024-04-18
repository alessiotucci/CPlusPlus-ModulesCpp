/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:38:59 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 15:35:43 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <string>
#include <iostream>
#include "Animal.hpp"

// initializer member list
Dog::Dog() : Animal()
{
	std::cout << "Dog Constructor called!" << std::endl;
}
// initializer member list
Dog::Dog(std::string type) : Animal(type)
{
	this->type = type;
}

// copy constractor
Dog::Dog(const Dog &obj) : Animal(obj)
{
	*this = obj; // enough?
}

Dog::~Dog() {}

// copy assignment operator
Dog& Dog::operator=(const Dog &obj)
{
	if (this != &obj)
	{
		this->type = obj.type;
	}
	return *this;
}

/* virtual keyword */
void Dog::makeSound() const
{
	std::cout << "Wolf! Wolf! Wolf!\n";
}
