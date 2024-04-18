/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:05:02 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 16:36:16 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int	main()
{
	Animal my_animal;
	my_animal.makeSound();
	Dog my_dog("Rex");
	Cat my_cat("Lucy");
	std::cout << my_cat.getType() << std::endl;
	my_cat.makeSound();

	std::cout << my_dog.getType() << std::endl;
	my_dog.makeSound();
	
	std::cout << "SUBJECT TEST\n\n";
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "\n\nWRONG ANIMAL TEST\n\n";
	const WrongAnimal* meta_wrong = new WrongAnimal();
	const WrongAnimal* wrong = new WrongCat();
	meta_wrong->makeSound();
	wrong->makeSound(); // Calls WrongCat's makeSound
}
