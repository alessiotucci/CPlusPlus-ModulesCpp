/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:49:09 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 16:54:38 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain &obj);
		~Brain();
		Brain& operator=(const Brain &obj);
	private:
		std::string ideas[100];
};

#endif
