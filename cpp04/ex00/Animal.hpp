/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:38:55 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 15:35:12 by atucci           ###   ########.fr       */
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
		Animal(std::string p);
		Animal(const Animal &obj);
		~Animal();//TODO: finished
		Animal & operator=(const Animal &obj);
		virtual void makeSound() const;
		std::string getType() const;
	protected:
		std::string type;
};

#endif
