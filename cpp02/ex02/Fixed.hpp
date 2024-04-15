/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:28:08 by atucci            #+#    #+#             */
/*   Updated: 2024/04/15 21:11:31 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <string>
# define BLUE    "\033[1;34m"
# define PURPLE  "\033[1;35m"
# define GRAY    "\033[1;30m"
# define GREEN   "\033[1;32m"
# define CYAN    "\033[1;36m"
# define YELLOW  "\033[1;33m"
# define RED     "\033[1;31m"
# define RESET   "\033[0m"
# define BG_RESET        "\033[49m"
# define BG_GREEN        "\033[42m"
# define BG_CYAN         "\033[46m"
# define BG_YELLOW       "\033[43m"
# define BG_RED          "\033[41m"

class Fixed
{
	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float number);
		~Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed &obj);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		/*TODO: new stuff */
		//The 6 comparison operators: >, <, >=, <=, == and !=.
		bool	operator>(const Fixed &obj) const;
		bool	operator<(const Fixed &obj) const;
		bool	operator>=(const Fixed &obj) const;
		bool	operator<=(const Fixed &obj) const;
		bool	operator==(const Fixed &obj) const;
		bool	operator!=(const Fixed &obj) const;

		//The 4 arithmetic operators: +, -, *, and /.
		Fixed	operator+(const Fixed &obj);
		Fixed	operator-(const Fixed &obj);
		Fixed	operator*(const Fixed &obj);
		Fixed	operator/(const Fixed &obj);

		/*The 4 increment/decrement that will increase or decrease
		 * the fixed-point value from the smallest representable */
		// pre increment
		Fixed	operator++();
		// pre decrement
		Fixed	operator--();
		// post increment
		Fixed	operator++(int);
		// post decrement
		Fixed	operator--(int);

		/*A static member function min that takes as parameters two references
		 * on fixed-point numbers, and returns a reference to the smallest one.*/
		static Fixed&	min(Fixed &first, Fixed &second);

		/*A static member function min that takes as parameters two references to constant
		fixed-point numbers, and returns a reference to the smallest one.*/
		static const Fixed&	min(const Fixed &first, const Fixed &second);

		/*A static member function max that takes as parameters two references on fixed-point
		numbers, and returns a reference to the greatest one.*/
		static Fixed&	max(Fixed &first, Fixed &second);

		/*A static member function max that takes as parameters two references to constant
		fixed-point numbers, and returns a reference to the greatest one.*/
		static const Fixed&	max(const Fixed &first, const Fixed &second);
	private:
		int _value;
		static const int _bits;
};

std::ostream& operator<<(std::ostream& output, const Fixed param);
#endif
