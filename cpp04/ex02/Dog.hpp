/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:40:43 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 17:58:13 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
#define DOG_HPP
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
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(std::string name);
		Dog(const Dog &obj);
		~Dog();//TODO: finished
		Dog & operator=(const Dog &obj);
		void makeSound() const;
	private:
		Brain *brain;
};
#endif
