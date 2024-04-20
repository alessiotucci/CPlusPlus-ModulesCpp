/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:05:02 by atucci            #+#    #+#             */
/*   Updated: 2024/04/20 20:00:18 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

int main()
{
    std::cout << GREEN << "Creating Animals..." << RESET << std::endl;
    Animal my_animal;
    Dog my_dog("Rex");
    Cat my_cat("Lucy");

    std::cout << CYAN << "Testing Cat: " << my_cat.getType() << " 🐱" << RESET << std::endl;
    my_cat.makeSound();
    std::cout << std::endl;

    std::cout << CYAN << "Testing Dog: " << my_dog.getType() << " 🐶" << RESET << std::endl;
    my_dog.makeSound();
    std::cout << std::endl;

    std::cout << YELLOW << "SUBJECT TEST" << RESET << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout << std::endl;

    std::cout << RED << "WRONG ANIMAL TEST" << RESET << std::endl;
    const WrongAnimal* meta_wrong = new WrongAnimal();
    const WrongAnimal* wrong = new WrongCat();
    meta_wrong->makeSound();
    wrong->makeSound(); // Calls WrongCat's makeSound
    std::cout << std::endl;

    delete meta;
    delete j;
    delete i;
    delete meta_wrong;
    delete wrong;

    return 0;
}

