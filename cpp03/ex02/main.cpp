/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:52:50 by atucci            #+#    #+#             */
/*   Updated: 2024/04/16 18:58:37 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap	b("@#$234j1");
	ScavTrap	c("!#$!$!");
	FragTrap	o("otto");

	b.takeDamage(c.getAttackDamage());

	c.attack(b.getName());
	b.takeDamage(c.getAttackDamage());
	c.guardGate();
	o.highFivesGuys();
	return (0);
}
