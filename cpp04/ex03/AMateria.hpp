/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:55:13 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 18:31:16 by atucci           ###   ########.fr       */
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

#ifndef AMATERIA_HPP
#define AMATERIA_HPP
class AMateria
{
	protected:
	
	public:
		AMateria();
		~AMateria();
		AMateria(const AMateria &obj);
		AMateria& operator=(const AMateria &obj);
		AMateria(std::string const & type);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
#endif
