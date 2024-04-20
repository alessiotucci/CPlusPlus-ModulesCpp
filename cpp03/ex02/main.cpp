/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:52:50 by atucci            #+#    #+#             */
/*   Updated: 2024/04/20 15:58:36 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
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
	ClapTrap	bi("@#$234j1");
	ScavTrap	ci("!#$!$!");
	FragTrap	oi("otto");

	bi.takeDamage(ci.getAttackDamage());

	ci.attack(bi.getName());
	bi.takeDamage(ci.getAttackDamage());
	ci.guardGate();
	oi.highFivesGuys();


	std::cout << BLUE << "Creating ClapTrap, ScavTrap, and FragTrap objects..." << RESET << std::endl;
	ClapTrap b("Buzzer");
	ScavTrap c("Scavenger");
	FragTrap o("Fragger");

	std::cout << PURPLE << "Testing attack and takeDamage functions..." << RESET << std::endl;
	c.attack(b.getName());
	b.takeDamage(c.getAttackDamage());

	std::cout << CYAN << "Testing guardGate function for ScavTrap..." << RESET << std::endl;
	c.guardGate();

	std::cout << YELLOW << "Testing highFivesGuys function for FragTrap..." << RESET << std::endl;
	o.highFivesGuys();

	std::cout << GREEN << "Creating more ClapTrap, ScavTrap, and FragTrap objects..." << RESET << std::endl;
	ClapTrap b2("Bell");
	ScavTrap c2("Sweeper");
	FragTrap o2("Bomber");

	std::cout << RED << "Testing attack and takeDamage functions for new objects..." << RESET << std::endl;
	c2.attack(b2.getName());
	b2.takeDamage(c2.getAttackDamage());

	std::cout << CYAN << "Testing guardGate function for new ScavTrap..." << RESET << std::endl;
	c2.guardGate();

	std::cout << YELLOW << "Testing highFivesGuys function for new FragTrap..." << RESET << std::endl;
	o2.highFivesGuys();

	std::cout << RED << "Destroying all objects..." << RESET << std::endl;
	return (0);
}
