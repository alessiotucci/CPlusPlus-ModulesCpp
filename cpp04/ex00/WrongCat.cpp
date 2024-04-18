/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:48:14 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 16:34:51 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"
#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Constructor called!" << std::endl;
}
// initializer member list
WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	this->type = type;
}

// copy constractor
WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	*this = obj; // enough?
}

WrongCat::~WrongCat() {}

// copy assignment operator
WrongCat& WrongCat::operator=(const WrongCat &obj)
{
	if (this != &obj)
	{
		this->type = obj.type;
	}
	return *this;
}

/* virtual keyword */
void WrongCat::makeSound() const
{
	std::cout << "WeoM! weom! weom!\n";
}
