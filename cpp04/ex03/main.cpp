/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:07:27 by atucci            #+#    #+#             */
/*   Updated: 2024/04/20 20:55:20 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

#include <iostream>

#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

int main()
{
	std::cout << GREEN << "Creating MateriaSource..." << RESET << std::endl;
	IMateriaSource* src = new MateriaSource();

	std::cout << CYAN << "Learning Ice and Cure materias..." << RESET << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << GREEN << "Creating Character 'me'..." << RESET << std::endl;
	ICharacter* me = new Character("me");

	std::cout << CYAN << "Creating and equipping Ice materia..." << RESET << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);

	std::cout << CYAN << "Creating and equipping Cure materia..." << RESET << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << CYAN << "Trying to equip more than 4 materias..." << RESET << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		tmp = src->createMateria("ice");
		me->equip(tmp);
	}

	std::cout << GREEN << "Testing Character copy constructor and assignment operator..." << RESET << std::endl;
	ICharacter* copyOfMe = new Character(*dynamic_cast<Character*>(me)); // Copy constructor
	ICharacter* anotherMe = new Character("anotherMe");
	*dynamic_cast<Character*>(anotherMe) = *dynamic_cast<Character*>(me); // Assignment operator

	std::cout << GREEN << "Creating Character 'bob'..." << RESET << std::endl;
	ICharacter* bob = new Character("bob");

	std::cout << CYAN << "Using materias on 'bob'..." << RESET << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << CYAN << "Using copied materias on 'bob'..." << RESET << std::endl;
	copyOfMe->use(0, *bob);
	copyOfMe->use(1, *bob);

	std::cout << CYAN << "Using assigned materias on 'bob'..." << RESET << std::endl;
	anotherMe->use(0, *bob);
	anotherMe->use(1, *bob);

	std::cout << CYAN << "Unequipping materias..." << RESET << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		me->unequip(i);
	}

	std::cout << RED << "Deleting characters and MateriaSource..." << RESET << std::endl;
	delete bob;
	delete me;
	delete copyOfMe;
	delete anotherMe;
	delete src;

	return 0;
}

