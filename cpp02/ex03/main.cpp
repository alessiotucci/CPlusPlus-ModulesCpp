/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:29:46 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 10:50:11 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>
bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	std::cout << std::boolalpha

	<< "a(0, 0), b(0, 5), c(5, 0), point(1, 1): "
	<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(1, 1)) << std::endl

	<< "a(0, 0), b(0, 5), c(5, 0), point(0, 5): "
	<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 5)) << std::endl

	<< "a(0, 0), b(0, 5), c(5, 0), point(0, 3): "
	<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 3)) << std::endl

	<< "a(0, 0), b(0, 5), c(5, 0), point(0, 0): "
	<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 0)) << std::endl

	<< "a(0, 0), b(0, 5), c(5, 0), point(0.1, 0.01): "
	<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0.1f, 0.01f)) << std::endl

	<< "a(0, 0), b(0, 5), c(5, 0), point(10, 0.01): "
	<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(10, 0.01f)) << std::endl

	<< "a(0, 0), b(0, 5), c(5, 0), point(0, -0.01): "
	<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, -0.01f)) << std::endl;
}
