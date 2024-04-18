/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:29:39 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 10:48:58 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


Point::Point() { }

Point::Point(float x, float y) : x(Fixed(x)), y(Fixed(y)) {}

/*Point::Point(const float x, const float y)
{
	x = SetX(Fixed(x));
	y = SetY(Fixed(y));
}*/

Point::~Point() { }

Point::Point(const Point& other) : x(other.x), y(other.y) {}
/*Point::Point(const Point& other)
{
	*this = other;
}*/


Point& Point::operator=(const Point &obj)
{
	(void)obj;
	return *this;
}

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}
