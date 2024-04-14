/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:26:15 by atucci            #+#    #+#             */
/*   Updated: 2024/04/14 19:56:37 by atucci           ###   ########.fr       */
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
		Fixed();							//1) Constructor
		~Fixed();							//2) Destructor
		Fixed(const Fixed& other);			//3) Copy Constructor
		Fixed& operator=(const Fixed &obj);  //4) assignment operator overload
		// function from the subject
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int _value;
		static const int _bits;
};
#endif
//https://en.cppreference.com/w/cpp/language/copy_constructor
//https://www.youtube.com/watch?v=Ldv5i14UhTA
//https://www.youtube.com/watch?v=9tHu4mWtrnM
