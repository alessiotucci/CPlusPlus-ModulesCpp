/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:28:14 by atucci            #+#    #+#             */
/*   Updated: 2024/04/16 14:27:57 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
const int Fixed::_bits = 8;
Fixed::Fixed()
{
	//std::cout << GREEN << "Default Constructor called" << RESET << std::endl;
	this->_value = 0;
}

// new ctor
Fixed::Fixed(const int number)
{
	this->_value = (number << this->_bits);
	//std::cout << "Int Constructor called" << std::endl;
}

// new ctor with float
Fixed::Fixed(const float number)
{
	this->_value = roundf(number * (1 << this->_bits));
	//std::cout << "Float Constructor called" << std::endl;
}

Fixed::~Fixed()
{
	//std::cout << RED << "Destructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	_value = other._value;
	//std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
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

bool	Fixed::operator>(const Fixed &obj) const
{
	return (this->_value > obj._value);
}

bool	Fixed::operator<(const Fixed &obj) const
{
	return (this->_value < obj._value);
}

bool	Fixed::operator>=(const Fixed &obj) const
{
	return (this->_value >= obj._value);
}

bool	Fixed::operator<=(const Fixed &obj) const
{
	return (this->_value <= obj._value);
}

bool	Fixed::operator==(const Fixed &obj) const
{
	return (this->_value == obj._value);
}

bool	Fixed::operator!=(const Fixed &obj) const
{
	return (this->_value != obj._value);
}

//The 4 arithmetic operators: +, -, *, and /.
Fixed	Fixed::operator+(const Fixed &obj)
{
	Fixed result;
	result._value = this->_value + obj._value;
	return (result);
}

Fixed	Fixed::operator-(const Fixed &obj)
{
	Fixed result;
	result._value = this->_value - obj._value;
	return (result);
}

Fixed	Fixed::operator*(const Fixed &obj)
{
	Fixed result;
	result._value = ((this->_value * obj._value) / (1 << _bits));
	return (result);
}

Fixed	Fixed::operator/(const Fixed &obj)
{
	Fixed result;
	if (obj._value != 0)
		result._value = (this->_value * (1 << _bits)) / obj._value;
	else
		std::cout << RED << "Error: Division by zero!" << RESET << std::endl;
	return (result);
}

// Pre-increment ++a
Fixed Fixed::operator++()
{
	this->_value++; // += 1 << _bits;
	return *this;
}

// Pre-decrement --a
Fixed Fixed::operator--()
{
	this->_value--;// -= 1 << _bits;
	return *this;
}

// Post-increment
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_value++;// += 1 << _bits;
	return temp;
}

// Post-decrement
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_value--;// -= 1 << _bits;
	return temp;
}

// Min (non-const)
Fixed& Fixed::min(Fixed &first, Fixed &second)
{
	return (first < second) ? first : second;
}

// Min (const)
const Fixed& Fixed::min(const Fixed &first, const Fixed &second)
{
	return (first < second) ? first : second;
}

// Max (non-const)
Fixed& Fixed::max(Fixed &first, Fixed &second)
{
	return (first > second) ? first : second;
}

// Max (const)
const Fixed& Fixed::max(const Fixed &first, const Fixed &second)
{
	return (first > second) ? first : second;
}

