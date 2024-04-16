/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:00:07 by atucci            #+#    #+#             */
/*   Updated: 2024/04/16 21:32:03 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
/*	ClapTrap	b("@#$234j1");
	ScavTrap	c("!#$!$!");
	FragTrap	o("otto");

	b.takeDamage(c.getAttackDamage());

	c.attack(b.getName());
	b.takeDamage(c.getAttackDamage());
	c.guardGate();
	o.highFivesGuys();
	return (0); */
	ClapTrap	alberto("alberto"), mario("mario");

	alberto.attack(mario.getName());
	mario.takeDamage(alberto.getAttackDamage());
	mario.attack(alberto.getName());
	alberto.takeDamage(mario.getAttackDamage());

	ScavTrap	maurizio("maurizio");
	maurizio.guardGate();
	maurizio.attack(alberto.getName());
	alberto.takeDamage(maurizio.getAttackDamage());
	maurizio.attack(mario.getName());
	mario.takeDamage(maurizio.getAttackDamage());

	FragTrap	carlone("carlone");
	carlone.highFivesGuys();
	for (int i = 0; i < 4; i++)
	{
		carlone.attack(maurizio.getName());
		maurizio.takeDamage(carlone.getAttackDamage());
	}
	DiamondTrap	alfredo("Alfredo");
	alfredo.whoAmI();
	alfredo.attack(carlone.getName());
	carlone.takeDamage(alfredo.getAttackDamage());
	return (0);

}
