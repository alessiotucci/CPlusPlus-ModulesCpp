/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:25:59 by atucci            #+#    #+#             */
/*   Updated: 2024/04/20 11:29:59 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* main from the subject */
#include "Fixed.hpp"
#include <iostream>
int main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << "\n*** more test ***\n";
	
	Fixed *d = new Fixed();
	std::cout << d->getRawBits() << std::endl;
	delete d;
return 0;
}
