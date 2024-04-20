/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:55:15 by atucci            #+#    #+#             */
/*   Updated: 2024/04/20 19:13:23 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include <iostream>

Cure::Cure () : AMateria("cure"){ }

//Cure::Cure (std:: string name) : name(name) { }

Cure::Cure (const Cure &obj) : AMateria(obj)
{
	*this = obj;
}
Cure::~Cure () { }

Cure & Cure::operator = (const Cure &obj)
{
	if (this != &obj)
	{
		this->type = obj.type;
	}
	return *this;
}

/* implementation of method Use() and Clone() */
AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	return;
}
