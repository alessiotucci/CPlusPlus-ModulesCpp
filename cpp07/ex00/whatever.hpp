#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream> // for testing purposes in main.cpp

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T const &min(T const &a, T const &b)
{
	return (a < b ? a : b);
}
/*
 * if (a < b)
 * 	return (a);
 * else
 * 	return (b)
 */

template <typename T>
T const &max(T const &a, T const &b)
{
	return (a > b ? a : b);
}

#endif

