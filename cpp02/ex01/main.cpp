/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:27:20 by atucci            #+#    #+#             */
/*   Updated: 2024/04/20 11:37:50 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
int main( void )
{
	Fixed	a;
	Fixed	const b( 10 );
	Fixed	const c( 42.42f );
	Fixed	const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << RED << "\n\nsome more TEST\n\n" << RESET;
	//construct an instance from a floating point number
		Fixed test(1.341f);
	//construct an instance from a integer point number
		Fixed test2(98);
	//<< operator and is it functionan
	std::cout << "1) << operator and is it functional" << test << std::endl;
	std::cout << "2) << operator and is it functional" << test2 << std::endl;
	/*The class must include a member function "int toInt(void) const;"
	 which converts a fixed-point number to an int.
	 Is it present and functional? */
	std::cout << "conversion being performed\n" << std::endl;
	std::cout << "1) func to int " << test.toInt() << std::endl;
	std::cout << "2) func to float" << test2.toFloat() << std::endl;
return 0;
}

