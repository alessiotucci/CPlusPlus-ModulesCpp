/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:32:15 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 21:27:32 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>
#include <string>

AMateria::AMateria() { }

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
	}
	return *this;
}

AMateria::AMateria(std::string const & type)
{
	(void)type;
}

std::string const& AMateria::getType() const
{
	return this->type;
}


void AMateria::use(ICharacter& target)
{
	(void)target; // learn
	return; // just for now
}
