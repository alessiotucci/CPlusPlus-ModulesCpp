/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:27:23 by atucci            #+#    #+#             */
/*   Updated: 2024/04/15 15:56:13 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
const int Fixed::_bits = 8;
Fixed::Fixed()
{
	std::cout << GREEN << "Default Constructor called" << RESET << std::endl;
	this->_value = 0;
}

// new ctor
Fixed::Fixed(const int number)
{
	this->_value = (number << this->_bits);
	std::cout << "Int Constructor called" << std::endl;
}

// new ctor with float
Fixed::Fixed(const float number)
{
	this->_value = roundf(number * (1 << this->_bits));
	std::cout << "Float Constructor called" << std::endl;
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

// overload of the insertion operator
std::ostream& operator<<(std::ostream& output, const Fixed param)
{
	output << param.toFloat();
	return output;
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

float Fixed::toFloat( void ) const
{
	return ((float)this->_value / (1 << this->_bits));
}

int Fixed::toInt( void ) const
{
	return (this->_value >> this->_bits);
}

