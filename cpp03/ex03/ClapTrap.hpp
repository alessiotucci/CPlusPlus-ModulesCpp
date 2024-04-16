/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:00:04 by atucci            #+#    #+#             */
/*   Updated: 2024/04/16 19:43:05 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include "ClapTrap.hpp"
#include <iostream>

//TODO: Always double check
//TODO: check if some fix has been made
class ClapTrap
{
	public:
		//1) CONSTRUCTOR
		ClapTrap(std::string name);
		ClapTrap();
		//2) DESTRUCTOR
		~ClapTrap();
		//3) COPY CONSTRUCTOR
		ClapTrap(const ClapTrap& other);
		//4) COPY ASSIGNMENT OPERATOR
		ClapTrap& operator=(const ClapTrap& other);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		// FUCKING getters
		std::string getName() const;
		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;
	protected:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
};
#endif
