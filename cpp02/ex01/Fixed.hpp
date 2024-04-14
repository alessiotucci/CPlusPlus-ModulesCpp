/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:27:16 by atucci            #+#    #+#             */
/*   Updated: 2024/04/14 22:06:25 by atucci           ###   ########.fr       */
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
		Fixed(const int number);	//constructor that takes a const int as a parameter.
		Fixed(const float number);  //constructor that takes a const float as a parameter.
		~Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed &obj);
		// function from the subject
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;//converts the fixed-point value to a floating-point value.
		int toInt( void ) const; //converts the fixed-point value to an integer value.
	private:
		int _value;
		static const int _bits;
};

std::ostream& operator<<(std::ostream& output, const Fixed param);
#endif
