/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:45:34 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 22:01:22 by atucci           ###   ########.fr       */
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
public:
	MateriaSource ();
	MateriaSource (const MateriaSource &obj);
	~MateriaSource ();
	MateriaSource & operator = (const MateriaSource &obj);
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

};
#endif
