/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:55:14 by atucci            #+#    #+#             */
/*   Updated: 2024/04/20 19:16:38 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include <iostream>

Ice::Ice () : AMateria("ice") { }
							// call base class constructor
//Ice::Ice (std:: string name) : type(name) { }

Ice::Ice (const Ice &obj) : AMateria(obj)
{
	*this = obj;
} // TODO
Ice::~Ice () { }

Ice & Ice::operator = (const Ice &obj)
{
	if (this != &obj)
	{
		this->type = obj.type;
	}
	return *this;
}

/* implementation of method Use() and Clone() */
AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return;
}

