/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:38:59 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 17:24:07 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <string>
#include <iostream>
#include "Animal.hpp"

#include "Dog.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

// initializer member list
Dog::Dog() : Animal()
{
	std::cout << "Dog 🐕 Constructor called!" << std::endl;
	this->brain = new Brain();  // Create a new Brain object
}

// initializer member list
Dog::Dog(std::string type) : Animal(type)
{
	this->type = type;
	this->brain = new Brain();  // Create a new Brain object
}

// copy constructor
Dog::Dog(const Dog &obj) : Animal(obj)
{
	std::cout << "Dog 🐕 copy constructor called!" << std::endl;
	this->brain = new Brain(*obj.brain);  // Create a new Brain object that is a copy of obj's Brain
}

Dog::~Dog()
{
	delete this->brain;  // Delete the Brain object
}

// copy assignment operator
Dog& Dog::operator=(const Dog &obj)
{
	std::cout << "Dog 🐕 copy assignment operator called!" << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
		delete this->brain;  // Delete the old Brain object
		this->brain = new Brain(*obj.brain);  // Create a new Brain object that is a copy of obj's Brain
	}
	return *this;
}

/* virtual keyword */
void Dog::makeSound() const
{
	std::cout << "Wolf! Wolf! Wolf!\n";
}

