/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:48:29 by atucci            #+#    #+#             */
/*   Updated: 2024/04/20 15:52:35 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#define BLUE    "\033[1;34m"
#define PURPLE  "\033[1;35m"
#define GRAY    "\033[1;30m"
#define GREEN   "\033[1;32m"
#define CYAN    "\033[1;36m"
#define YELLOW  "\033[1;33m"
#define RED     "\033[1;31m"
#define RESET   "\033[0m"
#define BG_RESET        "\033[49m"
#define BG_GREEN        "\033[42m"
#define BG_CYAN         "\033[46m"
#define BG_YELLOW       "\033[43m"
#define BG_RED          "\033[41m"

int main()
{
	ClapTrap	b("@#$234j1");
	ScavTrap	c("!#$!$!");

	b.takeDamage(c.getAttackDamage());

	c.attack(b.getName());
	b.takeDamage(c.getAttackDamage());
	c.guardGate();


	 std::cout << BLUE << "Creating ScavTrap and ClapTrap objects..." << RESET << std::endl;
	ScavTrap scavenger("Scavenger");
	ClapTrap clapper("Clapper");

	std::cout << PURPLE << "Testing attack functions..." << RESET << std::endl;
	scavenger.attack("Enemy1");
	clapper.attack("Enemy2");

	std::cout << CYAN << "Testing guardGate function for ScavTrap..." << RESET << std::endl;
	scavenger.guardGate();

	std::cout << YELLOW << "Creating more ScavTrap and ClapTrap objects..." << RESET << std::endl;
	ScavTrap gateKeeper("GateKeeper");
	ClapTrap noiseMaker("NoiseMaker");

	std::cout << GREEN << "Testing attack functions for new objects..." << RESET << std::endl;
	gateKeeper.attack("Enemy3");
	noiseMaker.attack("Enemy4");

	std::cout << RED << "Testing takeDamage and beRepaired functions..." << RESET << std::endl;
	scavenger.takeDamage(10);
	scavenger.beRepaired(10);
	clapper.takeDamage(20);
	clapper.beRepaired(20);

	std::cout << RED << "Destroying all objects..." << RESET << std::endl;
	return (0);
}
