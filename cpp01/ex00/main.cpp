/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:01:22 by atucci            #+#    #+#             */
/*   Updated: 2024/04/12 22:17:50 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* heapZombie = newZombie("HeapZombie"); // Creating a Zombie on the heap
	heapZombie->announce();// HeapZombie announces itself
	randomChump("StackZombie"); // Creating and announcing a Zombie on the stack
	delete heapZombie; //Manually delete the heapZombie to free the memory
	return 0;
}


