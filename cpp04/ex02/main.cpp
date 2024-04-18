/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:05:50 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 17:57:52 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
/*	std::cout << "SUBJECT TEST \n\n";
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;*/

	AAnimal** animals = new AAnimal*[10];  // Create an array of Animal pointers

	// Fill the array with Dog and Cat objects
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();

	std::cout << "segfault check\n";
	// Delete every Animal
	for (int i = 0; i < 10; i++)
	{
		std::cout << i;
		delete animals[i];
	}

	delete[] animals;  // Delete the array

	return 0;
}
