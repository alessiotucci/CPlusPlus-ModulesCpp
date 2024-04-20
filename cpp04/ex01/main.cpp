/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:05:50 by atucci            #+#    #+#             */
/*   Updated: 2024/04/20 20:42:09 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

int main()
{
	std::cout << "SUBJECT TEST \n\n";
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
		Dog basic;
	std::cout << "Address of basic's brain: " << basic.getBrain() << std::endl;

	{
		Dog tmp = basic;
		std::cout << "Address of tmp's brain: " << tmp.getBrain() << std::endl;
	}

	std::cout << "Address of basic's brain after tmp's destruction: " << basic.getBrain()
	 << std::endl;
/*
	std::cout << GREEN << "Creating Animals..." << RESET << std::endl;
	Animal** animals = new Animal*[10];  // Create an array of Animal pointers

	// Fill the array with Dog and Cat objects
	for (int i = 0; i < 5; i++)
	{
		animals[i] = new Dog();
		// Fill dog's brain with dog ideas
		for (int j = 0; j < 100; j++)
			animals[i]->getBrain()->setIdea("Thinking about dog food");
	}
	for (int i = 5; i < 10; i++)
	{
		animals[i] = new Cat();
		// Fill cat's brain with cat ideas
		for (int j = 0; j < 100; j++)
			animals[i]->getBrain()->setIdea("Thinking about sleeping");
	}

	// Print out the ideas in each animal's brain
	for (int i = 0; i < 10; i++)
	{
		std::cout << CYAN << "Animal " << i << "'s ideas:" << RESET << std::endl;
		for (int j = 0; j < 2; j++)
			std::cout << animals[i]->getBrain()->getIdea(j) << std::endl;
	}

	// Delete every Animal
	for (int i = 0; i < 10; i++)
		delete animals[i];

	delete[] animals;  // Delete the array

	return 0; */
}

