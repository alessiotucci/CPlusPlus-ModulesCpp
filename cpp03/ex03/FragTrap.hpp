/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:59:58 by atucci            #+#    #+#             */
/*   Updated: 2024/04/16 21:29:22 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//TODO: Always triple check
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

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#include <string>
#include <iostream>
class FragTrap : virtual public ClapTrap // virtual
{
	public:
		FragTrap(std::string name);
		FragTrap();
		FragTrap(const FragTrap &obj);
		~FragTrap();
		FragTrap& operator= (const FragTrap &obj);
		void highFivesGuys();
		void attack(std::string const & target);

};
#endif
