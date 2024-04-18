/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:05:50 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 17:35:02 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	Animal** animals = new Animal*[10];  // Create an array of Animal pointers

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
