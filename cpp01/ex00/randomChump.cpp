/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:02:13 by atucci            #+#    #+#             */
/*   Updated: 2024/04/12 22:04:57 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Function to create a Zombie on the stack and make it announce itself
void randomChump(std::string name)
{
	Zombie z(name);
	// Create a Zombie object on the stack
	z.announce();
	// The Zombie announces itself
	// The Zombie object 'z' is automatically destroyed when this function scope ends
}

