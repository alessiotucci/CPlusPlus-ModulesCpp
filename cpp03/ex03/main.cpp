/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:00:07 by atucci            #+#    #+#             */
/*   Updated: 2024/04/20 16:08:46 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>


#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

int main()
{
	std::cout << GREEN << "Starting the program...\n" << RESET;

	ClapTrap clapTrapOne("ClapMaster"), clapTrapTwo("ClapCommander");
	std::cout << CYAN << "Created ClapTrap instances: ClapMaster and ClapCommander\n" << RESET;

	clapTrapOne.attack(clapTrapTwo.getName());
	clapTrapTwo.takeDamage(clapTrapOne.getAttackDamage());
	clapTrapTwo.attack(clapTrapOne.getName());
	clapTrapOne.takeDamage(clapTrapTwo.getAttackDamage());

	ScavTrap scavTrapOne("Scavenger");
	std::cout << YELLOW << "Created ScavTrap instance: Scavenger\n" << RESET;

	scavTrapOne.guardGate();
	scavTrapOne.attack(clapTrapOne.getName());
	clapTrapOne.takeDamage(scavTrapOne.getAttackDamage());
	scavTrapOne.attack(clapTrapTwo.getName());
	clapTrapTwo.takeDamage(scavTrapOne.getAttackDamage());

	FragTrap fragTrapOne("Fragger");
	std::cout << RED << "Created FragTrap instance: Fragger\n" << RESET;

	fragTrapOne.highFivesGuys();
	for (int i = 0; i < 4; i++)
	{
		fragTrapOne.attack(scavTrapOne.getName());
		scavTrapOne.takeDamage(fragTrapOne.getAttackDamage());
	}

	DiamondTrap diamondTrapOne("DiamondKing");
	std::cout << CYAN << "Created DiamondTrap instance: DiamondKing 💎\n" << RESET;

	diamondTrapOne.whoAmI();
	diamondTrapOne.attack(fragTrapOne.getName());
	fragTrapOne.takeDamage(diamondTrapOne.getAttackDamage());

	std::cout << GREEN << "End of the program.\n" << RESET;
	return 0;
}

