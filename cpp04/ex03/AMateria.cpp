/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:32:15 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 18:37:16 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>
#include <string>

AMateria() { }

~AMateria() { }

AMateria(const AMateria &obj)
{
	*this = obj;
}

AMateria& operator=(const AMateria &obj)
{
	if (this = &obj)
	{
		// assign
	}
	return obj;
}

AMateria(std::string const & type)
{

}

std::string const & getType() const
{

}
