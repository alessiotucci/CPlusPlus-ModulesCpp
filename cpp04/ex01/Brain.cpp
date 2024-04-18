/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:49:17 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 16:51:59 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain 🧠 constructor\n";
	// Initialize the ideas array here if necessary
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Brain 🧠 copy constructor\n";
	*this = obj;  // This will call the copy assignment operator
}

Brain::~Brain()
{
	std::cout << "Brain 🧠 destructor\n";
}

Brain& Brain::operator=(const Brain &obj)
{
	std::cout << "Brain 🧠 copy assignment operator\n";
	if (this != &obj)  // Protect against self-assignment
	{
		// Deep copy the ideas array
		for (int i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	}
	return *this;
}

