/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:48:29 by atucci            #+#    #+#             */
/*   Updated: 2024/04/16 18:22:58 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap	b("@#$234j1");
	ScavTrap	c("!#$!$!");

	b.takeDamage(c.getAttackDamage());

	c.attack(b.getName());
	b.takeDamage(c.getAttackDamage());
	c.guardGate();
	return (0);
}
