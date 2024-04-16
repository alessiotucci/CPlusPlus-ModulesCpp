/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:46:07 by atucci            #+#    #+#             */
/*   Updated: 2024/04/16 16:15:15 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include "ClapTrap.hpp"

// main.cpp
#include "ClapTrap.hpp"

// main.cpp
#include "ClapTrap.hpp"

int main()
{
	ClapTrap Hyperion("Hyperion");
	ClapTrap Overenthusiast("Overenthusiast");
	ClapTrap ComicRelief("ComicRelief");

	while (Hyperion.getEnergyPoints() > 0 && Hyperion.getHitPoints() > 0 &&
		   Overenthusiast.getEnergyPoints() > 0 && Overenthusiast.getHitPoints() > 0)
	{
		Hyperion.attack(Overenthusiast.getName());
		Overenthusiast.takeDamage(Hyperion.getAttackDamage());
	}

	while (Overenthusiast.getEnergyPoints() > 0 && Overenthusiast.getHitPoints() > 0 &&
		   ComicRelief.getEnergyPoints() > 0 && ComicRelief.getHitPoints() > 0)
	{
		Overenthusiast.attack(ComicRelief.getName());
		ComicRelief.takeDamage(Overenthusiast.getAttackDamage());
	}

	while (ComicRelief.getEnergyPoints() > 0 && ComicRelief.getHitPoints() > 0 &&
		   Hyperion.getEnergyPoints() > 0 && Hyperion.getHitPoints() > 0)
	{
		ComicRelief.attack(Hyperion.getName());
		Hyperion.takeDamage(ComicRelief.getAttackDamage());
	}
	return 0;
}

