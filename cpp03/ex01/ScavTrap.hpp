/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:48:23 by atucci            #+#    #+#             */
/*   Updated: 2024/04/20 15:48:47 by atucci           ###   ########.fr       */
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

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
#include <string>
#include <iostream>
class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(); // add empty constructor
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &obj);
		~ScavTrap();
		ScavTrap& operator= (const ScavTrap &obj);
		void guardGate();
		void attack(std::string const & target);// override; // Override the method

};
#endif
