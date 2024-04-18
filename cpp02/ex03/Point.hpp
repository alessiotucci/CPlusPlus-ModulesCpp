/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:29:56 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 10:49:08 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
 *Let’s start by creating the class Point in Orthodox Canonical Form that represents
a 2D point:
• Private members:
	◦ A Fixed const attribute x.
	◦ A Fixed const attribute y.
	◦ Anything else useful.
• Public members:
	◦ A default constructor that initializes x and y to 0.
	◦ A constructor that takes as parameters two constant floating-point numbers.
It initializes x and y with those parameters.
	◦ A copy constructor.
	◦ A copy assignment operator overload.
	◦ A destructor.
	◦ Anything else useful.
 * */
class Point
{
	public:
		Point();
		Point(const float x, const float y);
		~Point();
		Point(const Point& other);
		Point& operator=(const Point &obj);
		Fixed getX() const;
		Fixed getY() const;
	private:
		const Fixed x;
		const Fixed y;
};
