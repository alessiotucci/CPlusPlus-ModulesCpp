/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:48:09 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 16:23:15 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
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
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string name);
		WrongCat(const WrongCat &obj);
		~WrongCat();//TODO: finished
		WrongCat & operator=(const WrongCat &obj);
		void makeSound() const;
};
#endif
