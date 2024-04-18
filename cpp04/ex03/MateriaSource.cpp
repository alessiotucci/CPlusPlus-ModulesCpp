/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:55:00 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 22:00:10 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSoource.hpp"

MateriaSource::MateriaSource () { }

MateriaSource::MateriaSource (const MateriaSource &obj)
{
	*this = obj;
}

MateriaSource::~MateriaSource () { }

MateriaSource& MateriaSource::operator=(const MateriaSource &obj)
{
	if (*this != obj)
	{

	}
	return *this;
}

void MateriaSource::learnMateria(AMateria*)
{

}

AMateria* MateriaSource::createMateria(std::string const & type)
{

}

