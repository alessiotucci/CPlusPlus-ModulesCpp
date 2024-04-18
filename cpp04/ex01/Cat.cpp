/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:39:01 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 17:11:36 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <string>
#include <iostream>
#include "Animal.hpp"

Cat::Cat()
{
	std::cout << "Cat 🐈 Constructor called!" << std::endl;
	this->brain = new Brain();  // Create a new Brain object
}
// initializer member list
Cat::Cat(std::string type) : Animal(type)
{
	this->type = type;
	this->brain = new Brain();  // Create a new Brain object
}

// copy constractor
Cat::Cat(const Cat &obj) : Animal(obj)
{
	std::cout << "Cat 🐈 copy constructor called!" << std::endl;
	this->brain = new Brain(*obj.brain);  // Create a new Brain object that is a copy of obj's Brain
}

Cat::~Cat()
{
	delete this->brain;  // Delete the Brain object
}

// copy assignment operator
Cat& Cat::operator=(const Cat &obj)
{
	std::cout << "Cat 🐈 copy assignment operator called!" << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
		delete this->brain;  // Delete the old Brain object
		this->brain = new Brain(*obj.brain);  // Create a new Brain object that is a copy of obj's Brain
	}
	return *this;

}

/* virtual keyword */
void Cat::makeSound() const
{
	std::cout << "Meow! Meow! Meow!\n";
}
