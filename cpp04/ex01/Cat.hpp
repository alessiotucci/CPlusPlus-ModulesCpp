/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:38:52 by atucci            #+#    #+#             */
/*   Updated: 2024/04/20 20:13:52 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
#define CAT_HPP
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
class Cat : public Animal
{
	public:
		Cat();
		Cat(std::string name);
		Cat(const Cat &obj);
		~Cat();//TODO: finished
		Cat & operator=(const Cat &obj);
		Brain* getBrain();
		void makeSound() const;
	private:
		Brain *brain;
};
#endif
