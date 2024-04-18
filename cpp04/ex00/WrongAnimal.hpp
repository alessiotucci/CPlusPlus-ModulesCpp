/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:48:13 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 16:19:41 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
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

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(std::string p);
		WrongAnimal(const WrongAnimal &obj);
		~WrongAnimal();//TODO: finished
		WrongAnimal & operator=(const WrongAnimal &obj);
		void makeSound() const;
		std::string getType() const;
	protected:
		std::string type;
};

#endif
