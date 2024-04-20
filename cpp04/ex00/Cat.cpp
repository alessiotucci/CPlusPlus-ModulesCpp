/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:39:01 by atucci            #+#    #+#             */
/*   Updated: 2024/04/20 20:33:35 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <string>
#include <iostream>
#include "Animal.hpp"

Cat::Cat()
{
	std::cout << "Cat Constructor called!" << std::endl;
}
// initializer member list
Cat::Cat(std::string type) : Animal(type)
{
	this->type = type;
}

// copy constractor
Cat::Cat(const Cat &obj) : Animal(obj)
{
	*this = obj; // enough?
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called!" << std::endl;
}

// copy assignment operator
Cat& Cat::operator=(const Cat &obj)
{
	if (this != &obj)
	{
		this->type = obj.type;
	}
	return *this;
}

/* virtual keyword */
void Cat::makeSound() const
{
	std::cout << "Meow! Meow! Meow!\n";
}
