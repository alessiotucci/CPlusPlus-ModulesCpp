/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:00:02 by atucci            #+#    #+#             */
/*   Updated: 2024/04/16 21:13:07 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*****************************************/
/*   ORTHODOX CANONICAL CLASS FORM       */
/*    * class A                          */
/*    {                                  */
/*       public:                         */
/*          A ();                        */
/*          A (const A &a);              */
/*          ~A ();                       */
/*          A & operator = (const A &a); */
/*    };                                 */
/*                                       */
/*****************************************/

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &obj);
		~DiamondTrap();
		DiamondTrap& operator= (const DiamondTrap &obj);
		void attack(const std::string& target);
		void whoAmI();
	private:
		std::string _name;
};
#endif
