/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:55:00 by atucci            #+#    #+#             */
/*   Updated: 2024/04/20 19:35:34 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource () : index(0)
{
	for(int i = 0; i < 4; ++i)
		materias[i] = NULL;
}

MateriaSource::MateriaSource (const MateriaSource &obj)
{
	*this = obj;
}

MateriaSource::~MateriaSource ()
{
	for(int i = 0; i < 4; ++i)
		delete materias[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource &obj)
{
	if (this != &obj)
	{
		// INVALID: this->materias = obj.materias;
		// Delete old materias
		for (int i = 0; i < 4; ++i)
			delete materias[i];
		// Copy new materias
		for (int i = 0; i < 4; ++i)
		{
			if (obj.materias[i])
				materias[i] = obj.materias[i]->clone();
			else
				materias[i] = 0;
		}
		this->index = obj.index;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m)
	{
		if (m && index < 4)
			materias[index++] = m->clone();
		else
			std::cout << "array is full of materia!!\n";
	}
	else
		std::cout << "parameter null\n";
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (materias[i] && materias[i]->getType() == type)
		{
			return materias[i]->clone();
		}
	}
	std::cout << "no match with this type of material\n";
	return NULL;
}

