/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:03:10 by atucci            #+#    #+#             */
/*   Updated: 2024/04/12 22:41:20 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int x = 10;// change this value to test
	Zombie* zombies = zombieHorde(x, "Zombie");
	for (int i = 0; i < x; i++)
	{
		zombies[i].announce();
	}
	delete [] zombies;
}

