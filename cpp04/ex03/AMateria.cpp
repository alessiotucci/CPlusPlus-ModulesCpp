/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:32:15 by atucci            #+#    #+#             */
/*   Updated: 2024/04/20 18:57:12 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>
#include <string>

AMateria::AMateria() { }

//AMateria::AMateria(std::string type) : type(type) { }

AMateria::~AMateria() { }

AMateria::AMateria(const AMateria &obj)
{
	*this = obj;
}

AMateria& AMateria::operator=(const AMateria &obj)
{
	if (this != &obj)
	{
		// assign
		this->type = obj.type;
	}
	return *this;
}

AMateria::AMateria(std::string const & type) : type(type) {}

std::string const& AMateria::getType() const
{
	return this->type;
}


// TODO: finish implement the Character
void AMateria::use(ICharacter& target)
{
	(void)target; // learn
	return; // just for now
}
