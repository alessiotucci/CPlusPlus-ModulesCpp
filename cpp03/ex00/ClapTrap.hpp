/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:46:12 by atucci            #+#    #+#             */
/*   Updated: 2024/04/14 17:49:47 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

class ClapTrap
{
	public:
		//1) CONSTRUCTOR
		ClapTrap(std::string name);
		//2) DESTRUCTOR
		~ClapTrap();
		//3) COPY CONSTRUCTOR
		ClapTrap(const ClapTrap& other);
		//4) COPY ASSIGNMENT OPERATOR
		ClapTrap& operator=(const ClapTrap& other);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	private:
		std:string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
};
#endif
