/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:45:34 by atucci            #+#    #+#             */
/*   Updated: 2024/04/20 18:28:21 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"
#include <string>
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


class MateriaSource : public IMateriaSource
{
	private:
		AMateria* materias[4]; //MateriaSource can know at most 4 Materias.
		int index;
	public:
		MateriaSource ();
		MateriaSource (const MateriaSource &obj);
		~MateriaSource ();
		MateriaSource & operator = (const MateriaSource &obj);
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);

};
#endif
