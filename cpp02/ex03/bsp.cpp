/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:29:42 by atucci            #+#    #+#             */
/*   Updated: 2024/04/18 10:02:19 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <cmath>
static float triangleArea(Point const a, Point const b, Point const c)
{
return abs((a.getX().toFloat()*(b.getY().toFloat() - c.getY().toFloat()) + b.getX().toFloat()*(c.getY().toFloat() - a.getY().toFloat()) + c.getX().toFloat()*(a.getY().toFloat() - b.getY().toFloat())) / 2.0);
}


/*To conclude, implement the following function in the appropriate file:
bool bsp( Point const a, Point const b, Point const c, Point const point);
	• a, b, c: The vertices of our beloved triangle.
	• point: The point to check.
	• Returns: True if the point is inside the triangle. False otherwise.

Thus, if the point is a vertex or on edge, it will return False.*/
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float total = triangleArea(a, b, c);
	float a1 = triangleArea(point, b, c);
	float a2 = triangleArea(a, point, c);
	float a3 = triangleArea(a, b, point);
	return (total == a1 + a2 + a3 && a1 > 0 && a2 > 0 && a3 > 0);

}

