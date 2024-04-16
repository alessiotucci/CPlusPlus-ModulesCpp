/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:38:55 by atucci            #+#    #+#             */
/*   Updated: 2024/04/16 21:47:08 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

/*****************************************/
/*   ORTHODOX CANONICAL CLASS FORM       */
/*      class A                          */
/*    {                                  */
/*       public:                         */
/*          A ();                        */
/*          A (const A &a);              */
/*          ~A ();                       */
/*          A & operator = (const A &a); */
/*    };                                 */
/*                                       */
/*****************************************/
#include <string>

class Animal
{
	public:
		Animal();
		Animal(const Animal &obj);
		~Animal();//TODO: finished
		Animal & operator=(const Animal &obj)
	protected:
		std::string type;
};

#endif
