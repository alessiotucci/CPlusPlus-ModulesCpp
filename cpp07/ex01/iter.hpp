/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: iter.hpp                                                ( o.o )    */
/*   Created: 2025/06/17 14:47:26 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/18 15:31:53                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */
#ifndef ITER_HPP
#define ITER_HPP

/*
 Implement a function template iter that takes 3 parameters and returns nothing
• The first parameter is the address of an array.
• The second one is the length of the array.
• The third one is a function that will be called on every element of the array
*/


//template <typename T, typename F>
template <typename T>
void iter(T *array, int length, void (*func)(T&) /*F func*/)
{
	if (!array || length <= 0 || !func)
		return;
	for (int i = 0; i < length; ++i)
		func(array[i]);
}

// Overload for arrays of const T
//template <typename T, typename F>
template <typename T>
void iter(const T *array, int length, void (*func)(const T&) /*F func*/)
{
	if (!array || length <= 0 || !func)
		return;
	for (int i = 0; i < length; ++i)
		func(array[i]);
}
#endif
