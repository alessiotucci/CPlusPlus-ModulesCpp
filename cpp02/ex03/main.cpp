/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:29:46 by atucci            #+#    #+#             */
/*   Updated: 2024/04/20 11:43:49 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>
bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	std::cout << std::boolalpha;

	std::cout << GREEN << "Testing with points inside the triangle:" << RESET << std::endl;
	std::cout << "a(0, 0), b(0, 5), c(5, 0), point(2, 2): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(2, 2)) << std::endl;
	std::cout << "a(0, 0), b(0, 5), c(5, 0), point(1, 2): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(1, 2)) << std::endl;

	std::cout << YELLOW << "Testing with points on the edges of the triangle:" << RESET << std::endl;
	std::cout << "a(0, 0), b(0, 5), c(5, 0), point(0, 3): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 3)) << std::endl;
	std::cout << "a(0, 0), b(0, 5), c(5, 0), point(2.5, 0): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(2.5, 0)) << std::endl;

	std::cout << RED << "Testing with points outside the triangle:" << RESET << std::endl;
	std::cout << "a(0, 0), b(0, 5), c(5, 0), point(10, 10): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(10, 10)) << std::endl;
	std::cout << "a(0, 0), b(0, 5), c(5, 0), point(-1, -1): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(-1, -1)) << std::endl;
}

