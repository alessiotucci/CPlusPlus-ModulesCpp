/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:25:54 by atucci            #+#    #+#             */
/*   Updated: 2024/04/14 21:15:57 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*static const int i = 3; // Integral types can be initialized here (*)...*/
/*https://stackoverflow.com/questions/2605520/where-should-a-static-const-data-member-be-defined*/

const int Fixed::_bits = 8;
Fixed::Fixed()
{
	std::cout << GREEN << "Default Constructor called" << RESET << std::endl;
	this->_value = 0;
}

Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	_value = other._value;
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

Fixed& Fixed::operator=(const Fixed &obj)
{
	// self-assignment guard
	std::cout << BG_YELLOW << "Copy assignment operator called" << BG_RESET << std::endl;
	if (this == &obj)
		return *this;
	_value = obj.getRawBits(); // can handle self-assignment

	// return the existing object so we can chain this operator
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits( int const raw )
{
	_value = raw;
}


