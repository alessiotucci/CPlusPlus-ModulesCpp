/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:52:28 by atucci            #+#    #+#             */
/*   Updated: 2024/04/16 18:50:17 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*TODO: Always double check cmon */
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

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
#include <string>
#include <iostream>
class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &obj);
		~ScavTrap();
		ScavTrap& operator= (const ScavTrap &obj);
		void guardGate();
		void attack(std::string const & target);// override; // Override the method

};
#endif
