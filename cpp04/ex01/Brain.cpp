/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:49:17 by atucci            #+#    #+#             */
/*   Updated: 2024/04/20 20:23:13 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() : currentIdeaIndex(0)
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

void Brain::setIdea(std::string idea)
{
	if (currentIdeaIndex >= 100)
	{
		std::cout << "There is no room in the brain for more ideas." << std::endl;
	}
	else
	{
		ideas[currentIdeaIndex++] = idea;
	}
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= currentIdeaIndex)
	{
		std::cout << "Invalid idea index." << std::endl;
		return "";
	}
	return ideas[index];
}

