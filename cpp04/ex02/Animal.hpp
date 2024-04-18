/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:38:55 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 17:56:45 by atucci           ###   ########.fr       */
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

class AAnimal
{
	public:
		AAnimal();
		AAnimal(std::string p);
		AAnimal(const AAnimal &obj);
		virtual ~AAnimal();//TODO: finished
		AAnimal & operator=(const AAnimal &obj);
		virtual void makeSound() const = 0;  // Pure virtual function
		std::string getType() const;
	protected:
		std::string type;
};

#endif
