/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:01:48 by atucci            #+#    #+#             */
/*   Updated: 2024/04/12 22:04:31 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
// Function to create a new Zombie on the heap
Zombie* newZombie(std::string name)
{
	Zombie* newZ = new Zombie(name);
	// Dynamically allocate a new Zombie object on the heap
	return newZ;
	// Return the pointer to the new Zombie
}


