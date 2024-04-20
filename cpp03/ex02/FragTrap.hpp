/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:52:43 by atucci            #+#    #+#             */
/*   Updated: 2024/04/20 16:00:52 by atucci           ###   ########.fr       */
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

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#include <string>
#include <iostream>
class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &obj);
		~FragTrap();
		FragTrap& operator= (const FragTrap &obj);
		void highFivesGuys();
		void attack(std::string const & target);

};
#endif
